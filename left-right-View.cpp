#include<bits/stdc++.h>
using namespace std;
struct tree
{
    int data;
    struct tree *r;
    struct tree *l;
};
typedef struct tree * node;
node getnode(int d)
{
    node n=new struct tree;
    n->data=d;
    n->r=n->l=NULL;
    return n;
}
void preorder(node root){
    if(!root)
        return;
    cout<<root->data<<" ";
    preorder(root->l);
    preorder(root->r);
}
void leftView(node root)
{
   if(!root) return; 
   queue<node> q;
   node qq;
   q.push(root);
   int n=q.size();
   cout<<root->data<<" ";
   while(!q.empty()){
       qq=q.front();
       q.pop();
       n--;
       if(qq->l)
       q.push(qq->l);
       if(qq->r)
       q.push(qq->r);
       if(!n && !q.empty())
       {
           cout<<q.front()->data<<" ";
           n=q.size();
       }
   }
}
void rightView(node root)
{
   queue <node> q;
   node qq;
   if(!root) return;
   q.push(root);
   cout<<root->data<<" ";
   int n=q.size();
   while(!q.empty()){
      qq=q.front();
      q.pop();
      n--;
      if(qq->r)
      q.push(qq->r);
      if(qq->l)
      q.push(qq->l);
      if(!n && !q.empty())
      {
          cout<<q.front()->data<<" ";
          n=q.size();
      }
   }
}
int main()
{
    map<int,node> m;
    int p,c,n;
    char a;
    node root=NULL;
    node parent,child;
    cin>>n;
    while(n--){
        cin>>p>>c;
        getchar();
        cin>>a;
        if(m.find(p)==m.end()){
            parent=getnode(p);
            m[p]=parent;
            if(!root)
                root=parent;
        }
        else
            parent=m[p];
        child=getnode(c);
        if(a=='L')
            parent->l=child;
        else
            parent->r=child;
        m[c]=child;
    }
    preorder(root);
    cout<<endl;
    leftView(root);
    cout<<endl;
    rightView(root);
    cout<<endl;
    return 0;
}

