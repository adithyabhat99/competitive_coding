// https://practice.geeksforgeeks.org/problems/ancestors-in-binary-tree/1/?ref=self
bool printt(struct Node *root, int target)
{
    if(root==NULL)
        return false;
    if(root->data==target)
    {
      return true;
    }
    if(printt(root->left,target) || printt(root->right,target))
    {
      cout<<root->data<<" ";
    return true;
    }
    return false;
}
bool printAncestors(struct Node *root, int target)
{
      bool x=printt(root,target);
      cout<<endl;
      return x;
}