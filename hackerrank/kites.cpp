#include <bits/stdc++.h>
using namespace std;
void printTop(int n)
{
    int l = 2, m = 0, r = 2;
    while (l >= 0 && r >= 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < l; j++)
                cout << " ";
            cout << "/";
            for (int j = 0; j < m; j++)
                cout << " ";
            cout << "\\";
            for (int j = 0; j < r; j++)
                cout << " ";
        }
        l--;
        r--;
        m += 2;
        cout << endl;
    }
}
void printBottom(int n)
{
    int l = 0, m = 4, r = 0;
    while (l <= 2 && m >= 0 && r <= 2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < l; j++)
                cout << " ";
            cout << "\\";
            for (int j = 0; j < m; j++)
                cout << " ";
            cout << "/";
            for (int j = 0; j < r; j++)
                cout << " ";
        }
        l++;
        r++;
        m -= 2;
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    printTop(n);
    printBottom(n);
    return 0;
}

/*
  /\  
 /  \
/    \
\    /
 \  /
  \/
*/