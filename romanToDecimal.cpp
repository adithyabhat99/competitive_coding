/*
Given an string in roman no format (s)  your task is to convert it to integer .

Input:
The first line of each test case contains the no of test cases T. Then T test cases follow. Each test case contains a string s denoting the roman no.

Output:
For each test case in a new line print the integer representation of roman number s. 

Constraints:
1<=T<=100
1<=roman no range<4000

Example:
Input
2
V
III 
Output
5
3
*/

#include <bits/stdc++.h>
using namespace std;
int priority(char c){
    switch(c){
        case 'I':return 1;
        case 'V':return 5;
        case 'X':return 10;
        case 'L':return 50;
        case 'C':return 100;
        case 'D':return 500;
        case 'M':return 1000;
    }
    return 0;
}
int value(string s,int n){
    int m=priority(s[n-1]),i;
    for(i=n-2;i>=0;i--){
        if(priority(s[i])<priority(s[i+1]))
        m-=priority(s[i]);
        else
        m+=priority(s[i]);
    }
    return m;
}
int main() {
	//code
	int t;
	string s;
	cin>>t;
	while(t--){
	    cin>>s;
	    cout<<value(s,s.size())<<endl;
	}
	return 0;
}