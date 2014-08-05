#include <iostream>
#include <string>

using namespace std;

// int getHeight(TreeNode* root){
// 	if(root == NULL)
// 		return 0;
// 	return abs(getHeight(root->left), getHeight(root->right)) + 1;
// }

// bool checkBalancedTree(Node* root){
// 	if(root == NULL)
// 		return true;
// 	int diff = getHeight(root->left) - getHeight(root->right);
// 	if(abs(diff) > 1){
// 		return false;
// 	}else{
// 		return checkBalancedTree(root->left) && checkBalancedTree(root->right);
// 	}

// }
/*above is not an efficient method, course every node is touch per node above it*/

int checkHeight(TreeNode* root){
	if(root == NULL){
		return 0;
	}
	/*check if left node is balanced*/
	int leftHeight = checkHeight(root->left);
	if(leftHeight == -1){
		return -1;
	}
	/*check if right node is balanced*/
	int rightHeight = checkHeight(root->right);
	if(rightHeight == -1){
		return -1;
	}

	if(abs(leftHeight - rightHeight) > 1){
		return -1;
	}else{
		return max(leftHeight, rightHeight) + 1;
	}
}

bool isBalanced(TreeNode* root){
	if(checkHeight(root) == -1){
		return false;
	}else{
		return true;
	}

}