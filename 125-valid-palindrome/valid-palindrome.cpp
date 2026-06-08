class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = (int)s.size() - 1;
        while (left < right) {
            if (!(unsigned char)isalnum(s[left])) {
                left++;
            } else if (!(unsigned char)isalnum(s[right])) {
                right--;
            } else {
                // cout << tolower(s[left]) << " " << tolower(s[right]) << endl;
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                } else {
                    left++;
                    right--;
                }
            }
        }
        return true;
    }
};