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
node *lca(node *root,int a,int b)
{
    if(root == NULL)
        return NULL;
    if(root->data == a || root->data == b)
        return root;
    node *l = lca(root->left,a,b);
    node *r = lca(root->right,a,b);

    if(l!= NULL && r != NULL)
        return root;
    else if(l!=NULL && r == NULL)
        return l;
    else
        return r;
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

   // levelOrder(root);
   // cout << "" <<endl;
   // levelOrderLineByLine(root);
                //     1
                //    /  \
                //   2    3
                //  / \  / 
                // 4   5 6  
                //      / \
                //     8   7
                //    
                //  
    node *res = lca(root,4,7);
    cout << " LCA is " << res->data << endl;
    return 0;
}
