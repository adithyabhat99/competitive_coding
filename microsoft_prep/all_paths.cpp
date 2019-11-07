//https://cdnpractice.geeksforgeeks.org/problems/root-to-leaf-paths/1/?ref=self
void printP(Node *root,vector<Node*>&s)
{
    if(!root->left && !root->right)
    {
        s.push_back(root);
        for(auto x:s)
            cout<<x->data<<" ";
        cout<<"#";
        s.pop_back();
        return;
    }
    s.push_back(root);
    if(root->left)
        printP(root->left,s);
    if(root->right)
        printP(root->right,s);
    s.pop_back();
}
void printPaths(Node* root)
{
    // Code here
    vector<Node*>s;
    printP(root,s);
    cout<<endl;
}