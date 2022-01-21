#include <iostream>
#include <utility>
#include <string>
#include <cstring> 
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
int** line;
bool** ch;
bool** check;
string* input;
queue<pair<int, int>> q;
queue<pair<int, int>> w;

bool isable;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void wbfs(){
    isable=false;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         check[i][j]=false;
    //     }   
    // }
    fill(check[1][1], check[n+2][m+2], false);

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

// void dfs(){
//     int x=w.front().first;
//     int y=w.front().second;

//     int rx=w.back().first;
//     int ry=w.back().second;

//     for (int i = 0; i < 4; i++)
//     {
//         int nx=x+dx[i];
//         int ny=y+dy[i];

//         if(nx>=1 && ny>=1 && nx<=n && ny<=m){

//         }
//     }
    
// }

void bfs(){
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         ch[i][j]=false;
    //     }   
    // }
    fill(ch[1][1], ch[n+2][m+2], false);

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
    ch=new bool*[n+1];
    check=new bool*[n+1];
    input=new string[n+1];

    for (int i = 1; i <= n; i++)
    {
        cin>>input[i];
    }

    for (int i = 1; i <= n; i++)
    {
        line[i]=new int[m+1];
        ch[i]=new bool[m+1];
        check[i]=new bool[m+1];
    }
    

    for (int i = 1; i <= n; i++)
    {
        string sl=input[i];
        for (int j = 1; j <= m; j++)
        {
            if(sl.substr(j-1,1).compare(".")==0){
                line[i][j]=1;
            }else if(sl.substr(j-1,1).compare("L")==0){
                line[i][j]=2;
                w.push(make_pair(i,j));
            }else if(sl.substr(j-1,1).compare("X")==0){
                line[i][j]=0;
            }
        }
        
    }

    int i=0;
    while (true)
    {
        i++;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if(line[i][j]==0) q.push(make_pair(i,j));
            }
            
        }
        
        bfs();

        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= m; j++)
        //     {
        //         cout<<line[i][j];
        //     }
        //     cout<<"\n";
        // }
        
        wbfs();

        if(isable) break;
    }
    
    cout<<i<<endl;
    
}