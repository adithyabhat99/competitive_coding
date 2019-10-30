//https://practice.geeksforgeeks.org/problems/construct-an-expression-tree/1/?ref=self
struct et
{
	char value;
	et* left, *right;
};
//function to construct expression tree
et* constructTree(char postfix[])
{
//code here
    stack<et*>s;
    et *t,*t1,*t2;
    for(int i=0;i<strlen(postfix);i++)
    {
        char x=postfix[i];
        if(!isOperator(x))
        {
            t=new et(x);
            s.push(t);
        }
        else
        {
            t=new et(x);
            t1=s.top();
            s.pop();
            t2=s.top();
            s.pop();
            t->right=t1;
            t->left=t2;
            s.push(t);
        }
    }
    t=s.top();
    s.pop();
    return t;
}