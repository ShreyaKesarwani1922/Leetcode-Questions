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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> answer;

        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> q;

        if (root == NULL) return answer;
        q.push(make_pair(root, make_pair(0,0)));

        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            

            nodes[hd][lvl].insert(frontNode->val);
            if(frontNode->left) {
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
            }
            if (frontNode->right) {
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
            }
        }
        for (auto& [hd, lvlMap] : nodes) {
            vector<int> col;
            for (auto& [lvl, vals] : lvlMap) {
                col.insert(col.end(), vals.begin(), vals.end());
            }
            answer.push_back(move(col));
        }
        return answer;
    }
};