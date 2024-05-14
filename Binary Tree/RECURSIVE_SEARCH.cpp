#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(int val): value(val), left(nullptr), right(nullptr){
	}	
};

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

TreeNode* Recursive_Search(TreeNode* root, int x){
	if(root == nullptr || root->value == x){
		return root;
	}
	
	if(x < root->value){
		return Recursive_Search(root->left, x);
	}
	
	return Recursive_Search(root->right, x);
	
}

int main(){
	TreeNode* root = nullptr;
	createTree(root);
	
	cout << "Preorder: " << endl;
	preOrderTraversal(root);
	
	int x;
	cout << "Nhap gia tri can tim kiem: " << endl;
	cin >> x;
	TreeNode* result = Recursive_Search(root, x);
	
	if(result != nullptr){
		cout << x << " was found in Tree" << endl;
	}else {
		cout << "Not found" << endl;
	}
	return 0;
}

