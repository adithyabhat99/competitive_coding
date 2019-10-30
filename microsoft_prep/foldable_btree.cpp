//https://practice.geeksforgeeks.org/problems/foldable-binary-tree/1
struct node
{
    int data;
    struct node* left;
    struct node* right;
    
    node(int x){
        data = x;
        left = right = NULL;
    }
};
void mirror(struct node *root)
{
    if(!root) return;
    node *temp;
    mirror(root->left);
    mirror(root->right);
    temp=root->left;
    root->left=root->right;
    root->right=temp;
}
bool isStructSame(struct node* r1,struct node* r2)
{
    if(!r1 && !r2)
        return true;
    if(r1 && r2 && (isStructSame(r1->left,r2->left)) && (isStructSame(r1->right,r2->right)))
        return true;
    return false;
}
bool isFoldable(struct node *root)
{
    // Your code goes here
    if(!root) return true;
    mirror(root->left);
    bool ans=isStructSame(root->left,root->right);
    mirror(root->left);
    return ans;
}