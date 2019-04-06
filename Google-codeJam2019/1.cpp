#include<bits/stdc++.h>

#include<string>
using namespace std;


int main(){
    long long int n,i;
    long long int t;
    cin>>t;
    string s;
    long long int x=0;
    while(x<t){
    cin>>s;
    n=s.size();  
    char s1[n],s2[n];
    int l=0,m=0; 
    for(i=0;i<n;i++){
        if(s[i]=='4'){
            s1[l++]='3';
            s2[m++]='1';
        }
        else{
            s1[l++]=s[i];
            s2[m++]='0';
        }
    }
    cout<<"Case #"<<x+1<<":"<<" ";
        for(i=0;i<m;i++){
            cout<<s1[i];
        }
        cout<<" ";
        for(i=0;i<m;i++){
            cout<<s2[i];
        }
        cout<<endl;
    x++;
    }
}