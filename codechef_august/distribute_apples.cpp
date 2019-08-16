#include<iostream>
using namespace std;
int main(){
    long long int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        if((n/k)%k){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}