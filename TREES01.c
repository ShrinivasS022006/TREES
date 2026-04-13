#include<stdio.h>
#include<stdlib.h>

struct tree
{
int data;
struct tree *left;
struct tree *right;
};
typedef struct tree TREE;

TREE *insert_into_bst(TREE*,int);
void inorder(TREE *);
void preorder(TREE *);
void postorder(TREE *);
TREE *delete_from_bst(TREE*, int);

TREE *insert_into_bst(TREE*root,int data)
{
TREE *newnode, *currnode, *parent;
newnode=(TREE*)malloc(sizeof(TREE));
if(newnode==NULL)
{
printf("Memory allocation failed\n");
return root;
}
newnode->data = data;
newnode->left = NULL;
newnode->right = NULL;
if(root == NULL)
{
root = newnode;
printf("Root node inserted into tree\n");
return root;
}
currnode = root;
parent = NULL;
while(currnode != NULL)
{
parent = currnode;
if(newnode->data <currnode->data)
currnode = currnode->left;
else
currnode = currnode->right;
}
if(newnode->data < parent->data)
parent->left = newnode;
else
parent->right = newnode;
printf("Node inserted successfully into the tree\n");
return root;
}
void inorder(TREE *troot)
{
if(troot != NULL)
{
inorder(troot->left);
printf("%d ",troot->data);
inorder(troot->right);
}
}
void preorder(TREE *troot)
{
if(troot != NULL)
{
printf("%d\t",troot->data);
preorder(troot->left);
preorder(troot->right);
}
}
void postorder(TREE *troot)
{
if(troot != NULL)
{
postorder(troot->left);
postorder(troot->right);
printf("%d\t",troot->data);
}
}
TREE* delete_from_bst(TREE*root, int data)
{
TREE *currnode, *parent, *successor, *p;
// Check if the tree is empty
if(root == NULL)
{
printf("Tree is empty\n");
return root;
}
// Traverse and reach the appropriate part of the tree
parent = NULL;
currnode = root;
while (currnode != NULL && data != currnode->data)
{
parent = currnode;
if(data < currnode->data)
currnode = currnode->left;
else
currnode = currnode->right;
}

// If the data is not present in the tree
 if(currnode == NULL)
 {
 printf("Item not found\n");
return root;
}
if(currnode->left == NULL)
p= currnode->right;
else if(currnode->right == NULL)
p = currnode->left;
else
{
successor = currnode->right;
while(successor->left != NULL)
successor = successor->left;
successor->left = currnode->left;
p = currnode->right;
}
if (parent == NULL)
{
free(currnode);
return p;
}
if(currnode == parent ->left)
parent->left = p;
else
parent->right = p;
free(currnode);
return root;
}
int main()
{
TREE*root = NULL;
root=NULL;
int choice = 0;
int data = 0;
int count = 0;
int a,b,c,d,k,q,e,w;

while(1)
{
    printf("\n******** Menu ******** \n");
    printf("1-Insert into BST\n");
    printf("2-Inorder Traversal\n");
    printf("3-Preorder Traversal\n");
    printf("4-Postorder Traversal\n");
    printf("5-Delete from BST\n");
    printf("6-Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insert_into_bst(root, data);
            break;

        case 2:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 4:
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 5:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            root = delete_from_bst(root, data);
            break;

        case 6:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
    }
}
return 0;
}
