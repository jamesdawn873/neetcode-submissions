class Solution {
public:
    bool isValid(string s) {
        stack<int> stc; 
        unordered_map<char, char> cmap = {{')', '('}, {'}', '{'}, {']', '['}};
        for (char c: s){
            if (c == '(' || c == '{' || c == '['){
                stc.push(c);
            } else {
                if (stc.empty()) return false;
                if (stc.top() != cmap[c]) return false;
                stc.pop();
            }
        }
        if (!stc.empty()) return false;
        return true;
    }
};
