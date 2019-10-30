//https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1/?ref=self
int minDiff(Node *root, int k)
{
    //Your code here
    if(!root) return INT_MAX;
    int d=(k-root->data<0)?root->data-k:k-root->data;
    return min(d,min(maxDiff(root->right,k),maxDiff(root->left,k)));
}