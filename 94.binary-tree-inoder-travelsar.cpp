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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> list;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if (node==NULL) {continue;}
            bool flag = node->right == NULL && node->left == NULL;
            if(flag) {
                list.push_back(node->val);
                continue;
            }
            TreeNode* l = node->left;
            node->left = NULL;
            TreeNode* r = node->right;
            node->right = NULL;
            if(r != NULL) {
                s.push(r);
            }
            s.push(node);
            if(l != NULL) {
                s.push(l);
            }

        }
        return list;
    }
};