class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap;
        for (int stone: stones){
            max_heap.push(stone);
        }
        while (max_heap.size() > 1){
            int first = max_heap.top();
            max_heap.pop();
            int second = max_heap.top();
            max_heap.pop();
            int diff = abs(first - second);
            max_heap.push(diff);

        }
        return max_heap.size() > 0 ? max_heap.top() : 0;
    }
 };
