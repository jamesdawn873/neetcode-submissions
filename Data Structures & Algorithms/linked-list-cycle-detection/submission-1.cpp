/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
       ListNode * slowptr = head;
       ListNode * fastptr = head;
       if (!head) return false;
       while (slowptr && fastptr){
            fastptr = fastptr -> next;
            slowptr = slowptr -> next;
            if (fastptr == nullptr || fastptr->next == nullptr) {
                return false;
            } 
            fastptr = fastptr->next;
            if (fastptr->val == slowptr->val){
                return true;
            }
       }
       return false;
    }
};
