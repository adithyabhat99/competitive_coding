/*
Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle in a fixed direction.â€‹ The task is to choose the safe place in the circle so that when you perform these operations starting from 1st place in the circle, you are the last one remaining and survive. You are required to complete the function josephus which returns an integer denoting such position . 

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains 2 integers n and k .

Output:
For each test case in a new line output will be the safe position which satisfies the above condition.

Constraints:
1<=T<=100
1<=k,n<=20

Example(To be used only for expected output) :
Input:
2
3 2
5 3

Output
3
4
*/
int find(vector<int> &v,int n,int k,int i)
{
if(v.size()==1)
return v[0];
i=(i+(k-1))%v.size();
v.erase(v.begin()+i);
return find(v,n,k,i);
}
int josephus(int n, int k)
{
vector<int> v;
for(int i=0;i<n;i++) 
v.push_back(i+1);
return find(v,n,k,0);
}