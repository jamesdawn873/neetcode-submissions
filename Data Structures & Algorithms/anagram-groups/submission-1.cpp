class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<vector<int>, vector<string>> hmap;
        for (string s: strs){
            vector<int> alpha(26, 0) ;
            for (char c : s){
                alpha[c - 'a']++;
            }
            hmap[alpha].push_back(s);
        }
        for (auto&[key, group]: hmap){
            result.push_back(group);
        }
        return result;
    }
};
