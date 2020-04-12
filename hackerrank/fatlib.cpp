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
    int value[n][n];
    string result[n][n];

    for (int i = 0; i < n; i++)
    {
        value[i][i] = numbers[i];
        result[i][i] = to_string(numbers[i]);
    }

    for (int L = 1; L < n; L++)
    {
        for (int i = 0; i < n - L; i++)
        {
            int j = i + L;
            value[i][j] = INT_MIN;
            for (int k = i; k < j; k++)
            {
                int q = calculate(value[i][k], value[k + 1][j], operators[k]);
                if (q > value[i][j])
                {
                    value[i][j] = q;
                    result[i][j] = '(' + result[i][k] + operators[k] + result[k + 1][j] + ')';
                }
            }
        }
    }

    return result[0][n - 1];
}
int main()
{
    string s;
    cin >> s;
    cout << calc(s) << endl;
    return 0;
}