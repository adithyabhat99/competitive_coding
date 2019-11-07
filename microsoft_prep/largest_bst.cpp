//https://cdnpractice.geeksforgeeks.org/problems/largest-bst/1/?track=binary-search-tree
int Max(int a,int b)
{
    return max(a,b);
}
int largestUntil(Node *root,int &min_ref,int &max_ref,bool &is_bst,int &max_size)
{
    if(!root)
    {
        is_bst=true;
        return 0;
    } 
    int min=INT_MAX,max;
    bool left_flag=false,right_flag=false;
    int ls,rs;
    max_ref=INT_MIN;
    ls=largestUntil(root->left,min_ref,max_ref,is_bst,max_size);
    if(is_bst && root->data>max_ref)
    {
        left_flag=true;
    }
    min=min_ref;
    min_ref=INT_MAX;
    rs=largestUntil(root->right,min_ref,max_ref,is_bst,max_size);
    if(is_bst && root->data<min_ref)
    {
        right_flag=true;
    }
    if(min<min_ref)
        min_ref=min;
    if(root->data < min_ref)
        min_ref=root->data;
    if(root->data > max_ref)
        max_ref=root->data;
    if(left_flag && right_flag)
    {
        max_size=Max(max_size,ls+rs+1);
        return ls+rs+1;
    }
    else
    {
        is_bst=false;
        return 0;
    }
}
int largestBst(Node *root)
{
	//Your code here
	int min_ref=INT_MAX,max_ref=INT_MIN;
	bool is_bst=false;
	int max_size=0;
	largestUntil(root,min_ref,max_ref,is_bst,max_size);
	return max_size;
}