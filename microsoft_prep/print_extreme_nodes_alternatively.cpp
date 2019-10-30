//https://practice.geeksforgeeks.org/problems/extreme-nodes-in-alternate-order/1/?ref=self
void printExtremeNodes(Node* root)
{
    // Your code here
    queue<Node*>q;
    if(!root) return;
    q.push(root);
    int x=0;
    while(!q.empty())
    {
        int s=q.size();
        if(x==0)
            cout<<q.back()->data<<" ";
        else
            cout<<q.front()->data<<" ";
        x=(x==0)?1:0;
        while(s--)
        {
            Node* curr=q.front();
            q.pop();
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
}