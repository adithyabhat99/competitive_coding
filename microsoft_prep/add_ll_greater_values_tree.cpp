//https://practice.geeksforgeeks.org/problems/add-all-greater-values-to-every-node-in-a-bst/1/?ref=self
void mod(Node *root,int &sum)
{
    if(!root) return;
    mod(root->right,sum);
    sum+=root->data;
    root->data=sum;
    mod(root->left,sum);
}
void modify(Node **root)
{
// Your code here
    int sum=0;
    mod(*root,sum);
}