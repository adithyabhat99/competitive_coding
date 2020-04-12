//https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers/0
#include <iostream>
#define m 5000
using namespace std;
void multiply(int a[],int &s,int i)
{
    int carry=0;
    for(int j=0;j<s;j++)
    {
        int p=a[j]*i+carry;
        carry=p/10;
        a[j]=p%10;
    }
    while(carry)
    {
        a[s]=carry%10;
        carry=carry/10;
        s++;
    }
}
void fact(int n)
{
    int a[m];
    a[0]=1;
    int s=1;
    for(int i=2;i<=n;i++)
    {
        multiply(a,s,i);
    }
    for(int i=s-1;i>=0;i--)
        cout<<a[i];
    cout<<endl;
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    fact(n);
	}
	return 0;
}