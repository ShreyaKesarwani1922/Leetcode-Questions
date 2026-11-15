class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if (!root) return answer;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size); // Pre-allocate size

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // Calculate index based on current level's direction
                int index = leftToRight ? i : (size - 1 - i);
                level[index] = curr->val;

                // Always push children left-to-right
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            leftToRight = !leftToRight; // Flip once per level
            answer.push_back(level);
        }
        return answer;
    }
};