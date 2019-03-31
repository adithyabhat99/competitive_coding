/*You are bee stuck in a cell in a honeycomb. A honeycomb is a grid of hexagonal cells each having six neighbouring hexagonal cells.
The exit of the honeycomb is located at cell number 1. (refer honeycomb.jpg image)
You are given the pattern of the grid below. You need to find the minimum number of cells you have to cross to reach cell 1.
Note that the image labels the cells from 1 to 25. This pattern will be continued.

Input Format

The first line contains a single integer n which is the total number of queries.
n lines follow. Each of these lines contain a single integer x indicating the current cell number
Constraints

Output Format

For each of the n inputs print a single line with a single integer d which is the minumum distance from cell number x to 1.
Distance is the count of cells that were traversed before reaching the destination.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long int n,q,p;
    cin>>q;
    while(q--)
    {
        cin>>n;
        long long int c=0,prev=0,i,l=0;
        long long int x;
        x=n-1;
        if(n==1 || n==0 )
        {
            cout<<0<<endl;
            continue;
        }
        while(1)
        {
            if(x>prev && x<=c)
            {
                cout<<l-2<<endl;
                break;
            }
            prev=c;
            c=c+6*l;
            l++;     
        }
        
    }
    return 0;
}
