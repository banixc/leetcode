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
	bool isCompleteTree(TreeNode* root) {
		queue<TreeNode*> q;
		q.push(root);
		bool flag = false;
		while(!q.empty()) {
			TreeNode* r = q.front();
			q.pop();
			if(r==NULL) {
				flag = true;
			} else {
				if(flag) return false;
				q.push(r->left);
				q.push(r->right);
			}

		}
		return true;
	}
};