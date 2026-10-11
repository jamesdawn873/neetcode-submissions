class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> char_count;
        int left = 0;
        int longest_substring = 0;
        for (int right = 0; right < s.size(); ){
            if (char_count[s[right]] == 0){
                char_count[s[right]]++;
                right++;
                longest_substring = max(longest_substring, right - left);
            } else {
                while(s[left] != s[right]){
                    char_count[s[left]]--;
                    left++;
                }
                char_count[s[left]]--;
                left++;
            }
        }
        return longest_substring;
    }
};
