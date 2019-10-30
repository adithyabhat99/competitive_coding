//https://practice.geeksforgeeks.org/problems/convert-level-order-traversal-to-bst/1
Node *LevelOrder(Node* root,int data)
{
    if(!root)
    {
        root=new Node(data);
        return root;
    }
    if(data<=root->data)
        root->left=LevelOrder(root->left,data);
    else
        root->right=LevelOrder(root->right,data);
    return root;
}
Node* constructBst(int arr[], int n)
{
    
    // Code here
    Node *root=NULL;
	for(int i=0;i<n;i++)
	{
	    root=LevelOrder(root,arr[i]);
	}
	return root;
}