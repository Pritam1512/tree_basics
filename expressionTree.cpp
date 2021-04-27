#include <bits/stdc++.h>
using namespace std;

//using level order 

struct node
{
    char data;
    struct node *left;
    struct node *right;
    
}*root = NULL;

struct node * createNode(char data)
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
int evaluateTree(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else if(root->left==NULL && root->right ==NULL)
    {
        return;
    }
    evaluateTree(root->left);
    evaluateTree(root->right);
    if(root->data == '*')
    {
        root->data = (root->left->data) * (root->right->data);
    }
    else if(root->data == '-')
    {
        root->data = (root->left->data) - (root->right->data);
    }
    else if(root->data == '+')
    {
        root->data = (root->left->data) + (root->right->data);
    }
}
int main()
{
    root = createNode('-');
    root->left = createNode('*');
    root->right = createNode('-');
    root->left->left = createNode('4');
    root->left->right = createNode('5');
    root->right->left = createNode('6');
    root->right->right = createNode('3');

    //root->right->left->right = createNode(8);
  
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
    evaluateTree(root);
    cout << root->data << endl;
    return 0;
}
