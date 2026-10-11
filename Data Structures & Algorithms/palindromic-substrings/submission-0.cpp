class Solution {
public:
    int countSubstrings(string s) {
        int sscount = 0;
        if (s.size() == 1) return 1;
        for (int i = 0; i < s.size(); i++){
            int right = i, left = i;
            while ((left >= 0) && right < s.size() && (s[right] == s[left])){
                sscount++;
                right++, left--;
            }
        }
        for (int i = 0; i + 1 < s.size(); i++){
            int right = i+1, left =i;
            while (left >= 0 && right < s.size() && s[right]==s[left]){
                left--, right++;
                sscount++;
            }
        }
        return sscount;
    }
};
