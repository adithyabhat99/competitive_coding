/*
print array based on frequency of occurance of element
*/
#include<bits/stdc++.h>
using namespace std;
struct s{
    int first,second;
};
bool compare(s a,s b){
    return a.second==b.second?a.first<b.first:a.second<b.second;
}
int main(){
    int n;
    cin>>n;
    int i;
    int a[n];
    map<int,int> m;
    for(i=0;i<n;i++){
        cin>>a[i];
        if(m.find(a[i])==m.end()){
            m[a[i]]=1;
        }
        else m[a[i]]++;
    }
    s b[m.size()];
    i=0;
    for(auto x:m){
        b[i].first=x.first;
        b[i].second=x.second;
        i++;
    }
    sort(b,b+m.size(),compare);
    for(i=0;i<m.size();i++)
    cout<<b[i].first<<" ";
    cout<<endl;
}