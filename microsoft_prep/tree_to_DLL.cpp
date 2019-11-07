//https://practice.geeksforgeeks.org/problems/leaves-to-dll/1
Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};
Node *convertToDLL(Node *root,Node **head_ref)
{
//add code here.
    queue<Node*> q;
    if(!root) return NULL;
    q.push(root);
    vector<Node*>v;
    while(!q.empty())
    {
        int s=q.size();
        while(s--)
        {
            Node *f=q.front();
            q.pop();
            if(!f->left && !f->right) v.push_back(f);
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
        }
    }
    *head_ref=v[0];
    Node *prev=*head_ref;
    Node *h;
    for(int i=1;i<v.size();i++)
    {
        h=v[i];
        h->left=prev;
        prev->right=h;
        prev=h;
    }
    return root;
}

// Better solution
Node* extractLeafList(Node *root, Node **head_ref)  
{  
// Base cases  
if (root == NULL) return NULL;  
  
if (root->left == NULL && root->right == NULL)  
{  
    // This node is going to be added  
    // to doubly linked list of leaves, 
    // set right pointer of this node  
    // as previous head of DLL. We  
    // don't need to set left pointer   
    // as left is already NULL  
    root->right = *head_ref;  
  
    // Change left pointer of previous head  
    if (*head_ref != NULL) (*head_ref)->left = root;  
  
    // Change head of linked list  
    *head_ref = root;  
  
    return NULL; // Return new root  
}