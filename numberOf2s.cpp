/*
Count the number of 2s as digit in all numbers from 0 to n.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains the input integer n.

Output:
Print the count of the number of 2s as digit in all numbers from 0 to n.

Constraints:
1<=T<=100
1<=N<=10^5

Example:
Input:
2
22
100

Output:
6
20
*/
/* Counts the number of 2s in a number at d-th
   digit */
long long int count2sinRangeAtDigit(long long int number, long long int d)
{
// Your code goes here
  string x=to_string(number);
  long long int c=0,i;
  for(i=0;i<d;i++){
      if(x[i]=='2')
      c++;
  }
  return c;
}
/* Counts the number of '2' digits between 0 and n */
long long int numberOf2sinRange(long long int number)
{
// Your code goes here
  long long int i,c=0;
  for(i=0;i<=number;i++)
  {
      c+=count2sinRangeAtDigit(i,to_string(i).length());
  }
  return c;
}