// https://www.hackerrank.com/challenges/counting-valleys/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int count=0,prev;
    int x=0;
    if(s[0]=='U')
        prev=1,x=1;
    else
        prev=-1,x=-1;
    for(int i=1;i<n;i++)
    {
        if(s[i]=='D')
            x--;
        else
            x++;
        if(x==0 && prev<x)
            count++;
        prev=x;
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

