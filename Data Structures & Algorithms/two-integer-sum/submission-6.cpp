class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hmap; 
        for (int i = 0; i < nums.size(); i++){
            if (hmap.find(target - nums[i]) != hmap.end())
                return vector<int>{hmap[target - nums[i]], i};
            else {
                hmap[nums[i]] = i;
            }
        }
        return vector<int>{};
    }
};
