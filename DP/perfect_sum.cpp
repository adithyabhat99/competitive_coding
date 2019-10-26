//https://www.geeksforgeeks.org/perfect-sum-problem-print-subsets-given-sum/
#include<bits/stdc++.h>
using namespace std;
void display(vector<int>v)
{
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;
}
void printSubs(int S[],bool **X,int n,int sum,vector<int>v)
{
    if(n==0) return;
    if(n==1 && sum!=0 && X[1][sum])
    {
        v.push_back(S[n-1]);
        display(v);
        return;
    }
    if(n==1 && sum==0)
    {
        display(v);
        return;
    }
    if(X[n-1][sum])
    {
        vector<int>v2=v;
        printSubs(S,X,n-1,sum,v2);
    }   
    if(sum>=S[n-1] && X[n-1][sum-S[n-1]])
    {
        v.push_back(S[n-1]);
        printSubs(S,X,n-1,sum-S[n-1],v);
    }
}
void SubsetSum(int S[],int n,int sum)
{
    bool **X=new bool*[n+1];
    for(int i=0;i<=n;i++)
    {
        X[i]=new bool[sum+1];
        X[i][0]=true;
    }
    for(int i=1;i<=sum;i++)
        X[0][i]=false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<S[i-1])
            {
                X[i][j]=X[i-1][j];
            }
            else
            {
                X[i][j]=X[i-1][j]||X[i-1][j-S[i-1]];
            }
        }
    }
    if(!X[n][sum])
    {
        cout<<"No subsets\n";
        return;
    }
    vector<int>v;
    printSubs(S,X,n,sum,v);
}
int main()
{
    int n,sum;
    cin>>n;
    int S[n];
    for(int i=0;i<n;i++)
    {
        cin>>S[i];
    }
    cin>>sum;
    SubsetSum(S,n,sum);
    return 0;
}