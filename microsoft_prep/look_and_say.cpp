//https://practice.geeksforgeeks.org/problems/decode-the-pattern/0
#include <bits/stdc++.h>
using namespace std;
string nth(int n)
{
    int cnt;
    string str="11";
    if(n==1) return "1";
    if(n==2) return "11";
    for(int i=3;i<=n;i++)
    {
        str+='$';
        int x=str.size(),c=1;
        string temp="";
        for(int j=1;j<x;j++)
        {
            if(str[j]!=str[j-1])
            {
                temp+=c+'0';
                temp+=str[j-1];
                c=1;
            }
            else 
            {
                c++;
            }
        }
        str=temp;
    }
    return str;
}
int main() {
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    cout<<nth(n)<<endl;
	}
	return 0;
}