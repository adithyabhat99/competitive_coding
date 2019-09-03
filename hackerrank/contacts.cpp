// https://www.hackerrank.com/challenges/contacts/problem
// Solved using trie data structure
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int count;
    node *next[26];
    node()
    {
        count = 0;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root;
void add(string name)
{
    node *curr = root;
    curr->count++;
    for (int i = 0; i < name.size(); i++)
    {
        char x = name[i];
        if (curr->next[(int)x - 'a'] == NULL)
            curr->next[(int)x - 'a'] = new node();
        curr = curr->next[(int)x - 'a'];
        curr->count++;
    }
}
int find(string s)
{
    node *curr = root;
    for (int i = 0; i < s.size(); i++)
    {
        char x = s[i];
        if (curr->next[(int)x - 'a'] == NULL)
            return 0;
        curr = curr->next[(int)x - 'a'];
    }
    return curr->count;
}
int main()
{
    int n;
    root = new node();
    cin >> n;
    while (n--)
    {
        string query, s;
        cin >> query >> s;
        if (query == "add")
        {
            add(s);
        }
        else
        {
            cout << find(s) << endl;
        }
    }
    return 0;
}