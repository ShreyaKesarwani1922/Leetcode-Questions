/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorderTraversalRecursive(vector<int> &answer, TreeNode* root) {
        if (root== NULL) return;
        
        inorderTraversalRecursive(answer, root->left);
        answer.push_back(root->val);
        inorderTraversalRecursive(answer, root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        inorderTraversalRecursive(answer, root);
        return answer;
    }
};