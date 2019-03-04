/*
Write a function to print spiral order traversal of a tree. For below tree, function should print 1, 2, 3, 4, 5, 6, 7.
Input:
The task is to complete the method which takes one argument, root of the Tree. The struct node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should print level order traversal in spiral form .

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 3000
1 <=Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1 3 2
10 20 30 60 40
*/

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
void inorder(node root){
    if(!root)
        return;
    inorder(root->l);
    cout<<root->data<<" ";
    inorder(root->r);
}
void printSpiral(node root)
{
    if(!root) return;
     queue<node>q;
     q.push(root);
     node curr;
     int n=q.size(),dir=1;
     vector<int> v;
     while(!q.empty()){
         while(n-- && !q.empty()){
             curr=q.front();
             v.push_back(curr->data);
             if(curr->l)
             {
                 q.push(curr->l);
             }
             if(curr->r)
             {
                 q.push(curr->r);
             }
             q.pop();
         }
        if(!dir){
        for(auto x:v)
            cout<<x<<" ";
            dir=1;
        }
        else{
            for(int xx=v.size()-1;xx>=0;xx--)
            cout<<v[xx]<<" ";
            dir=0;
        }
        v.clear();
        n=q.size();
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
    inorder(root);
    cout<<endl;
    printSpiral(root);
    cout<<endl;
    return 0;
}

