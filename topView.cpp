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
void topView(node *root,map<int,int> &mp)
{
    queue<pair<int,node *>> q;
    q.push({0,root});

    while(q.size()!=0)
    {
        node *temp = q.front().second;
        int level = q.front().first;
        q.pop();

        if(!mp.count(level))
        {
            mp[level] = temp->data;
        }

        if(temp->left) q.push({level-1,temp->left});
        if(temp->right) q.push({level+1,temp->right});

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
                //      / \
                //     8   7
                //    /
                //   9
    map<int,int> mp;
    topView(root,mp);

    for(auto x :mp)
    {
        cout << x.second << " ";
    }
    return 0;
}
