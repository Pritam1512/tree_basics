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
void postorder(struct node *temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
    return;
    
}
int twoDsum(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left!=NULL && root->right!=NULL)
    {
        return root->data + twoDsum(root->left)+twoDsum(root->right);
    }
    else
    {
        return twoDsum(root->left)+twoDsum(root->right);
    }
}
int oneDsum(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    if((root->left==NULL && root->right!=NULL) ||(root->left!=NULL && root->right==NULL) )
    {
        return root->data + oneDsum(root->left) + oneDsum(root->right);
    }
    else
    {
        return oneDsum(root->left)+oneDsum(root->right);
    }
}
int main()
{
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->left->right = createNode(7);
  
   // levelOrder(root);
   // cout << "" <<endl;
   // levelOrderLineByLine(root);
                //     1
                //    /  \
                //   2    3
                //  / \  / 
                // 4   5 6  
                //        \
                //         7

    vector<int> res;
    cout << oneDsum(root) << endl;
    return 0;
}
