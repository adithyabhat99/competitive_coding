//https://cdnpractice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1/?ref=self
bool isIsomorphic(Node *root1,Node *root2)
{
//add code here.
    if(!root1 && !root2)
    {
        return true;
    }
    if(!root1 || !root2)
    {
        return false;
    }
    if(root1->data!=root2->data)
    {
        return false;
    }
    else
    {
        return (isIsomorphic(root1->left,root2->left)&&isIsomorphic(root1->right,root2->right))||(isIsomorphic(root1->left,root2->right)&&isIsomorphic(root1->right,root2->left));
    }
}