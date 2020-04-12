#include<bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string s;
    cin>>s;
    set<int> S;
    for(int i=0;i<s.length();i++)
    {
        int pos=i+1;
        int rep_pos=(2*pos)<=s.length()?(2*pos):(2*pos)-s.length();
        cout<<pos<<" "<<rep_pos<<endl;
        if(s[pos-1]==s[rep_pos-1])
        {
            S.insert((int)s[i]-'0');
        }
    }
    int sum=0;
    for(auto x:S)
        sum+=x;
    cout<<sum<<endl;
    return 0;
}