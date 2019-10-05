// https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1/?ref=self
int getMaxWidth(Node* root)
{
   queue<Node*> q;
   q.push(root);
   int m=INT_MIN;
   if(root==NULL)
   return 0;
   while(!q.empty())
   {
       int n=q.size();
       m=max(n,m);
       while(n>0)
       {
           Node* temp=q.front();
           if(temp->left)
           q.push(temp->left);
           if(temp->right)
           q.push(temp->right);
           q.pop();
           n--;
       }
   }
   return m;
}