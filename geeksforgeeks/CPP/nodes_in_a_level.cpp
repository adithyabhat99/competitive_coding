// https://practice.geeksforgeeks.org/problems/k-distance-from-root/1/?ref=self
void printKdistance(Node *root, int k)
{
  queue<Node*> q;
   q.push(root);
   int l=-1;
   if(root==NULL)
   return;
   while(!q.empty())
   {
       int n=q.size();
       l++;
       if(l==k)
       {
       while(!q.empty())
       {
         cout<<q.front()->data<<" ";
         q.pop();
       }
       return;
       }
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
}