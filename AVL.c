#include <stdio.h>
#include <stdlib.h>
struct avlnode {
int data;
struct avlnode *left;
struct avlnode *right;
int height;
};
typedef struct avlnode*NODE;
NODE root = NULL;
NODE createnode(int key){
NODE newnode = (NODE)malloc(sizeof(struct avlnode));
newnode->data = key;
newnode->left = NULL;
newnode->right = NULL;
newnode->height = 1;
return newnode;
}
int getHeight(NODE n){
if(n== NULL)
return 0;
return n->height;
}
int max(int a, int b){
return(a > b) ?a:b;
}
void updateHeight(NODE node) {
if (node != NULL)
node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}
NODE rightRotation(NODE y) {
NODE x = y->left;
NODE t2 = x->right;
x->right = y;
y->left = t2;
updateHeight(y);
updateHeight(x);
return x;
}
NODE leftRotation(NODE x){
NODE y = x->right;
NODE t2 = y->left;
y->left = x;
x->right = t2;
updateHeight(x);
updateHeight(y);
return y;
}
void inOrder(NODE root, FILE *outputFile) {
if (root != NULL) {
inOrder(root->left, outputFile);
printf("%d ", root->data);
if (outputFile != NULL)
fprintf(outputFile, "%d ", root->data);
inOrder(root->right, outputFile);
}
}
int getBalfactor(NODE n) {
if (n == NULL)
return 0;
return (getHeight(n->left) - getHeight(n->right));
}
NODE balanceTree(NODE node, int key){
int balance = getBalfactor(node);
if(balance > 1 && key < node->left->data)
return rightRotation(node);
if (balance < -1 && key > node->right->data)
return leftRotation(node);
if (balance > 1 && key > node->left->data) {
node->left = leftRotation(node->left);
return rightRotation(node);
}
if (balance < -1 && key < node->right->data) {
node->right = rightRotation(node->right);
return leftRotation(node);
}
return node;
}
NODE insert(NODE node, int key) {
if (node == NULL)
return createnode(key);
else if (key < node->data)
node->left = insert(node->left, key);
else if (key > node->data)
node->right = insert(node->right, key);
else
return node;
updateHeight(node);
return balanceTree(node, key);
}
NODE minValNode(NODE temp) {
NODE cur = temp;
while (cur->left != NULL) {
cur = cur->left;
}
return cur;
}
NODE deleteNode(NODE root, int key) {
NODE temp;
if (root == NULL)
return root;
if (key < root->data)
root->left = deleteNode(root->left, key);
else if (key > root->data)
root->right = deleteNode(root->right, key);
else {
if (root->left == NULL) {
temp = root->right;
free(root);
return temp;
} else if (root->right == NULL) {
temp = root->left;
free(root);
return temp;
} else {
temp = minValNode(root->right);
root->data = temp->data;
root->right = deleteNode(root->right, temp->data);
}
}
updateHeight(root);
return balanceTree(root, key);
}

int main() {
FILE *inputFile;
int n;
int choice, key;
inputFile = fopen("input.txt", "r");
if (inputFile == NULL) {
fprintf(stderr, "Could not open input file.\n");
return 1;
}

while (fscanf(inputFile, "%d", &n) != EOF) {
root = insert(root, n);
}
fclose(inputFile);
while (1) {
printf("\nAVLTREE operations\n 1.Insert a node\n 2.Delete a node\n 3.Inorder traversal \n 4.Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter the value to insert: ");
scanf("%d", &key);
root = insert(root, key);
break;
case 2:
printf("Enter the value to delete: ");
scanf("%d", &key);
root = deleteNode(root, key);
break;
case 3: {
FILE *outputFile3 = fopen("output.txt", "a");
if (outputFile3 == NULL) {
fprintf(stderr, "Could not open output file.\n");
break;
}
printf("Inorder traversal: ");
inOrder(root, outputFile3);
printf("\n");
fprintf(outputFile3, "\nInorder traversal completed\n\n");
fclose(outputFile3);
break;
}
case 4:
printf("Exiting program.\n");
exit(0);
break;
default:
printf("Invalid choice\n");
}
}
return 0;
}

