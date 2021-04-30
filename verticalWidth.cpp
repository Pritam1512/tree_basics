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

void helper(node *root,int l)
{
    if(root==NULL)
        return;
    mi = min(mi,l);
    ma = max(ma,l);

    helper(root->left,l-1);
    helper(root->right,l+1);

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
    mi = INT_MAX;
    ma = INT_MIN;

    helper(root,0);
    cout << ma-mi+1 << endl;
    return 0;
}
