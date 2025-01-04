#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *insert(struct node *root, int data);
struct node *search(struct node *root, int data);
struct node *delete(struct node *root, int data);
void display(struct node *root);

void main() {
    struct node *root = NULL; 
    int op, data;

    do {
        printf("\nBST Operations");
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit");
        printf("\nYour choice: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(root, data))
                    printf("Item found\n");
                else
                    printf("Item not found\n");
                break;

            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;

            case 4:
                printf("Tree traversal (In-order): ");
                display(root);
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid option! Try again.\n");
        }
    } while (1);
}

struct node *insert(struct node *root, int data) {
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = data;
    t->left = t->right = NULL;

    if (root == NULL) {
        return t;
    }

    struct node *current = root, *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else if (data > current->data) {
            current = current->right;
        } else {
            printf("Duplicate element not allowed\n");
            free(t);
            return root;
        }
    }

    if (data < parent->data) {
        parent->left = t;
    } else {
        parent->right = t;
    }

    return root;
}

struct node *search(struct node *root, int data) {
    while (root != NULL && root->data != data) {
        if (data < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return root;
}

struct node *delete(struct node *root, int data) {
    if (root == NULL) {
        printf("Node not found\n");
        return root;
    }

    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
       
        if (root->left == NULL && root->right == NULL) {
            
            free(root);
            return NULL;
        } else if (root->left == NULL || root->right == NULL) {
            
            struct node *temp = (root->left != NULL) ? root->left : root->right;
            free(root);
            return temp;
        } else {
            
            struct node *successorParent = root;
            struct node *successor = root->right;

            while (successor->left != NULL) {
                successorParent = successor;
                successor = successor->left;
            }

            root->data = successor->data;

            if (successorParent->left == successor) {
                successorParent->left = successor->right;
            } else {
                successorParent->right = successor->right;
            }

            free(successor);
        }
    }

    return root;
}

void display(struct node *root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}
