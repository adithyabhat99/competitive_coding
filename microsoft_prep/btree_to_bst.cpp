//https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1/?ref=self
struct Node
{
    int data;
    Node* left;
    Node* right;
};
/*Your code here*/
int countNodes(Node *root)
{
    if(!root) return 0;
    return countNodes(root->left)+countNodes(root->right)+1;
}
void inorderFill(Node *root,int *a,int &i)
{
    if(!root) return;
    inorderFill(root->left,a,i);
    a[i++]=root->data;
    inorderFill(root->right,a,i);
}
void arrayToBST(Node *root,int *a,int &i)
{
    if(!root) return;
    arrayToBST(root->left,a,i);
    root->data=a[i++];
    arrayToBST(root->right,a,i);
}
Node *binaryTreeToBST (Node *root)
{
//Your code here
    if(!root) NULL;
    int count=countNodes(root);
    int *a=new int[count];
    int i=0;
    inorderFill(root,a,i);
    sort(a,a+count);
    i=0;
    arrayToBST(root,a,i);
    delete []a;
    return root;
}