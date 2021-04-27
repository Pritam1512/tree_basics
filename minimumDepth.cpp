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
void minDepth(node *root,vector<int> &res,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        res.push_back(k);
    }
    else
    {
        minDepth(root->left,res,k+1);
        minDepth(root->right,res,k+1);
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
    root->right->left->left = createNode(8);
    root->right->left->left->left = createNode(9);
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
    //parentSum(root);
    //postorder(root);
    minDepth(root,res,1);
    //cout << res.size() << endl;
    for(auto x : res)
    {
        cout << x << " ";
    }
    return 0;
}
