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
void helper(node *root,int level,map<int,int> &mp)
{
    if(root==NULL)
        return;
    mp[level]+= root->data;
    helper(root->left,level+1,mp);
    helper(root->right,level+1,mp);

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
    map<int,int> mp;
    helper(root,1,mp);
    int m = INT_MIN;
    for(auto x : mp)
    {
        m = max(m,x.second);
    }
    cout << m << endl;
    return 0;
}
