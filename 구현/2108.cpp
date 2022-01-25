#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){

    vector<int> v;

    int n;
    int sum=0;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        int s;
        cin>>s;
        v.push_back(s);
        sum+=s;
    }

    sort(v.begin(), v.end());

    cout<<sum/v.size()<<endl;
    cout<<v[v.size()/2]<<endl;
    cout<<""<<endl;
    cout<<v[v.size()-1]-v[0]<<endl;
}