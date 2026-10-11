class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int max = *max_element(piles.begin(), piles.end());
       int min = 1;
       int ans;
       while (max >= min){
            int midk = (min + max) / 2;
            if (possible_in_time(piles, midk, h)){
                ans = midk;
                max = midk - 1 ;
            } else {
                min = midk + 1;
            }
       } 
       return ans;
    }
    bool possible_in_time(vector<int>& piles, int k, int h){
        int count = 0;
        for (int pile: piles){
            count += (pile / k) + (pile % k != 0);
        }
        return count <= h;
    }
};
