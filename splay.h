#include<bits/stdc++.h>
#include "Node.h"
using namespace std;


class SPLAY{
    public:
node *rightRotate(node *x)//zig rotation
{
    node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}


node *leftRotate(node *x)//zag rotation
{
    node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}


node *splay(node *root, int key)
{

    if (root == NULL || root->key == key)
        return root;

    // Key lies in left subtree
    if (root->key > key)
    {
        // Key is not in tree
        if (root->left == NULL) return root;


        if (root->left->key > key)// Zig-Zig
        {
            root->left->left = splay(root->left->left, key);


            root = rightRotate(root);
        }
        else if (root->left->key < key) // Zig-Zag
        {
            root->left->right = splay(root->left->right, key);


            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        return (root->left == NULL)? root: rightRotate(root);
    }
    else
    {

        if (root->right == NULL) return root;

        if (root->right->key > key)// Zig-Zag
        {
            root->right->left = splay(root->right->left, key);

            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        else if (root->right->key < key)// Zag-Zag
        {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }


        return (root->right == NULL)? root: leftRotate(root);
    }
}


node *insert(node *root, int k)
{

    if (root == NULL)
        return root = new node(k);


    root = splay(root, k);


    if (root->key == k) return root;

    node *newnode = new node(k);

    if (root->key > k)
    {
        newnode->right = root;
        newnode->left = root->left;
        root->left = NULL;
    }

    else
    {
        newnode->left = root;
        newnode->right = root->right;
        root->right = NULL;
    }

    return newnode;
}

node *search(node *root, int key)
{
    return splay(root, key);
}


 node* delete_key(node *root, int key)
{
    struct node *temp;
    if (!root)
        return NULL;

    // Splay the given key
    root = splay(root, key);

    //key is not present
    if (key != root->key)
        return root;


    // If key is present
    if (!root->left)
    {
        temp = root;
        root = root->right;
    }

    // Else if left child exits
    else
    {
        temp = root;

        root = splay(root->left, key);

        // Make right child of previous root  as
        // new root's right child
        root->right = temp->right;
    }

    free(temp);

    return root;

}


void preOrder(node *root)
{
    if (root != NULL)
    {
        cout<<root->key<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}


};
