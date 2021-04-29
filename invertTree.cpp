#include <bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node *left;
    struct node *right;
    
}*root = NULL;

struct node * createNode(int data)
{
    struct node *temp;
    temp = new node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;



}

void inorder(node *root)
{

    if(root!=NULL)
    {   
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void invert(node *root)
{
    if(root==NULL)
        return;
    invert(root->left);
    invert(root->right);

    swap(root->right,root->right);
}
int main()
{
    root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->right->right = createNode(7);

                //     4
                //    /  \
                //   2    2
                //  /      \
                // 3        3
                //        
                //         
    
    return 0;
}
