#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int>::iterator iter=v.begin();

    for (iter=v.begin(); iter!=v.end(); ++iter)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;

    iter=v.begin();

    cout<<"iter[0] : "<<iter[0]<<endl;
    cout<<"iter[3] : "<<iter[3]<<endl<<endl;

    cout<<"iterator가 3번째 원소를 가리키도록 변경"<<endl;
    iter+=2;
    cout<<"iter[0] : "<<iter[0]<<endl;
    cout<<"*iter : "<<*iter<<endl;

    *iter=10;
    *(iter+1)=20;
    iter[2]=30;

    for (iter=v.begin(); iter!=v.end(); ++iter)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
    
}