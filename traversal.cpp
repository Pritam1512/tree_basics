#include <bits/stdc++.h>
using namespace std;

//INORDER TRAVERSAL
//POSTORDER TRAVERSAL
//PREORDER TRAVERSAL

//LEVEL ORDER 2 METHODS
//USING queue


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
void parentSum(node *root)
{
    if(root==NULL)
        return;
    else if(root->left == NULL  && root->right == NULL)
        return;
    else
    {
        parentSum(root->left);
        parentSum(root->right);
         int a = 0;
         int b = 0;
        if(root->left)
            a = root->left->data;
        if(root->right)
            b = root->right->data;
        root->data = a+b;
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

    //cout << height(root) << endl;
    // printAtK(root,1);

    //printLevel(root);
    postorder(root);
    cout<< "" << endl;
    parentSum(root);
    postorder(root);

    return 0;
}
