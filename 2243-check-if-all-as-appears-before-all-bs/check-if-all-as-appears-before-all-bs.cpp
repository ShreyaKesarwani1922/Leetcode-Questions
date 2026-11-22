class Solution {
public:
    bool checkString(string s) {
        string a = s;
        sort(a.begin(),a.end());
        if(s == a) {
            return true;
        }
        return false;
    }
};