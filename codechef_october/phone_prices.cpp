#include<iostream>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int c=1;
        for(int i=1;i<n;i++)
        {
            int x=5;
            int m=1;
            for(int j=i-1;j>=0 && x>0;j--)
            {
                x--;
                if(a[j]<=a[i])
                {
                    m=0;
                    break;
                }
            }
            if(m==1)
            {
                c++;
            }
        }
        cout<<c<<endl;
    }
}