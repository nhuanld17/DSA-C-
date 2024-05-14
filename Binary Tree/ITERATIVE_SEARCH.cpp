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

int main(){
	TreeNode* root = nullptr;
	createTree(root);
	
	cout << "Preorder: " << endl;
	preOrderTraversal(root);
	
	int x;
	cout << "Nhap gia tri can tim kiem: " << endl;
	cin >> x;
	TreeNode* result = Iterative_Search(root, x);
	
	if(result != nullptr){
		cout << x << " was found in Tree" << endl;
	}else {
		cout << "Not found" << endl;
	}
	return 0;
}
