#include <bits/stdc++.h>
#include <ctype.h>
#include <string>
using namespace std;
int calculate(int a, int b, char c)
{
    if (c == '*')
        return a * b;
    if (c == '+')
        return a + b;
    if (c == '-')
        return a - b;
    return 0;
}
string calc(string s)
{
    vector<int> numbers;
    vector<char> operators;

    int i = 0, j = 0;
    while (i < s.length() && j < s.length())
    {
        if (isdigit(s[j]))
        {
            j++;
        }
        else
        {
            string ss = s.substr(i, j - i);
            numbers.push_back(atoi(ss.c_str()));
            operators.push_back(s[j]);
            i = ++j;
        }
    }
    string ss = s.substr(i, j - i);
    numbers.push_back(atoi(ss.c_str()));

    int n = numbers.size();
    int res[n][n];
    string resStr[n][n];

    for (int i = 0; i < n; i++)
    {
        res[i][i] = numbers[i];
        resStr[i][i] = to_string(numbers[i]);
    }

    for (int L = 1; L < n; L++)
    {
        for (int i = 0; i <= n - L - 1; i++)
        {
            int j = i + L;
            res[i][j] = INT_MIN;
            for (int k = i; k < j; k++)
            {
                int q = calculate(res[i][k], res[k + 1][j], operators[k]);
                if (q > res[i][j])
                {
                    res[i][j] = q;
                    resStr[i][j] = '(' + resStr[i][k] + operators[k] + resStr[k + 1][j] + ')';
                }
            }
        }
    }

    return resStr[0][n - 1];
}
int main()
{
    string s;
    cin >> s;
    cout << calc(s) << endl;
    return 0;
}