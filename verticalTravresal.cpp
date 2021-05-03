#include <bits/stdc++.h>
using namespace std;


// VERTICAL ORDER TRAVERSAL 
// COMBINATION OF LEVEL ORDER AND MAP

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
void verticalTravresal(node *root,map<int,vector<int>> &mp)
{
        queue<pair<node *,int>> q;
        q.push({root,0});
        
        while(q.size()!=0)
        {
            node *temp = q.front().first;
            int level = q.front().second;
            
            q.pop();
            mp[level].push_back(temp->data);
            
            if(temp->left) q.push({temp->left,level-1});
            if(temp->right)q.push({temp->right,level+1});
            
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
    root->left->right ->left= createNode(8);
    root->left->right->left->right = createNode(9);


                //     1
                //    /  \
                //   2    3
                //  / \  / 
                // 4   5 6  
                //    /
                //   8 
                //    \
                //     9
    map<int,vector<int>> mp;
    verticalTravresal(root,mp);

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
