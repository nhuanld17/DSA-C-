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

// Tính chiều cao của cây
int height(TreeNode* root){
	if(root == nullptr){
		return 0;
	}
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	
	if(leftHeight > rightHeight){
		return leftHeight + 1;
	}
	
	return rightHeight + 1;
}

void printGivenLevel(TreeNode* root, int level){
	if(root == nullptr){
		return;
	}
	
	if(level == 1){
		cout << root->value << " ";
	}else if(level > 1){
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level -1);
	}
}

void BFS(TreeNode* root){
	int h = height(root);
	for(int i = 1; i <= h; i++){
		printGivenLevel(root, i);
	}
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
	BFS(root);
	return 0;
}
