#include<bits/stdc++.h>
using namespace std;

struct node{
    int key;
    node* left;
    node* right;
    node(int k){
        key=k;
        left=right=NULL;
    }
};

void preorder(node* root){
    if(root!=NULL){
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

void postorder(node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}

int height(node* root){
    if(root==NULL){
        return 0;
    }
    return (max(height(root->left), height(root->right)))+1;
}

void printK(node* root, int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->key<<" ";
    }
    else{
        printK(root->left, k-1);
        printK(root->right, k-1);
    }
}

void bfs(node* root, int h){
    for(int i=0; i<h; i++){
        printK(root, i);
    }
}

void qbfs(node* root){
    if(root==NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        node* curr=q.front();
        q.pop();
        cout<<curr->key<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
    
}

int main(){
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->right->right=new node(60);
    root->left->right->left=new node(70);
    root->left->right->right=new node(80);
    preorder(root);
    cout<<"\n";
    postorder(root);
    cout<<"\n";
    inorder(root);
    cout<<"\n";
    int h=height(root);
    cout<<height(root)<<"\n";
    printK(root, 3);
    cout<<"\n";
    bfs(root, h);
    cout<<"\n";
    qbfs(root);
    cout<<"\n";
    return 0;
}