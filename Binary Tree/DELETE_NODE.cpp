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

TreeNode* Find_Min(TreeNode* root){
	while(root->left != nullptr){
		root = root->left;
	}
	
	return root;
}

TreeNode* Delete_Node(TreeNode* root, int key){
	// Base case
	if(root == nullptr){
		return root;
	}
	
	// Nếu nút cần xóa nhỏ hơn nút gốc của cây
	// thì nút đó nằm ở cây con trái
	if(key < root->value){
		root->left = Delete_Node(root->left, key);
	}else if(key > root->value){
		root->right = Delete_Node(root->right, key);	
	} else {
		// Nút chỉ có 1 con hoặc không có con
		if(root->left == nullptr){
			TreeNode* temp = root->right;
			delete root;
			return temp;
		} else if (root->right == nullptr){
			TreeNode* temp = root->left;
			delete root;
			return temp;
		} 
		
		// Nút có 2 con: lấy nút có giá trị nhỏ nhất ở cây con bên phải
		TreeNode* temp = Find_Min(root->right);
		
		// Copy giá trị của temp vào node hiện tại
		root->value = temp->value;
		
		// Xóa node temp
		root->right = Delete_Node(root->right, temp->value);
	}
	
	return root;
}

int main(){
	TreeNode* root = nullptr;
	createTree(root);
	
	cout << "Preorder: " << endl;
	preOrderTraversal(root);
	
	int key;
	cout << "Nhap gia tri cua node can xoa: " << endl;
	cin >>key;
	root = Delete_Node(root, key);
	
	cout << "After deletion: " << endl;
	preOrderTraversal(root);
	return 0;
}

