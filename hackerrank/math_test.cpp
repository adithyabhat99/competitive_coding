#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n<=1 || n%2)
    {
        cout<<"Fail\n";
    }
    else
    {
        for(int i=0;i<n-1;i+=2)
            cout<<i+1<<" "<<i<<" ";
        cout<<endl;
    }
    return 0;
}