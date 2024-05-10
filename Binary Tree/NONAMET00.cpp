#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int value;          // Dữ liệu lưu trữ trong nút
    TreeNode* left;     // Con trỏ tới nút con bên trái
    TreeNode* right;    // Con trỏ tới nút con bên phải

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* insertNode(TreeNode* root, int data) {
    if (root == nullptr) {
        return new TreeNode(data);
    }

    if (data < root->value) {
        root->left = insertNode(root->left, data);
    } else if (data > root->value) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void preorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        cout << root->value << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->value << " ";
        inorderTraversal(root->right);
    }
}

void postOrderTraversal(TreeNode* root) {
    if (root != nullptr) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->value << " ";
    }
}

int main() {
    TreeNode* root = nullptr;
    root = insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 4);
    insertNode(root, 6);
    insertNode(root, 8);

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
