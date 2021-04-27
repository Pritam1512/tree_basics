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
void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->left);
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
    inorder(root);
    

    return 0;
}
