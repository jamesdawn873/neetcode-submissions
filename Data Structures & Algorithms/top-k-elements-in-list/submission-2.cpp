class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hmap;
        unordered_map<int, vector<int>> freq;
        for (int number: nums){
            hmap[number]++;
        }
        for (auto &[c, n]: hmap){
            freq[n].push_back(c);
        }
        vector<int> result;
        for (int i = nums.size();i >= 1; i--){
            if (freq.find(i) != freq.end()){
                for (int number : freq[i]){
                    result.push_back(number);
                    if (result.size() == k){
                        return result;
                    }
                }
            }
        }
        return vector<int>{};
    }
};
