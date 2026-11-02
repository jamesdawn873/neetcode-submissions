class KthLargest {
public:
    priority_queue<int, vector<int>, std::greater<int>> min_heap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i: nums){
            add(i);
        }

    }
    
    int add(int val) {
        min_heap.push(val);
        if (min_heap.size() > k){
            min_heap.pop();
        }
        return min_heap.top();
    }
};
