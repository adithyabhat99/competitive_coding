#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int count = s.size();
    for (int j = 0; j < s.size(); j++)
    {
        int top = -1, n = s.size();
        int stack[n];
        for (int i = j; i < n; i++)
        {
            if (top == -1)
            {
                stack[++top] = s[i];
                continue;
            }
            else if (s[i] == s[top] && i==j)
            {
                count++;
            }
            else if (top > 0 && s[i] == stack[top - 1])
            {
                top--;
                count++;
            }
            else
            {
                stack[++top] = s[i];
            }
        }
    }
    cout << count << endl;
    return 0;
}