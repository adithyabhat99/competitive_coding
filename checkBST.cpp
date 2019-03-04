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
//one more way!
//called as isBST(root,INT_MIN,INT_MAX); at beginning
bool isBST(Node *root,int min,int max){
    if(!root)
    return true;
    if(root->data<min || root->data >max)
    return false;
    return (isBS(root->left,min,root->data-1)&&isBS(root->right,root->data+1,max));
}

