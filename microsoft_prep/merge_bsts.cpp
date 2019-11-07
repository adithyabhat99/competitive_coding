//https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
/*
Naive method:
void Inorder(Node *root,multiset<int>&s)
{
    if(!root) return;
    Inorder(root->left,s);
    s.insert(root->data);
    Inorder(root->right,s);
}
void merge(Node *root1, Node *root2)
{
   //Your code here
    multiset<int> s;
    Inorder(root1,s);
    Inorder(root2,s);
    for(auto x:s)
        cout<<x<<" ";
}
*/
//Better solution O(m+n), using iterative inorder traversal
void inorder(Node *root)
{
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void merge(Node *root1, Node *root2)
{
    //Your code here
    Node *c1=root1,*c2=root2;
    stack<Node*>s1,s2;
    if(!root1)
    {
        inorder(root2);
        return;
    }
    if(!root2)
    {
        inorder(root1);
        return;
    }
    while(c1 || c2 || !s1.empty() || !s2.empty())
    {
        if(c1 || c2)
        {
            if(c1)
            {
                s1.push(c1);
                c1=c1->left;
            }
            if(c2)
            {
                s2.push(c2);
                c2=c2->left;
            }
        }
        else
        {
            if(s1.empty())
            {
               while(!s2.empty())
               {
                   c2=s2.top();
                   s2.pop();
                   c2->left=NULL;
                   inorder(c2);
               }
               return;
            }
            if(s2.empty())
            {
               while(!s1.empty())
               {
                   c1=s1.top();
                   s1.pop();
                   c1->left=NULL;
                   inorder(c1);
               }
               return;
            }
            c1=s1.top(); s1.pop();
            c2=s2.top(); s2.pop();
            if(c1->data<c2->data)
            {
                cout<<c1->data<<" ";
                c1=c1->right;
                s2.push(c2);
                c2=NULL;
            }
            else
            {
                cout<<c2->data<<" ";
                c2=c2->right;
                s1.push(c1);
                c1=NULL;
            }
        }
    }
}