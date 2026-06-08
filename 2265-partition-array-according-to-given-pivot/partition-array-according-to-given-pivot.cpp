class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;

        // 1st pass: elements < pivot
        for (int x : nums) {
            if (x < pivot) {
                ans.push_back(x);
            }
        }

        // 2nd pass: elements == pivot
        for (int x : nums) {
            if (x == pivot) {
                ans.push_back(x);
            }
        }

        // 3rd pass: elements > pivot
        for (int x : nums) {
            if (x > pivot) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};