#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
	int value;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(int val) : value(val), left(nullptr), right(nullptr){
	}
};

void Insert_Node(TreeNode* &root, int data){
	if(root == nullptr){
		root = new TreeNode(data);
		return;
	}
	
	if(data < root->value){
		Insert_Node(root->left, data);
	} else if (data > root->value){
		Insert_Node(root->right, data);
	}
}	

void DFS(TreeNode* root){
	if(root == nullptr){
		return;
	}
	
	// In giá trị của nút hiện tại
	cout << root->value << " ";
	
	// Duyệt cây con bên trái
	DFS(root->left);
	
	// Duyệt cây con bên phải
	DFS(root->right);
}
	
int main(){
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(2);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(6);
	
	cout << "DFS: " << endl;
	DFS(root);
	return 0;
}
