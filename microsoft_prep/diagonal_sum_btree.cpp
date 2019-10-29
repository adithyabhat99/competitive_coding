//https://practice.geeksforgeeks.org/problems/diagonal-sum-in-binary-tree/1/?ref=self
void diagonalSum(Node* root)
{
 // Add your code here
    queue<Node *>q;
    if(!root) return;
    q.push(root);
    while(!q.empty())
    {
        int s=q.size(),sum=0;;
        while(s--)
        {
            Node *temp=q.front();
            q.pop();
            while(temp!=NULL)
            {
                sum+=temp->data;
                if(temp->left)
                    q.push(temp->left);
                temp=temp->right;
            }
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}