/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int calcHeight(TreeNode* root, int& maxDiameter) {
        if (root == NULL)
            return 0;

        int leftTreeHeight = calcHeight(root->left, maxDiameter);
        int rightTreeHeight = calcHeight(root->right, maxDiameter);

        maxDiameter = max(maxDiameter, leftTreeHeight + rightTreeHeight);
        return max(leftTreeHeight, rightTreeHeight) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        int heightOfTree = calcHeight(root, maxDiameter);
        return maxDiameter;
    }
};