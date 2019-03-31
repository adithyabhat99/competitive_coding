/*
Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

For Example:
If the matrix is    

1 2 3
4 5 6
7 8 9
The output should Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]
i.e print the elements of array diagonally.

Note: The input array given is in single line and you have to output the answer in one line only.

 

Input:

The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N depicting the size of square matrix and next line followed by the value of array.


Output:

Print the elements of matrix diagonally in separate line.


Constraints:

1 ≤ T ≤ 30
1 ≤ N ≤ 20
0 ≤ A[i][j] ≤ 9


Example:

Input:
2
2
1 2 3 4
3
1 2 3 4 5 6 7 8 9
Output:
1 2 3 4
1 2 4 3 5 7 6 8 9
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t,n,i,j;
	cin>>t;
	while(t--){
	    cin>>n;
	    int a[n][n];
	    for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
	    cin>>a[i][j];
	    map<int,vector<int>> m;
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<n;j++){
	            m[i+j].push_back(a[i][j]);
	        }
	    }
	    auto x=m.begin();
	    while(x!=m.end()){
	        vector<int> v=x->second;
	        for(i=0;i<v.size();i++)
	        cout<<v[i]<<" ";
	        x++;
	    }
	    
	    cout<<endl;
	}
	return 0;
}