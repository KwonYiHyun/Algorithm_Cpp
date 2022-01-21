#include <iostream>
#include <utility>
#include <string>
#include <cstring> 
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
int** line;
// bool** ch;
// bool** check;
bool ch[1501][1501];
bool check[1501][1501];
string* input;
queue<pair<int, int>> q;
queue<pair<int, int>> w;
int maxx=0;
bool isable;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void wwbfs(){
    isable=false;
    fill(&check[1][1], &check[n+2][m+2], false);

    while (!q.empty())
    {
        int zx=q.front().first;
        int zy=q.front().second;

        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx=zx+dx[i];
            int ny=zy+dy[i];
            if(nx>=1 && ny>=1 && nx<=n && ny<=m){
                if(line[nx][ny]==0 && !check[nx][ny]){
                    check[zx][zy]=true;
                    q.push(make_pair(nx,ny));
                    line[nx][ny]=line[zx][zy]+1;
                    if(maxx<line[nx][ny]) maxx=line[nx][ny];
                }
            }
        }
        
    }
    
}

void wbfs(){
    isable=false;
    fill(&check[1][1], &check[n+2][m+2], false);

    int x=w.front().first;
    int y=w.front().second;
    check[x][y]=true;
    q.push(make_pair(x,y));

    while (!q.empty())
    {
        int zx=q.front().first;
        int zy=q.front().second;

        if(zx==w.back().first && zy==w.back().second) isable=true;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx=zx+dx[i];
            int ny=zy+dy[i];
            if(nx>=1 && ny>=1 && nx<=n && ny<=m){
                if((line[nx][ny]==1 || line[nx][ny]==2) && !check[nx][ny]){
                    check[nx][ny]=true;
                    q.push(make_pair(nx,ny));
                }
            }
        }
        
    }
    
}

void bfs(){
    fill(&ch[0][0], &ch[n+2][m+2], false);

    while (!q.empty())
    {
        int zx=q.front().first;
        int zy=q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx=zx+dx[i];
            int ny=zy+dy[i];

            if(nx>=1 && ny>=1 && nx<=n && ny<=m){
                if(line[nx][ny]==1 && !ch[nx][ny]){
                    line[zx][zy]=1;
                    ch[zx][zy]=true;
                }
            }
        }
        
    }
    
}

int main(){
    cin>>n>>m;
    line=new int*[n+1];
    input=new string[n+1];

    for (int i = 1; i <= n; i++)
    {
        cin>>input[i];
    }

    for (int i = 1; i <= n; i++)
    {
        line[i]=new int[m+1];
    }
    

    for (int i = 1; i <= n; i++)
    {
        string sl=input[i];
        for (int j = 1; j <= m; j++)
        {
            if(sl.substr(j-1,1).compare(".")==0){
                line[i][j]=1;
                q.push(make_pair(i,j));
            }else if(sl.substr(j-1,1).compare("L")==0){
                line[i][j]=2;
                w.push(make_pair(i,j));
            }else if(sl.substr(j-1,1).compare("X")==0){
                line[i][j]=0;
            }
        }
        
    }

    wwbfs();
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout<<line[i][j]<<"\t";
        }
        cout<<"\n";
    }

    cout<<maxx-1<<endl;
    // cout<<line[w.back().first][w.back().second];
}