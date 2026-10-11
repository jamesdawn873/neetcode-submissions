class Solution {
public:
    string longestPalindrome(string s) {
        int longestsizess = 0;
        int left = 0, right = 0;
        if (longestsizess < 1){
            longestsizess = 1;
            left = 0;
            right = 0;
        }
        for (int i = 0; i < s.size(); i++){
            int r = i, l = i;
            int size = 1;
            while ((r < s.size()) && (l > 0)){
                l--;
                r++;
                if (s[r] == s[l]){
                    size += 2;
                    if (size > longestsizess){
                        right = r;
                        left = l;
                        longestsizess = size;
                    }
                } else break;
            }
        }
        if (s.size() >= 2){
            for (int i = 0; i < s.size(); i++){
                int r = i + 1, l = i;
                int size;
                if (s[r] == s[l] ){
                    size = 2;
                    if (longestsizess < size){
                        right = r;
                        left = l;
                    }
                } else {
                    continue;
                }
                while ((r < s.size()) && (l > 0)){
                    l--;
                    r++;
                    if (s[r] == s[l]){
                        size += 2;
                        if (size > longestsizess){
                            right = r;
                            left = l;
                            longestsizess = size;
                        }
                    } else break;
                }
            }
        }   
        return s.substr(left, right - left + 1);
        
    }
};
