//https://www.techiedelight.com/count-total-possible-combinations-n-digit-numbers-mobile-keypad/
#include<bits/stdc++.h>
#define MAX 8
using namespace std;
int lookup[10][MAX];
int row[]={0,-1,0,1};
int col[]={-1,0,1,0};
bool isValid(int i,int j)
{
    if(i==3 && (j==0||j==2))
    {
        return false;
    }
    return (i>=0 && i<4 && j>=0 && j<3);
}
void fillmap(multimap<int,int>&mp)
{
    char keyboard[4][3]={
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'},
        {'*','0','#'}
    };
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<4;k++)
            {
                int r=i+row[k];
                int c=j+col[k];
                if(isValid(i,j) && isValid(r,c))
                {
                    mp.insert(make_pair(keyboard[i][j]-'0',keyboard[r][c]-'0'));
                }
            }
        }
    }
}
int getCount(multimap<int,int>&mp,int i,int n)
{
    if(n==1)
        return 1;
    if(lookup[i][n]==0)
    {
        lookup[i][n]=getCount(mp,i,n-1);
        for(auto it=mp.find(i);it!=mp.end()&&it->first==i;it++)
        {
            lookup[i][n]+=getCount(mp,it->second,n-1);
        }
    }
    return lookup[i][n];
}
int main()
{
    int n;
    cin>>n;
    if(n>MAX)
        return 0;
    multimap<int,int> mp;
    fillmap(mp);
    int c=0;
    for(int i=0;i<=9;i++)
    {
        c+=getCount(mp,i,n);
    }
    cout<<c<<endl;
    return 0;   
}