/*The cost of stock on each day is given in an aay A. Find all the days on which you buy and sell the stock so that in between those days you shouldn't have any loss.

Input: 
First line contains number of test cases T. Each test case contains the integer value N denoting days followed by an aay of stock prices of N days. 

Output:
For each testcase, output all the days with profit in a single line. And if there is no profit then print "No Profit".

Constraints:
1 <= T <= 100
2 <= N <= 103
1 <= Ai <= 104

Example
Input:
2
7
100 180 260 310 40 535 695
10
23 13 25 29 33 19 34 45 65 67

Output:
(0 3) (4 6)
(1 4) (5 9)

Note: Output format is as follows - (buy_day sell_day) (buy_day sell_day)
For each input, output should be in a single line.*/

#include<iostream>
#include<vector>
using namespace std;
vector <int> stock(int *a,int n){
    vector <int>s;
    int i,buy=0,sell=-1;
    a[n]=a[n-1];
    for(i=0;i<=n;i++){
        if(a[i]<=a[buy]){
            buy=i;
        }
        else if(a[i]>a[sell] || sell==-1){
            sell=i;
        }
        else if(a[buy]<a[sell] && (a[i]<a[sell] || i==n)){
            s.push_back(buy);
            s.push_back(sell);
            buy=i;
            sell=-1;
        }
    }
    return s;
}
int main()
{
    int n,t,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n+1];
        vector <int> profits;
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        profits=stock(a,n);
        if(profits.empty()){
            printf("No Profit\n");
        }
        for(i=0;i<profits.size();i+=2){
            cout<<"("<<profits[i]<<" "<<profits[i+1]<<")"<<" ";
        }
        cout<<endl;
    }
    return 0;
}