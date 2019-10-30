//https://practice.geeksforgeeks.org/problems/expression-tree/1/?ref=self
struct node{
	string data;
	node *left;
	node *right;
};
/*You are required to complete below method */
bool isOperator(string s)
{
    return (s=="+"||s=="-"||s=="*"||s=="/");
}
int cal(int a,int b,string o)
{
    if(o=="+") return a+b;
    if(o=="-") return a-b;
    if(o=="*") return a*b;
    if(o=="/") return a/b;
}
int evalTree(node* root)
{
    //Your code here
    if(!root) return 0;
    if(!isOperator(root->data))
        return stoi(root->data);
    int L=evalTree(root->left);
    int R=evalTree(root->right);
    return cal(L,R,root->data);
}