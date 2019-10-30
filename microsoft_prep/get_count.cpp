//https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1/?ref=self 
void count(Node *root, int l, int h,int &c)
{
    if(!root) return;
    if(l<=root->data && h>=root->data)
        c++;
    count(root->left,l,h,c);
    count(root->right,l,h,c);
}
int getCountOfNode(Node *root, int l, int h)
{
  // your code goes here   
    int c=0;
    count(root,l,h,c);
    return c;
}