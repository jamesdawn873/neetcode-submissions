class Solution {
public:
    int search(vector<int>& nums, int target) {
       int high = nums.size() - 1;
       int lo = 0;
       while (high >= lo){
            int mid = (high + lo) / 2;
            if (nums[mid] == target){
                return mid;
            } else if (nums[mid] <= target){
                lo = mid + 1;
            } else {
                high = mid - 1 ;
            }
       } 
       return -1;
    }
};
