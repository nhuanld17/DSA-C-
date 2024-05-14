#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(int val): value(val), left(nullptr), right(nullptr){
	}	
};

TreeNode* insertNode(TreeNode* root, int data){
	if(root == nullptr){
		return new TreeNode(data);
	}
		
	if(data < root->value) {
		root->left = insertNode(root->left, data);
	} else if(data > root->value){
		root->right = insertNode(root->right, data);
	}
	
	return root;
}

void insert(TreeNode* &root, int data){
	if(root == nullptr){
		root = new TreeNode(data);
		return;
	}
	
	if(data < root->value) {
		insert(root->left, data);
	} else if(data > root->value){
		insert(root->right, data);
	}
}

void preOrderTraversal(TreeNode* root){
	if(root != nullptr){
		cout << root->value << " ";
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
	}
}

void inOrderTraversal(TreeNode* root){
	if(root != nullptr){
		inOrderTraversal(root->left);
		cout << root->value << " ";
		inOrderTraversal(root->right);
	}
}

void postOrderTraversal(TreeNode* root){
	if(root != nullptr){
		postOrderTraversal(root->left);
		postOrderTraversal(root->right);
		cout << root->value << " ";
	}
}

void createTree(TreeNode* &root){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int data;
		cout << "Nhap gia tri cua node thu nhat: " << endl;
		cin >> data;
		insert(root, data);
	}
}

TreeNode* Iterative_Search(TreeNode* root, int x){
	while(root != nullptr){
		if(x == root->value){
			return root;
		}
		
		if(x < root->value){
			root = root->left;
		}else {
			root = root->right;
		}
	}
	
	return nullptr;
}

TreeNode* Recursive_Search(TreeNode* root, int x){
	
	if(root != nullptr){
		return nullptr;
	}
	if(x == root->value){
		return root;
	}
	
	if(x < root->value){
		return Recursive_Search(root->left, x);
	}
	
	if(x > root->value){
		return Recursive_Search(root->right, x);
	}
	return nullptr;
}

TreeNode* minValueNode(TreeNode* node){
	TreeNode* current = node;
	while(current && current->left != nullptr){
		current = current->left;
	}
	return current;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return root;
    
    if (key < root->value) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->value) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = minValueNode(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

int main(){
	TreeNode* root = nullptr;
	createTree(root);
	
	cout << "Preorder: " << endl;
	preOrderTraversal(root);
	cout << endl;
	cout << "Inorder: " << endl;
	inOrderTraversal(root);
	cout << endl;
	cout << "PostOrder: " << endl;
	postOrderTraversal(root);
	cout << endl;
	
	cout << "Nhap gia tri can tim trong cay: " << endl;
	int x;
	cin >> x;
	TreeNode* result = Iterative_Search(root, x);
	if(result != nullptr ){
		cout << x << " nam trong cay" << endl;
	}else {
		cout << " Khong tim thay " << x <<endl;
	}
	
	result = Recursive_Search(root, x);
	if(result != nullptr){
		cout << x << " nam trong cay " << endl;
	} else {
		cout << " Khong tim thay " << x << endl;
	}
	
	int key;
	cout << "Nhap gia tri cua node can xoa: " << endl;
	cin >> key;
	
	return 0;
}
