/*Shashank is an entrepreneur who is hiring smart people for his new venture. In order to get hired by Shashank, you need to solve the following problem-

You are given an array A with size N (1 based indexing). For each number in the array, convert the number into its binary form and hence find the maximum number of 0s between two consecutive 1s. Let this value be x. For example, for 6(110), x=0; for 41(101001), x=2; for 2(10), x=0, etc.

Now you are given Q queries each having two integers L and R denoting the range of the positions in the array. For each query, print the maximum value of x in the range of positions [L,R] in the array A.

Input Format

First line of the input contains two integers N,Q.

Second line of the input contains the array A with N elements.

The next Q lines of the input contain two integers L,R.

Constraints

1<=N,Q<=10^5

1<=Ai<=10^9

1<=L,R<=N

Output Format

For each Query Q, print the maximum value of x each separated by a new line.*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int cc(int a[],int n)
{
    int i,c=0,m=0,max=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==1)
            m=1;
        if(m==1 && a[i]==0)
        {
            c++;
            continue;
        }
        if(m==1 && a[i]==1)
        {
            if(c>max)
                max=c;
            c=0;
        }
    }  
    return max;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n,q,i,left,right,x,count;
    cin>>n;
    cin>>q;
    int a[n],y[20];
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    while(q--)
    {
        cin>>left;
        cin>>right;
        int max=0;
        for(i=left;i<=right;i++)
        {
            int m=a[i],j=0;
            while(m)
            {
                y[j++]=m%2;
                m=m/2;
            }
            count=cc(y,j);
            if(count>max)
                max=count;
        }
        cout<<max<<endl;
    }
    
    return 0;
}
