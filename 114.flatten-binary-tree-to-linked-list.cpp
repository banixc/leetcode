/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	void flatten(TreeNode* root) {
		if(root==NULL) return;
		flatten_end(root);
	}
	
	TreeNode* flatten_end(TreeNode* root) {
		if(root->left == NULL && root->right == NULL) {
			return root;
		} 
		if(root->left == NULL && root->right != NULL) {
			return flatten_end(root->right);
		}
		if(root->left !=NULL && root->right == NULL) {
			root->right = root->left;
			root->left = NULL;
			return flatten_end(root->right);
		}
			TreeNode* lend = flatten_end(root->left);
			TreeNode* rend = flatten_end(root->right);
		lend->right = root->right;
		root->right = root->left;
		root->left = NULL;
		return rend;
	}
};