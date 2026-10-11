class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        int min_size = 1e9;
        int start_idx = 0;
        int left = 0, right = 0;
        unordered_map<char, int> hash_map;
        unordered_map<char, int> sstring_map;
        for (int i = 0; i < t.size(); i++){
            sstring_map[t[i]]++;
        }
        while (right <= s.size()){
            if (has_sstring(hash_map, sstring_map)){
                if (min (right - left, min_size) == right - left){
                    start_idx = left;
                }
                min_size = min(right - left, min_size);
                hash_map[s[left]]--;
                left++;
            } else {
                if (right == s.size())
                    right++;
                else 
                    hash_map[s[right++]]++;
            }
        }
        if (min_size == 1e9){
            return "";
        }
        return s.substr(start_idx, min_size);
    }
    bool has_sstring(const unordered_map<char, int>& main, const unordered_map<char, int>& sstring){
        for (auto [c, num]: sstring){
            auto it = main.find(c);
            if (it == main.end() || (it ->second < num)){
                return false;
            }
        }
        return true;
    }
};
