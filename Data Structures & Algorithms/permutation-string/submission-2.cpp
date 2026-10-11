class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        array<int, 26> s1map = {0};
        for (char c: s1){
            s1map[c - 'a']++;
        }
        int ptr1 = 0;
        for (int ptr2 = s1.size(); ptr2 <= s2.size(); ptr1++, ptr2++){
            if (s2map(s2, ptr1, ptr2) == s1map){
                return true;
            }
        }
        return false;
        
    }
    array<int, 26> s2map(string s2, int left, int right){
        array<int, 26> s2map = {0};
        for (int i = left; i < right; i++){
            s2map[s2[i] - 'a']++;
        }
        return s2map;
    }
};
