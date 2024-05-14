#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
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
	
	if(data < root->value){
		root->left = insertNode(root->left, data);
	}else if (data > root->value){
		root->right = insertNode(root->right, data);
	}
	
	return root;
}

void insertNode_(TreeNode* &root, int data){
	if(root == nullptr){
		root = new TreeNode(data);
		return;
	}
	
	if(data < root->value){
		insertNode_(root->left, data);
	}else if(data > root->value){
		insertNode_(root->right, data);
	}
}

void createTree(TreeNode* &root){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int data;
		cout << "Nhap gia tri cho node moi: " << endl;
		cin >> data;
		insertNode_(root, data);
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

int main(){
	TreeNode* root = nullptr;
	createTree(root);
	
	cout << "Preoder: " << endl;
	preOrderTraversal(root);
	cout << endl;
	cout << "Inorder: " << endl;
	inOrderTraversal(root);
	cout << endl;
	cout << "Postoder: " << endl;
	postOrderTraversal(root);
	cout << endl;
	return 0;
}
