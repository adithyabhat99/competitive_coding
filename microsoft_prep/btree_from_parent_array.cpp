//https://practice.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1/?ref=self
Node *createTree(int parent[], int n)
{
// Your code here
    vector<Node*> v;
    for(int i=0;i<n;i++)
        v.push_back(NULL);
    
    for(int i=0;i<n;i++){
        if(parent[i]==-1){
            if(v[i]!=NULL)
                {
                    continue;
                }
            v[i] = new Node(i);
        }
        else if(v[parent[i]]==NULL){
            
            if(v[i]==NULL){
                Node* temp = new Node(i);
                v[i] = temp;
            }
            v[parent[i]] = new Node(parent[i]);
            v[parent[i]]->left = v[i];
        }
        else if(v[parent[i]]!=NULL){
            if(v[i]==NULL){
                Node* temp = new Node(i);
                v[i] = temp;
            }
            if(v[parent[i]]->left==NULL)
                {
                    v[parent[i]]->left = v[i];
                }
                else{
                    v[parent[i]]->right = v[i];
                }
        }
    }
    for(int i=0;i<n;i++)
        {
            if(parent[i]==-1)
                return v[i];
        }
}