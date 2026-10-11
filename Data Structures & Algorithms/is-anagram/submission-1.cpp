class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> counts;
        unordered_map<char, int> countt;

        if (s.length() != t.length()){
            return false;
        }

        for (int i = 0; i < s.length(); i++){
            counts[s[i]]++;
            countt[t[i]]++;
        } 
        return counts == countt;
    }
};
