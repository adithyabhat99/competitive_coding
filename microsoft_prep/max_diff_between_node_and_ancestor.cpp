//https://practice.geeksforgeeks.org/problems/maximum-difference-between-node-and-its-ancestor/1/?ref=self
int min_elem(Node* root)
{
    if(!root) return INT_MAX;
    return min(root->data,min(min_elem(root->left),min_elem(root->right)));
}
int maxDiff(Node* root)
{
    if(root==NULL) return INT_MIN;
    return max(root->data-(min(min_elem(root->left),min_elem(root->right))),max(maxDiff(root->left),maxDiff(root->right)));
}