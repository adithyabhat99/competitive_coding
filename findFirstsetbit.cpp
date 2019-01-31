/*
  
Given an integer an N, write a program to print the position of first set bit found from right side in the binary representation of the number.

Input:
The first line of the input contains an integer T, denoting the number of test cases. Then T test cases follow. The only line of the each test case contains an integer N.

Output:
For each test case print in a single line an integer denoting the position of the first set bit found form right side of the binary representation of the number.If there is no set bit print "0".

Constraints:
1<=T<=200
0<=N<=106

Example:
Input:
2
18
12

Output:
2
3
*/

int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int x=0;
	    if(!n){ cout<<"0\n"; continue; }
	    while(!(n&1) && n)
	    {
	        x++;
	        n=n>>1;
	    }
	    cout<<x+1<<endl;
	}
	return 0;
}