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
    std::vector<std::vector<int>> verticalTraversal(TreeNode* root) {
        // Vector to store tuples of {col, row, val}
        std::vector<std::tuple<int, int, int>> nodes;
        
        // Queue stores {node, col, row}
        std::queue<std::tuple<TreeNode*, int, int>> q;
        if (root) {
            q.push({root, 0, 0});
        }
        
        while (!q.empty()) {
            auto [node, col, row] = q.front();
            q.pop();
            
            nodes.push_back({col, row, node->val});
            
            if (node->left) {
                q.push({node->left, col - 1, row + 1});
            }
            if (node->right) {
                q.push({node->right, col + 1, row + 1});
            }
        }
        
        // Sort tuples: automatically compares by col first, then row, then val
        std::sort(nodes.begin(), nodes.end());
        
        std::vector<std::vector<int>> result;
        if (nodes.empty()) return result;
        
        int prevCol = INT_MIN;
        for (const auto& [col, row, val] : nodes) {
            if (col != prevCol) {
                result.push_back({});
                prevCol = col;
            }
            result.back().push_back(val);
        }
        
        return result;
    }
};