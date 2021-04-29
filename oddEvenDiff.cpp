#include <bits/stdc++.h>
using namespace std;

int oddSum,evenSum;

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
void helperOddEven(node *root,int level)
{
    if(root==NULL)
        return;
    if(level%2==0)
    {
        evenSum+=root->data;
    }
    else
    {
        oddSum+=root->data;
    }

    helperOddEven(root->left,level+1);
    helperOddEven(root->right,level+1);

}
int main()
{
    root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(9);
    root->left->left = createNode(3);
    root->left->right = createNode(5);

    root->right->right = createNode(7);

                //     4
                //    /  \
                //   2    9
                //  / \     \
                // 3   5    7
                //        
                //         
    helperOddEven(root,1);
    
    cout << oddSum-evenSum << endl;
    return 0;
}
