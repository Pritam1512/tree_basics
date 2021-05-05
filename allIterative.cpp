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
void inorderIter(node *root)
{
    stack<node *> st;
    node *temp = root;

    while(temp!=NULL || st.size()!=0)
    {
        while(temp)
        {
            st.push(temp);
            temp = temp->left;
        }

        temp = st.top();
        st.pop();
        cout << temp->data << " ";

        temp = temp->right;

    }
}
void preorderIter(node *root)
{
    stack<node *> st;
    node *temp = root;

    while(temp!=NULL || st.size()!=0)
    {
        while(temp)
        {
            cout << temp->data << " ";
            st.push(temp);
            temp = temp->left;
        }

        temp = st.top();
        st.pop();

        temp = temp->right;

    }
}
vector<int> postOrder(node *root)
{
    node *temp = root;
    stack<node *> st;
    vector<int> res;
    while(temp!=NULL || st.size()!=0)
    {
        while(temp)
        {
            st.push(temp);
            res.push_back(temp->data);
            temp = temp->right;
        }

        temp = st.top();
        st.pop();

        temp = temp->left;
    }
    reverse(res.begin(),res.end());
    return  res;
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

    vector<int> res = postOrder(root);
    for(auto x :res)
    {
        cout << x << " ";
    }
    return 0;
}
