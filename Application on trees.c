#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree *left, *right;
};

struct tree* createNode(int val) {
    struct tree *temp=(struct tree*)malloc(sizeof(struct tree));
    temp->data=val;
    temp->left=temp->right=NULL;
    return temp;
}

struct tree* insert(struct tree *root, int val) {
    if (root==NULL)
        return createNode(val);

    if (val<root->data)
        root->left=insert(root->left, val);
    else if (val>root->data)
        root->right=insert(root->right, val);

    return root;
}

struct tree* findMin(struct tree *root) {
    while (root->left!=NULL)
        root=root->left;
    return root;
}

struct tree* deleteNode(struct tree *root, int val) {
    if (root==NULL)
        return NULL;

    if (val<root->data)
        root->left=deleteNode(root->left, val);
    else if (val>root->data)
        root->right=deleteNode(root->right, val);
    else {
        if (root->left==NULL&&root->right==NULL) {
            free(root);
            return NULL;
        }
        else if (root->left==NULL) {
            struct tree *temp=root->right;
            free(root);
            return temp;
        }
        else if (root->right==NULL) {
            struct tree *temp=root->left;
            free(root);
            return temp;
        }
        else {
            struct tree *temp=findMin(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void inorder(struct tree *root) {
    if (root!=NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int n,i,val,insertVal,deleteVal;
    struct tree *root=NULL;

    scanf("%d",&n);

    for (i=0;i<n;i++) {
        scanf("%d",&val);
        root=insert(root, val);
    }

    scanf("%d",&insertVal);
    root=insert(root, insertVal);

    scanf("%d", &deleteVal);
    root=deleteNode(root, deleteVal);

    printf("Current File Index sorted in ascending order: ");
    inorder(root);

    return 0;
}
