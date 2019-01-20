/*
A boy lost the password of his super locker. He remembers the number of digits N as well as the sum S of all the digits of his password. He know that his password is the largest number of N digits that can be possible with given sum S. As he is busy doing his homework, help him retrieving his password.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains two space separated integers N and S, where N is the number of digits in password and S is the sum of all the digits of the password.


Output:
Corresponding to each test case, in a new line, print the largest integer if possible , else print -1.

Constraints:
1<= T <= 100
1<= N <= 10000
0<= S <= 100000000

Example:

Input:

3
5 12
3 29
3 26

Output:
93000
-1
998

Explanation :

In first test case, sum of elements is 12. Largest possible 5 digit number is 93000.
In second test case, there is no such three digit number whose sum is 29.
*/
#include<bits/stdc++.h>
using namespace std;
void lar(int s,int m){
    
    if(s>9*m){
        cout<<-1;
        return;
    }
    int a[m];
    for(int i=0;i<m;i++){
        if(s>9)
        {
            a[i]=9;
            s-=9;
        }
        else{
        a[i]=s;
        s=0;
        }
    }
    for(int i=0;i<m;i++)
    {
        cout<<a[i];
    }
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int s,m;
	    cin>>m>>s;
	    lar(s,m);
	    cout<<endl;
	}
	return 0;
}