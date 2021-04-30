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

void inorder(node *root)
{

    if(root!=NULL)
    {   
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void diagonalTraversal(node *root , map<int,vector<int>> &mp,int l)
{
    if(root==NULL)
        return;
    mp[l].push_back(root->data);

    diagonalTraversal(root->left,mp,l+1);
    diagonalTraversal(root->right,mp,l);

    
}
int main()
{
    root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->right->right = createNode(7);

                //     4
                //    /  \
                //   2    2
                //  /      \
                // 3        7
                //        
                //         
    
    map<int,vector<int>> mp;

    diagonalTraversal(root,mp,0);

    for(auto x:mp)
    {
        for(auto y:x.second)
        {
            cout << y << " "; 
        }
        cout << "" << endl;
    }
    return 0;
}
