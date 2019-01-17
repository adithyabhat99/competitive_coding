/*
Given a large number (represented as string) which has to divided by another number (represented as int data type). 
The large number can be very large which does not even fit in long long in C++.
 The task is to find division of these numbers.
*/
#include<iostream>
using namespace std;
string cal(string n,int d){
    string ans;
    int t,i=0;
    t=n[0]-'0';
    while(t<d){
        t=t*10+(n[++i]-'0');
    }
    while(i<n.length())
    {
        ans+=(t/d)+'0';
        t=(t%d)*10+(n[++i]-'0');
    }
    if(n.length()==0)
        return "0";
    return ans;

}
int main(){
    string num;
    int d,t;
    cin>>t;
    while(t--){
    cin>>num;
    cin>>d;
    cout<<cal(num,d)<<endl;
    }
}
