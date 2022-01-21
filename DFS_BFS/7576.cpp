#include <iostream>
#include <string>
#include <list>
#include <queue>
#include <utility>

using namespace std;

int n,m;
int** arr;
bool** ch;

int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};

queue<pair<int, int>> q;

void bfs(){
    while (!q.empty())
    {
        int zx=q.front().first;
        int zy=q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx=zx+dx[i];
            int ny=zy+dy[i];

            if(nx>=1 && nx<=m && ny>=1 && ny<=n){
                if(arr[nx][ny]==0 && !ch[nx][ny]){
                    ch[nx][ny]=true;
                    q.push(make_pair(nx,ny));
                    arr[nx][ny]=arr[zx][zy]+1;
                }
            }
        }
        
    }
    
}

int main(){
    cin>>n>>m;
    arr=new int*[m+1];
    ch=new bool*[m+1];

    for (int i = 1; i <= m; i++)
    {
        arr[i]=new int[n+1];
        ch[i]=new bool[n+1];
    }
    

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>arr[i][j];
        }
        
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(arr[i][j]==1){
                q.push(make_pair(i,j));
            }
        }
    }
    
    bfs();
    bool iszero=true;
    int max=0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(arr[i][j]==0) iszero=false;
            if(arr[i][j]>max) max=arr[i][j];
        }
    }

    if(iszero){
        cout<<max-1<<endl;
    }else{
        cout<<"-1"<<endl;
    }
}