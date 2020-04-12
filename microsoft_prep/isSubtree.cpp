//https://practice.geeksforgeeks.org/problems/check-if-subtree/1
bool isSubtree(Node* T1, Node* T2) {
    // Your code here
    // return 1 if T2 is subtree of T1 else 0
    if(!T1 && !T2)
        return 1;
    if(!T1 || !T2)
        return 0;
    if(T1->data==T2->data)
    {
        return isSubtree(T1->left,T2->left) && isSubtree(T1->right,T2->right);
    }
    return isSubtree(T1->left,T2)||isSubtree(T1->right,T2);
}