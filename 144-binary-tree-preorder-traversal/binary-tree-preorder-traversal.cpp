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
    void preorderRecursive(TreeNode* root, vector<int> &answer) {
        if (root == NULL) {
            return;
        }
        answer.push_back(root->val);
        preorderRecursive(root->left,answer);
        preorderRecursive(root->right,answer);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        preorderRecursive(root, answer);
        return answer;
    }
};