#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
int i,x,c=0;
cin>>x;
    for(i=1;i<=(int)sqrt(x);i++) {
        if(x%i==0)
        {
            if(x/i==i)
                c++;
            else
                c=c+2;
        } 
    }
    cout<<c<<endl;
}