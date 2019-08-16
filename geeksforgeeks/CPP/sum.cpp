#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,sum,i;
    map<int,int> m;
    cin>>n;
    cin>>sum;
    while(n--){
        cin>>i;
        m[i]=0;
        if(m.find(sum-i)!=m.end()){
            cout<<i<<" "<<sum-i<<endl;
            break;
        }
    }
}