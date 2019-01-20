#include <bits/stdc++.h>
#include<string>
using namespace std;
int main() {
	//code
	int t,x=0;
	string a;
	cin>>t;
	while(t--){
        if(x==0) cin.ignore();
	    getline(cin,a);
	    vector<char> s;
	    for(int i=0;i<a.size();i++)
	    {
	       if(s.empty())
	       {
	           s.push_back(a[i]);
	       }
	       else
	       {
	           if(a[i]==' ' && find(s.begin(),s.end(),' ')==s.end()){
	               s.push_back(' ');
	           }
	           else if(find(s.begin(),s.end(),a[i])==s.end())
	           s.push_back(a[i]);
	       }
	    }
	    for(auto m:s){
	        cout<<m;
	    }
	    cout<<endl;
        x=1;
	}
	return 0;
}