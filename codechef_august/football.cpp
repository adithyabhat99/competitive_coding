#include<iostream>
using namespace std;
int main(){
    int n,t,i,m,s;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n],b[n];
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        for(i=0;i<n;i++){
            cin>>b[i];
        }
        m=0;
        for(i=0;i<n;i++){
            s=(20*a[i])-(10*b[i]);
            if(s<0)
                s=0;
            m=max(s,m);
        }
        cout<<m<<endl;
    }
    return 0;
}