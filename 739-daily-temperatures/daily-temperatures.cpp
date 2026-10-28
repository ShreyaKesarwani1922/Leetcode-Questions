class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> result(size, 0);
        stack<pair<int, int>> st; // temperature, index

        // if curr_temp > st.top() => find difference and then add to result
        // array and then pop
        for (int i = 0; i < size; i++) {
            int temp = temperatures[i];
            while (!st.empty() && temp > st.top().first) {
                auto pair = st.top();
                result[pair.second] = i - pair.second;
                st.pop();
            }
            st.push({temp, i});
        }

        return result;
    }
};