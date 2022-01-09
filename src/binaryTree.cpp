#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

struct LNode {
    int index;
    struct Node* node;
    struct LNode* next;
};

struct LNode* enqueue(struct LNode** headptr, struct Node* node, int index) {
    struct LNode* head = *headptr;

    struct LNode* newLNode = (struct LNode*)malloc(sizeof(struct LNode));
    newLNode->index = index;
    newLNode->node = node;
    newLNode->next = NULL;

    if (head == NULL) {
        head = newLNode;
    } else {
        struct LNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newLNode;
    }
    return head;
}

struct LNode* dequeue(struct LNode** headptr) {
    struct LNode* head = *headptr;

    if (head == NULL) {
        printf("List is empty!\n");
    } else {
        struct LNode* temp = head;
        head = head->next;
        free(temp);
    }

    return head;
}

struct LNode* getTop(struct LNode** headptr) {
    struct LNode* temp = *headptr;

    struct LNode* top = (struct LNode*)malloc(sizeof(struct LNode));
    top->node = temp->node;
    top->index = temp->index;
    top->next = temp->next;

    return top;
}

void displaySinglyLinkedList(struct LNode** headptr) {
    struct LNode* head = *headptr;

    if (head == NULL) {
        printf("\nList is empty!\n");
    } else {
        struct LNode* temp = head;
        while (temp->next != NULL) {
            printf("%d(%d) -> ", temp->node->data, temp->index);
            temp = temp->next;
        }
        printf("%d(%d) -> NULL\n", temp->node->data, temp->index);
    }
}

struct Node* insert() {
    int n;
    scanf("%d", &n);

    if (n == -1)
        return NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = n;
    newNode->left = insert();
    newNode->right = insert();

    return newNode;
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void levelorder(struct Node* root, int level) {
    if (level == 1)
        printf("%d ", root->data);

    if (level > 1) {
        levelorder(root->left, level - 1);
        levelorder(root->right, level - 1);
    }
}

int getHeight(struct Node* node) {
    return node == NULL ? -1 : 1 + max(getHeight(node->left), getHeight(node->right));
}

void topView(struct Node* root) {
    int arr[200];
    for (int i = 0; i < 200; i++)
        arr[i] = -1;

    struct LNode* front = NULL;
    front = enqueue(&front, root, 100);
    arr[100] = root->data;

    struct LNode* tempFront = NULL;
    struct Node* rFront = NULL;
    int index;

    while (front != NULL) {
        tempFront = getTop(&front);
        front = dequeue(&front);

        rFront = tempFront->node;
        index = tempFront->index;
        arr[index] = rFront->data;

        if (rFront->left != NULL && arr[index - 1] == -1)
            front = enqueue(&front, rFront->left, index - 1);
        if (rFront->right != NULL && arr[index + 1] == -1)
            front = enqueue(&front, rFront->right, index + 1);

        free(tempFront);
    }

    for (int i = 0; i < 200; i++) {
        if (arr[i] != -1)
            printf("%d ", arr[i]);
    }
    printf("\n");
}

struct Node* lowestCommonAncestor(struct Node* root, int node1, int node2) {
    if (root == NULL)
        return NULL;

    if (root->data == node1 || root->data == node2)
        return root;

    struct Node* left = lowestCommonAncestor(root->left, node1, node2);
    struct Node* right = lowestCommonAncestor(root->right, node1, node2);

    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    return root;
}

void deleteBinaryTree(struct Node** rootptr) {
    struct Node* root = *rootptr;
    if (root == NULL)
        return;

    deleteBinaryTree(&root->left);
    deleteBinaryTree(&root->right);
    free(root);
}

void updateArr(vector<vector<int>>& arr, struct Node* node, int row, int left, int right) {
    if (node == NULL)
        return;

    int mid = (left + right) / 2;
    arr[row][mid] = node->data;
    updateArr(arr, node->left, row + 1, left, mid - 1);
    updateArr(arr, node->right, row + 1, mid + 1, right);
}

void showTree(vector<vector<int>>& arr, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (arr[i][j] == 0)
                printf("  ");
            else
                printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Node *root = insert();

    int height = getHeight(root);
    int width = ((height + 1) * (height + 1)) - 1;

    vector<vector<int>> arr(height + 1, vector<int>(width, 0));
    updateArr(arr, root, 0, 0, width - 1);

    printf("\nTree Representation:\n");
    showTree(arr, height + 1, width);

    printf("\nHeight of the tree: %d\n", height);

    printf("\nPreorder traversal:\n");
    preorder(root);

    printf("\n\nInorder traversal:\n");
    inorder(root);

    printf("\n\nPostorder traversal:\n");
    postorder(root);

    printf("\n\nLevel order traversal:\n");
    for (int h = 1; h <= height + 1; h++)
        levelorder(root, h);

    printf("\n\nTop View:\n");
    topView(root);

    int node1, node2;
    scanf("%d", &node1);
    scanf("%d", &node2);

    int lca = lowestCommonAncestor(root, node1, node2)->data;
    printf("\nLowest common ancestor of %d and %d is %d\n", node1, node2, lca);

    deleteBinaryTree(&root);

    return 0;
}
