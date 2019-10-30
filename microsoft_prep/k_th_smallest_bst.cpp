//https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1/?ref=self
struct Node
{
    int data;
    int lCount;
    Node* left;
    Node* right;
};
int KthSmallestElement(Node *root, int k)
{
    //add code here.
    if(!root) return 0;
    Node *p=root;
    while(p)
    {
        if(k==(p->lCount+1))
            return p->data;
        else if(k>p->lCount)
        {
            k=k-(p->lCount+1);
            p=p->right;
        }
        else
        {
            p=p->left;
        }
    }
}