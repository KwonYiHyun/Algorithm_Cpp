#include <iostream>

using namespace std;

int main(){

    int e,s,m;
    int cnt=0;
    cin>>e>>s>>m;

    int n1=1,n2=1,n3=1;

    while (true)
    {
        cnt++;
        if(e==n1 && s==n2 && m==n3) break;
        int ee=(n1%15)+1;
        int ss=(n2%28)+1;
        int mm=(n3%19)+1;
        cout<<ee<<" / "<<ss<<" / "<<mm<<endl;
        n1=ee;
        n2=ss;
        n3=mm;
        
    }
    
    cout<<cnt;
}