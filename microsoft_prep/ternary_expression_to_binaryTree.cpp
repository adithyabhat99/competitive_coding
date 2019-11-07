//https://practice.geeksforgeeks.org/problems/convert-ternary-expression-to-binary-tree/1/?ref=self
Node *convertExpression(string str,int i)
{
//add code here.
    Node *root=new Node(str[i]);
    if(i==str.length()-1)
        return root;
    //move ahead str
    i++;
    if(str[i]=='?')
    {
        //skip ?
        i++;
        root->left=convert(str,i);
        //skip :
        i++;
        root->right=convert(str,i);
    }
    return root;
}