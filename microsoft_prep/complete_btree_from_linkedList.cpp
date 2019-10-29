//https://practice.geeksforgeeks.org/problems/make-binary-tree/1/?ref=self
void convert(Node *head, TreeNode *&root) {
    // Your code here
    if(!head) return;
    unordered_map<int,TreeNode*> mp;
    root=new TreeNode(head->data);
    head=head->next;
    mp[0]=root;
    int i=1;
    while(head!=NULL)
    {
        TreeNode *curr=new TreeNode(head->data);
        TreeNode *parent=mp[(i-1)/2];
        if(parent->left==NULL)
        {
            parent->left=curr;
        }
        else
        {
            parent->right=curr;
        }
        mp[i]=curr;
        i++;
        head=head->next;
    }
}