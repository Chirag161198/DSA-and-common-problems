#include <iostream>

using namespace std;

struct treeNode {
    int item;
    treeNode *parent;
    treeNode *left;
    treeNode *right;
};

void traversal(treeNode* root){
    if(root!=NULL){
        cout<<root->item<<endl;
        traversal(root->left);
        traversal(root->right);
    }
}

void insert(treeNode* & root, int x, treeNode* parent = NULL){
    if(root==NULL){
        root = new treeNode({x, parent, NULL, NULL});
        cout<<x<<" inserted"<<endl;
    }
    else{
        if(x>root->item){
            insert(root->right, x, root);
        }
        else if(x<root->item){
            insert(root->left, x, root);
        }
        else{
            cout<<x<<" already exist"<<endl;
        }
    }
}

treeNode* search(treeNode* root, int x){
    if(root==NULL) return NULL;

    else if(root->item==x){
        return root;
    }
    else if(root->item>x){
        return search(root->left, x);
    }
    else if(root->item<x){
        return search(root->right, x);
    }
    return NULL;
}

treeNode* find_minimum(treeNode* root){
    if(root==NULL) return NULL;
    if(root->left==NULL) return root;
    return find_minimum(root->left);
    return NULL;
}

treeNode* find_maximum(treeNode* root){
    if(root==NULL) return NULL;
    if(root->right==NULL) return root;
    return find_maximum(root->right);
    return NULL;
}

bool remove(treeNode* root, int x){
    treeNode* nodeRemoved = search(root, x);
    
    if(nodeRemoved==NULL) {
        return false;
    }

    treeNode* nodeParent = nodeRemoved->parent;

    if(nodeRemoved->right==NULL&&nodeRemoved->left==NULL){
        if(nodeRemoved==nodeParent->left) nodeParent->left = NULL;
        else nodeParent->right = NULL;
        return true;
    }

    else if(nodeRemoved->left==NULL){
        if(nodeRemoved==nodeParent->left) nodeParent->left = nodeRemoved->right;
        else nodeParent->right = nodeParent->right;
        return true;
    }

    else if(nodeRemoved->right==NULL){
        if(nodeRemoved==nodeParent->left) nodeParent->left = nodeRemoved->right;
        else nodeParent->right = nodeParent->right;
        return true;
    }

    else{
        treeNode* minimum = find_minimum(nodeRemoved->right);
        nodeRemoved->item = minimum->item;
        return remove(nodeRemoved->right, minimum->item);
    }
    return false;
}


int main(){
    treeNode* tree = new treeNode({5,NULL,NULL,NULL});
    
    insert(tree, 3);
    insert(tree, 7);
    insert(tree, 6);
    insert(tree, 9);
    insert(tree, 8);
    insert(tree, 10);
    
    //traversal(tree);
    
    /* // Search 
    treeNode* temp = search(tree, 11);
    if(temp!=NULL){
        cout<<11<<" found"<<endl;
    }

    temp = search(tree, 3);
    if(temp!=NULL){
        cout<<3<<" found"<<endl;
    }
    */

    /* //Removing a node
    bool a = remove(tree, 5);
    cout<<a<<endl;
    traversal(tree);
    */

    //cout<<find_minimum(tree)->item<<endl;
    //cout<<find_maximum(tree)->item<<endl;
}