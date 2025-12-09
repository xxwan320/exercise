class Solution {
    string build(const string& str) {
        string st;
        for (char c : str) {
            if (c == '#') {
                if (!st.empty()) st.pop_back();
            } else {
                st.push_back(c);
            }
        }
        return st;
    }

public:
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
};