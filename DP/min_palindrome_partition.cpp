//https://www.techiedelight.com/find-minimum-cuts-needed-palindromic-partition-string/
#include<bits/stdc++.h>
using namespace std;
bool pals[20][20];
void findpals(string s,int n)
{
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<=n;j++)
        {
            if(i==j)
                pals[i][j]=true;
            else if(s[i]==s[j])
                pals[i][j]=(j-i==1)?true:pals[i+1][j-1];
            else
                pals[i][j]=false;
        }
    }
}
int minPartitions(string s,int n)
{   
    int lookup[n];
    for(int i=n-1;i>=0;i--)
    {
        lookup[i]=INT_MAX;
        if(pals[i][n-1])
            lookup[i]=0;
        else
        {
            for(int j=n-2;j>=i;j--)
            {
                if(pals[i][j])
                    lookup[i]=min(lookup[i],1+lookup[j+1]);
            }
        }
    }
    return lookup[0];
}
int main()
{
    string s;
    cin>>s;
    findpals(s,s.length());
    cout<<minPartitions(s,s.length())<<endl;
    return 0;
}
/* Recursive
#include<bits/stdc++.h>
using namespace std;
bool isPal(string s,int i,int j)
{
    while(i<=j)
    {
        if(s[i++]!=s[j--])
            return false;
    }
    return true;
}
int minPartitions(string s,int i,int j)
{
    if(i==j || isPal(s,i,j))
        return 0;
    int Min=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int c=1+minPartitions(s,i,k)+minPartitions(s,k+1,j);
        Min=min(Min,c);
    }
    return Min;
}
int main()
{
    string s;
    cin>>s;
    cout<<minPartitions(s,0,s.length()-1)<<endl;
}*/