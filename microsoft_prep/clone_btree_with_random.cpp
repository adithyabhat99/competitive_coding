//https://practice.geeksforgeeks.org/problems/clone-a-binary-tree/1
Node *copyLeftRight(Node *tree,unordered_map<Node*,Node*>&mp)
{
    if(tree==NULL)
        return NULL;
    Node *copy=new Node(tree->data);
    mp[tree]=copy;
    copy->left=copyLeftRight(tree->left,mp);
    copy->right=copyLeftRight(tree->right,mp);
    return copy;
}
void copyRandom(Node *tree,Node *copy,unordered_map<Node*,Node*>&mp)
{
    if(!copy)
        return;
    copy->random=mp[tree->random];
    copyRandom(tree->left,copy->left,mp);
    copyRandom(tree->right,copy->right,mp);
}
Node* cloneTree(Node* tree)
{
   //Your code here
   unordered_map<Node*,Node*>mp;
   Node *copy=copyLeftRight(tree,mp);
   copyRandom(copy,tree,mp);
   return copy;
}