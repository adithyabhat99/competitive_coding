//https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1/?ref=self
struct Node
{
    int key;
    Node *left, *right;
}; 
/*Complete the function below*/
void kthLargestUntil(Node *root,int k,int &c)
{
    if(!root || c>=k)   return;
    kthLargestUntil(root->right,k,c);
    c++;
    if(k==c)
    {
        cout<<root->key<<endl;
        return;
    }
    kthLargestUntil(root->left,k,c);
}
void kthLargest(Node *root, int k)
{
    //Your code here
    int c=0;
    kthLargestUntil(root,k,c);
}