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
vector<int> levelOrder(node *root)
{
    queue<node *> q;
    vector<int> res;

    q.push(root);
    while(q.size()!=0)
    {
        node *temp = q.front();
        q.pop();
        res.push_back(temp->data);

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);

    }
    return res;
}

void levelOrderRec(node *root,map<int,vector<int>> &mp,int l)
{
    if(root == NULL)
        return;
    
    mp[l].push_back(root->data);

    levelOrderRec(root->left , mp, l+1);
    levelOrderRec(root->right, mp, l+1);


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
    // level order ITERATIVE 
    // vector<int> res;
    // res = levelOrder(root);

    // for(auto x: res)
    // {
    //     cout << x << " ";
    // }


    // level order RECURSIVE (can also be used to print level order)

    map<int,vector<int> > mp;
    levelOrderRec(root,mp,0);

    for(auto x :mp)
    {
        for(auto y :x.second)
        {
            cout << y << " ";
        }
        cout << "" << endl;
    }


    return 0;
}
