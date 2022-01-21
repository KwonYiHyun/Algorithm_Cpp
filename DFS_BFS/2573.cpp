#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int n,m;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int** arr;
bool** ch;
bool** check;
queue<pair<int,int>> q;

void bfs(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ch[i][j]=false;
        }
        
    }

    while (!q.empty())
    {
        int zx=q.front().first;
        int zy=q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx=zx+dx[i];
            int ny=zy+dy[i];

            if(nx>=1 && nx<=n && ny>=1 && ny<=m){
                int cnt=0;
                if(arr[nx][ny]==0 && !ch[nx][ny]){
                    cnt++;
                }
                arr[zx][zy]-=cnt;
                if(arr[zx][zy]<0) arr[zx][zy]=0;
                if(arr[zx][zy]==0) ch[zx][zy]=true;
            }
        }
        
    }
    
}

void dfs(int x, int y){
    check[x][y]=true;
    for (int i = 0; i < 4; i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=1 && nx<=n && ny>=1 && ny<=m){
            if(arr[nx][ny]!=0 && !check[nx][ny]){
                dfs(nx,ny);
            }
        }
    }
    
}

int sum(){
    int cnt=0;
    check=new bool*[n+1];
    for (int i = 1; i <= n; i++)
    {
        check[i]=new bool[m+1];
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            check[i][j]=false;
        }
        
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(arr[i][j]!=0 && !check[i][j]){
                cnt++;
                dfs(i,j);
            }
        }
        
    }
    
    return cnt;
}

int main(){
    cin>>n>>m;
    arr=new int*[n+1];
    ch=new bool*[n+1];

    for (int i = 1; i <= n; i++)
    {
        arr[i]=new int[m+1];
        ch[i]=new bool[m+1];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int w;
            cin>>w;
            arr[i][j]=w;
            if(w!=0) q.push(make_pair(i,j));
        }
        
    }
    int i=0;
    while (true)
    {
        i++;
        bfs();
        int max=0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if(arr[i][j]!=0) q.push(make_pair(i,j));
                if(arr[i][j]>max) max=arr[i][j];
            }
        
        }

        if(sum()>=2) break;
        if(max==0){
            i=0;
            break;
        }
    }
    cout<<i<<endl;
}