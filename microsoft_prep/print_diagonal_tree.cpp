//https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1/?ref=self
void diagonalPrint(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *t=q.front();
        while(t){
            cout<<t->data<<" ";
            if(t->left)
                q.push(t->left);
            t=t->right;
        }
        q.pop();
    }
    //To print diagonals line by line(having NULL as delimiter inside queue)
   /*queue<Node *>q;
   if(!root) return;
   q.push(root);
   q.push(NULL);
   while(!q.empty())
   {
       Node *temp=q.front();
       q.pop();
       if(temp==NULL)
       {
            if(q.empty())
                return;
            cout<<endl;
            q.push(NULL);
       }
       else
       {
           while(temp)
           {
                cout<<temp->data<<" ";
                if(temp->left)
                    q.push(temp->left);
                temp=temp->right;
           }
       }
   }*/
}