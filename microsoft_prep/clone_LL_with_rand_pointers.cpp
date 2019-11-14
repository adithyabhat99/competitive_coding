//https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
Node *copyList(Node *head) {
    // Your code here
    vector<Node*>v;
    if(!head) return NULL;
    map<Node *,Node*> mp1,mp2;
    Node *n,*hh=NULL,*h=head,*prev=NULL;
    while(h)
    {
        if(!hh)
        {
            n=new Node(h->data);
            hh=n;
        }
        else
        {
            n=new Node(h->data);
            prev->next=n;
        }
        mp1[h]=n;
        mp2[n]=h;
        prev=n;
        h=h->next;
    }
    n=hh,h=head;
    while(n)
    {
        n->arb=mp1[mp2[n]->arb];
        n=n->next;
    }
    return hh;
}