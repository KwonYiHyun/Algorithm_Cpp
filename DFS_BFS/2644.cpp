#include <iostream>
#include <queue>

using namespace std;

int** line;
bool* ch;
int n;
int zx,zy;
int m;
int** s;
queue<int> q;
int* save;

void bfs(int num){
    q.push(num);
    save[num]=1;
    while (!q.empty())
    {
        int now=q.front();
        // cout<<n<<endl;
        q.pop();
        ch[now]=true;
        for (int i = 1; i <= n; i++)
        {
            if(line[now][i]==1 && !ch[i]){
                q.push(i);
                save[i]=save[now]+1;
            }
        }
        
    }
    
}

int main(){
    cin>>n;
    cin>>zx>>zy;
    cin>>m;
    s=new int*[m+1];
    line=new int*[n+1];
    ch=new bool[n+1];
    save=new int[n+1];

    for (int i = 1; i <= m; i++)
    {
        s[i]=new int[2];
    }

    for (int i = 1; i <= n; i++)
    {
        line[i]=new int[n+1];
        ch[i]=false;
        save[i]=0;
    }
    

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            line[i][j]=-1;
        }
        
    }
    
    for (int i = 1; i <= m; i++)
    {
        cin>>s[i][0]>>s[i][1];
        line[s[i][0]][s[i][1]]=1;
        line[s[i][1]][s[i][0]]=1;
    }
    bfs(zx);

    if(save[zy]==-1){
        cout<<save[zy];
    }else{
        cout<<save[zy]-1;
    }
}