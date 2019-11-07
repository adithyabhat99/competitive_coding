//https://practice.geeksforgeeks.org/problems/count-the-reversals/0/?ref=self
//see the first comment for better solution
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string e;
	    stack<char> s;
	    cin>>e;
	    if(e.length()%2)
	    {
	        cout<<-1<<endl;
	        continue;
	    }
	    for(int i=0;i<e.length();i++)
	    {
	        if(!s.empty() && e[i]=='}')
	        {
	            if(s.top()=='{')
	                s.pop();
	            else
	                s.push('}');
	        }
	        else
	            s.push(e[i]);
	    }
	    int r=s.size();
	    int n=0;
	    while(!s.empty() && s.top()=='{')
	    {
	        n++;
	        s.pop();
	    }
	    cout<<(r/2)+(n%2)<<endl;
	}
	return 0;
}