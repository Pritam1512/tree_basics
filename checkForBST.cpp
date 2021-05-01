#include <bits/stdc++.h>
using namespace std;

int mi;
int ma;

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
bool checkBST(node *root ,int l,int h)
{
    if(root == NULL)
        return true;
    return (root->data > l && root->data < h) && checkBST(root->left,l,root->data) && checkBST(root->right,root->data,h);
}
int main()
{
    root = createNode(4);
    root->left = createNode(3);
    root->right = createNode(7);
    root->left->left = createNode(1);
    root->right->right = createNode(10);

                //     4
                //    /  \
                //   3    7
                //  /      \
                // 1        2
                //        
                // 
    cout << checkBST(root,INT_MIN,INT_MAX);
    return 0;
}
