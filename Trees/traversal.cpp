#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    ll data;
    node* left;
    node* right;
};
queue<node*> q;

node* newnode(ll data) {
    node* temp = new node;
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

void preorder(node* root) {
    if (!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(node* root) {
    if (!root) return;
    else if (!root->left && !root->right) {
        cout<<root->data<<" ";
    } else {
        cout<<root->data<<" ";
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            node* temp = q.front();
            q.pop();
            levelorder(temp);
        }

    }
}

void inorder(node* root) {
    if (!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
    node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    cout<<"Preorder:: ";
    preorder(root);
    cout<<endl;
    cout<<"PostOrder:: ";
    postorder(root);
    cout<<endl;
    cout<<"Inorder:: ";
    inorder(root);
    cout<<endl;
    cout<<"Levelorder:: ";
    levelorder(root);
    cout<<endl;

}