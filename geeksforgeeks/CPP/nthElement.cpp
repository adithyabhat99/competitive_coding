#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    int a;
    for(int i=0;i<10;i++){
        cin>>a;
        v.push_back(a);
    }    
    cout<<endl;
    nth_element(v.begin(),v.begin()+4,v.end()); //it uses a function related to QuickSort
    cout<<v[4]<<endl;
    cout<<endl;
    random_shuffle(v.begin(),v.end());
    for(auto x:v)
        cout<<x<<endl;

    string s="adithya";
    cout<<s.substr(1,3)<<endl;
    return 0;
}