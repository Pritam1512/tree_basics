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
void generateNumber(node *root,string str)
{
    if(root==NULL)
    {
        return ;
    }
    else if(root->left==NULL && root->right == NULL)
    {
        cout << str << " ";
    }
    if(root->left)
    {
        str.push_back(root->left->data);
        generateNumber(root->left,str);
        str.pop_back();
        str.push_back(root->right->data);
        generateNumber(root->right,str);
    }
    else
    {
        str.push_back(root->right->data);
        generateNumber(root->right,str);
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
    string str;
    str.push_back(root->data);
    generateNumber(root,str);
    
    return 0;
}
