//Function to check whether a list given is binary search tree or not
bool isBST(Node* root) {
    // Your code here
    if(root==NULL)
        return true;
    if(!isBST(root->left))
        return false;
    static Node *prev=NULL;
    if(prev && prev->data>root->data)
    {
        prev=NULL;
        return false;
        
    }
    prev=root;
    return isBST(root->right);
}
