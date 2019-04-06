#include<iostream>
using namespace std;
int main(){
    int t,i,j;
    cin>>t;
    int n;
    string s;
    int x=0;
    while(x<t){
        cin>>n>>s;
        n=s.size();
        char m[n];
        j=0;
        for(i=0;i<n;i++){
            if(s[i]=='S')
            m[j++]='E';
            else
            m[j++]='S';
        }
        cout<<"Case #"<<x+1<<":"<<" ";
        for(i=0;i<n;i++)
        cout<<m[i];
        cout<<endl;
        x++;
    }
}