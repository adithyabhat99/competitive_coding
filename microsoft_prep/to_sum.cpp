//https://cdnpractice.geeksforgeeks.org/problems/transform-to-sum-tree/1/?ref=self
int toSum(Node *node)
{
    if(!node)
    {
        return 0;
    }
    int l=toSum(node->left);
    int r=toSum(node->right);
    int x=node->data;
    node->data=l+r;
    return node->data+x;
}
void toSumTree(Node *node)
{
    // Your code here
    node->data=toSum(node);
}