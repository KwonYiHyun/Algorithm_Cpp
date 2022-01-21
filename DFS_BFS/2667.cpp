#include <iostream>
#include <string>
#include <list>

using namespace std;

bool** ch;
int** line;
int** arr;
int cnt=0;
int cnum=0;
int n;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
list<int> lt;

void dfs(int x, int y){
    ch[x][y]=true;

    for (int i = 0; i < sizeof(dx)/4; i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=1 && nx<=n && ny>=1 && ny<=n){
            if(arr[nx][ny]==1 && !ch[nx][ny]){
                cnum++;
                dfs(nx,ny);
            }
        }
    }
}

int main(){
    cin>>n;
    arr=new int*[n+1];
    line=new int*[n+1];
    ch=new bool*[n+1];
    for (int i = 1; i <= n; i++)
    {
        arr[i]=new int[n+1];
        ch[i]=new bool[n+1];
        line[i]=new int[n+1];
    }
    
    for (int i = 1; i <= n; i++)
    {
        string m;
        cin>>m;
        for (int j = 0; j < n; j++)
        {
            arr[i][j+1]=stoi(m.substr(j,1));
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(arr[i][j]==1 && !ch[i][j]){
                cnt++;
                cnum=1;
                dfs(i,j);
                lt.push_back(cnum);
            }
        }
    }

    cout<<cnt<<endl;
    lt.sort();
    list<int>::iterator iter;
    for (iter=lt.begin(); iter!=lt.end(); iter++)
    {
        cout<<*iter<<endl;
    }
    
}