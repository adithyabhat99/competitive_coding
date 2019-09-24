// https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem
// https://medium.com/@TheZaki/project-euler-2-even-fibonacci-numbers-2219e9438970
#include <bits/stdc++.h>
using namespace std;

long fibo(long n)
{
    long n2 = 2, n1 = 8;
    long sum = 10;
    while (1)
    {
        long X = 4 * n1 + n2;
        if (X >= n)
            return sum;
        sum += X;
        n2 = n1;
        n1 = X;
    }
}
int main()
{
    int t;
    cin >> t;
    for (int a0 = 0; a0 < t; a0++)
    {
        long n;
        cin >> n;
        cout << fibo(n) << endl;
    }
    return 0;
}
