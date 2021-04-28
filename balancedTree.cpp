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
void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int isBalanced(node *root)
{
    if(root==NULL) return 0;
    int lh = isBalanced(root->left);
    if(lh == -1) return -1;
    int rh = isBalanced(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh) > 1)
    {
        return -1;
    } 
    else
    {
        return max(lh,rh)+1;
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
    root->right->left->right->left = createNode(8);
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
    cout << isBalanced(root);
    // -1 means tree is not balanced
    // else return height of tree
    return 0;
}
