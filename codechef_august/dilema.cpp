#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    string x;
    cin>>t;
    while(t--){
        cin>>x;
        if(count(x.begin(),x.end(),'1')%2==0){
            cout<<"LOSE\n";
        }
        else{
            cout<<"WIN\n";
        }
   }
   return 0;
}