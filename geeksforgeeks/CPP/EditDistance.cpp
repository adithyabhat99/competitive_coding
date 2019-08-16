/*
    
Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

Insert
Remove
Replace
All of the above operations are of cost=1.
Both the strings are of lowercase.

Input:
The First line of the input contains an integer T denoting the number of test cases. Then T test cases follow. Each tese case consists of two lines. The first line of each test case consists of two space separated integers P and Q denoting the length of the strings str1 and str2 respectively. The second line of each test case coantains two space separated strings str1 and str2 in order.


Output:
Corresponding to each test case, pirnt in a new line, the minimum number of operations required.

Constraints:
1<=T<=50
1<= Length(str1) <= 100
1<= Length(str2) <= 100
 

Example:
Input:
1
4 5
geek gesek

Output:
1
*/
#include<iostream>
using namespace std;
int mini(int a,int b,int c){
    return min(min(a,b),c);
}
int steps(string s1,string s2,int m,int n){
    int i,j;
    int a[m+1][n+1];
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            if(i==0)
            a[i][j]=j;
            else if(j==0)
            a[i][j]=i;
            else if(s1[i-1]==s2[j-1])
            a[i][j]=a[i-1][j-1];
            else
            a[i][j]=1+mini(a[i-1][j],a[i][j-1],a[i-1][j-1]);
        }
    }
    return a[m][n];
}
int main() {
	//code
	int t,m,n;
	string s1,s2;
	cin>>t;
	while(t--){
	cin>>m>>n;
	cin>>s1>>s2;
	cout<<steps(s1,s2,m,n)<<endl;
	}
	return 0;
}