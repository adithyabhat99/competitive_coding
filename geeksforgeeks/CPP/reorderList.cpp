//https://practice.geeksforgeeks.org/problems/reorder-list/1
#include <bits/stdc++.h>
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void reorderList(Node *head)
{
    // Your code here
    vector<int> v;
    Node *t = head;
    while (t)
    {
        v.push_back(t->data);
        t = t->next;
    }
    int i;
    t = head;
    for (i = 0; i < v.size() / 2; i++)
    {
        // cout<<v[i]<<" "<<v[v.size()-1-i]<<" ";
        t->data = v[i];
        if (t->next)
            t->next->data = v[v.size() - i - 1];
        if (t->next)
            t = t->next;
        if (t->next)
            t = t->next;
    }
    t->data = v[i];
}