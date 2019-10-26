// https://practice.geeksforgeeks.org/problems/ugly-numbers/0
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n,i2,i3,i5;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    unsigned long long int ugly[n],next_ugly;
	    unsigned long long int next2=2,next3=3,next5=5;
	    ugly[0]=1,i2=0,i3=0,i5=0;
	    for(int i=1;i<n;i++)
	    {
	        next_ugly=min(next2,min(next3,next5));
	        ugly[i]=next_ugly;
	        if(next_ugly==next2)
	        {
	            i2+=1;
	            next2=ugly[i2]*2;
	        }
	        if(next_ugly==next3)
	        {
	            i3+=1;
	            next3=ugly[i3]*3;
	        }
	        if(next_ugly==next5)
	        {
	            i5+=1;
	            next5=ugly[i5]*5;
	        }
	    }
	    cout<<ugly[n-1]<<endl;
	}
	return 0;
}