#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long int n,q,p;
    cin>>q;
    while(q--)
    {
        cin>>n;
        long long int c=0,prev=0,i,l=0;
        long long int x;
        x=n-1;
        if(n==1 || n==0 )
        {
            cout<<0<<endl;
            continue;
        }
        while(1)
        {
            if(x>prev && x<=c)
            {
                cout<<l-2<<endl;
                break;
            }
            prev=c;
            c=c+6*l;
            l++;     
        }
        
    }
    return 0;
}
