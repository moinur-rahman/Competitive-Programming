#include<iostream>
using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node *left;
    Node *right;
};

bool Binary_S_tree(Node *rt,int low,int high)
{
    if(rt==NULL)
        return true;

    else if(low>=0&&rt->data<=low)
        return false;
    else if(high>=0&&rt->data>=high)
        return false;

    return Binary_S_tree(rt->left,low,rt->data)&&Binary_S_tree(rt->right,rt->data,high);
}


bool checkBST(Node *rt)
{
    return Binary_S_tree(rt,-1,-1);
}


int main()
{

    node *root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);

    if(isBST(root))
        cout<<"Is BST";
    else
        cout<<"Not a BST";

    return 0;
}
