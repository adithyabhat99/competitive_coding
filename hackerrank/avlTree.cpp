#include <iostream>
using namespace std;
struct node
{
    int val;
    struct node *left;
    struct node *right;
    int ht;
};
node *newnode(int val)
{
    node *root = new node();
    root->left = root->right = NULL;
    root->val = val;
    root->ht = 1;
    return root;
}
int height(node *root)
{
    return root ? root->ht : 0;
}
int BF(node *root)
{
    if (!root)
        return 0;
    return height(root->left) - height(root->right);
}
node *leftRotate(node *root)
{
    node *x = root->right;
    node *y = x->left;
    x->left = root;
    root->right = y;
    root->ht = max(height(root->left), height(root->right)) + 1;
    x->ht = max(height(x->left), height(x->right)) + 1;
    return x;
}
node *rightRotate(node *root)
{
    node *x = root->left;
    node *y = x->right;
    x->right = root;
    root->left = y;
    root->ht = max(height(root->left), height(root->right)) + 1;
    x->ht = max(height(x->left), height(x->right)) + 1;
    return x;
}
node *insert(node *root, int val)
{
    if (!root)
        return newnode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    if (val > root->val)
        root->right = insert(root->right, val);
    root->ht = max(height(root->left), height(root->right)) + 1;
    int bf = BF(root);
    if (bf > 1 && val < root->left->val)
    {
        return rightRotate(root);
    }
    if (bf > 1 && val > root->left->val)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (bf < -1 && val > root->right->val)
    {
        return leftRotate(root);
    }
    if (bf < -1 && val < root->right->val)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void inorder(node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main()
{
    node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 4);
    root = insert(root, 10);
    inorder(root);
    cout << endl;
    return 0;
}