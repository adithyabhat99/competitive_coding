//https://practice.geeksforgeeks.org/problems/polynomial-addition/1/?ref=self
void addPolynomial(Node *p1, Node *p2)
{
    //Your code here
    while(p1 && p2)
    {
        if(p1->pow==p2->pow)
        {
            cout<<p1->coeff+p2->coeff<<"x^"<<p1->pow;
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->pow>p2->pow)
        {
            cout<<p1->coeff<<"x^"<<p1->pow;
            p1=p1->next;
        }
        else
        {
            cout<<p2->coeff<<"x^"<<p2->pow;
            p2=p2->next;
        }
        if(p1 || p2) cout<<" + ";
    }
    while(p1)
    {
        cout<<p1->coeff<<"x^"<<p1->pow;
        p1=p1->next;
        if(p1) cout<<" + ";
    }
    while(p2)
    {
        cout<<p2->coeff<<"x^"<<p2->pow;
        p2=p2->next;
        if(p2) cout<<" + ";
    }
}