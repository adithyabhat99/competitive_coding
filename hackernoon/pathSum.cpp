/*
Given a binary tree and a number ‘pathSum’ 
find if the tree has a path from root-to-leaf 
such that the sum of all the node values of that path equals ‘pathSum’
*/
// I used binary search tree here.
#include <bits/stdc++.h>
using namespace std;
struct tree
{
    int data;
    tree *left, *right;
    tree(int d)
    {
        left = right = NULL;
        data = d;
    }
};
tree *insert(int data, tree *root)
{
    if (!root)
        return new tree(data);
    if (data < root->data)
        root->left = insert(data, root->left);
    if (data > root->data)
        root->right = insert(data, root->right);
    return root;
}
void inorder(tree *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}
bool isPath(tree *root, int pathSum, int currSum)
{
    if (!root)
        return false;
    currSum += root->data;
    if (currSum == pathSum)
        return true;
    return isPath(root->left, pathSum, currSum) || isPath(root->right, pathSum, currSum);
}
int main()
{
    int ch, data;
    tree *root = NULL;
    do
    {
        cout << "Enter choice, 1 insert,2 display,0 Exit insertion\n";
        cin >> ch;
        if (ch == 1)
        {
            cin >> data;
            root = insert(data, root);
        }
        else if (ch == 2)
            inorder(root);
    } while (ch != 0);
    int pathSum;
    cout << "Enter the path sum\n";
    cin >> pathSum;
    if (isPath(root, pathSum, 0))
    {
        cout << "Path with given sum exists\n";
    }
    else
    {
        cout << "Path with given sum does not exist\n";
    }
    return 0;
}