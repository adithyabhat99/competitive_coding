//https://practice.geeksforgeeks.org/problems/children-sum-parent/1/?ref=self
int isSumProperty(Node *node)
{
 // Add your code here
    int sum=0;
    if(!node || !node->right || !node->left) return 0;
    sum+=node->left->data;
    sum+=node->right->data;
    isSumProperty(node->left);
    isSumProperty(node->right);
    if(sum!=node->data)
        return 0;
    return 1;
}