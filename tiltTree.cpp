#include <bits/stdc++.h>
using namespace std;

int tilt = 0;

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

int nodeSum(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lv = nodeSum(root->left);
    int rv = nodeSum(root->right);
    tilt += abs(lv-rv);
    root->data = lv+rv + root->data;
    return root->data;
}
int main()
{
    root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(9);
    root->left->left = createNode(3);
    root->left->right = createNode(5);

    root->right->right = createNode(7);

                //     1
                //    /  \
                //   2    3
                //  / \   / \
                // 4   5  6  10
                //        \   \
                //         7    20
    cout << nodeSum(root) << endl;// with nodesum we calculate tilt value
    inorder(root);
    cout << "" << endl;
    cout << tilt << endl;
    return 0;
}
