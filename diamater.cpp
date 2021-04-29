#include <bits/stdc++.h>
using namespace std;

int ans = 0;

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
int diameter(node *root)
{
    if(root==NULL)
        return 0;
    int lh = diameter(root->left);
    int rh = diameter(root->right);

    ans = max(ans,lh+rh+1);

    return max(lh,rh)+1;
}
int main()
{
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->right->right = createNode(10);
    root->right->right->right = createNode(20);
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
                //  / \   / \
                // 4   5  6  10
                //        \   \
                //         7    20
    // cout << isBalanced(root);
    // -1 means tree is not balanced
    // else return height of tree
    
    diameter(root);
    cout << ans << endl;
    return 0;
}
