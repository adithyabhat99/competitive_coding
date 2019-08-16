/*
Given an array having both positive an negative integers . Your task is to complete the function maxLen which returns the length of maximum subarray with 0 sum . The function takes two arguments an array A and n where n is the size of the array A . 

Input:
The first line of input contains an element T denoting the No of test cases. Then T test cases follow. Each test case consist of 2 lines. The first line of each test case contains a number denoting the size of the array A. Then in the next line are space separated values of the array A .

Output:
For each test case output will be the length of the largest subarray which has sum 0 .

Constraints:
1<=T<=100
1<=N<=100
-1000<=A[]<=1000

Example:
Input
1
8
15  -2  2  -8  1  7  10 23

Output
5

Explanation
In the above test case the  largest subarray with sum 0 will be -2  2  -8  1  7
*/
int maxLen(int A[],int n)
{
  map<int,int>m;
  int sum,len=0;
  for(int i=0;i<n;i++){
      sum+=A[i];
      if(len==0 && A[i]==0)
      len=1;
      if(sum==0)
      len=i+1;
      if(m.find(sum)==m.end()){
          m[sum]=i;
      }
      else
      {
          len=max(len,i-m[sum]);
      }
  }
  return len;
}
