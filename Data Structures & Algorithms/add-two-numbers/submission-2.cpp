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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1ptr = l1;
        ListNode* l2ptr = l2;
        ListNode *res = new ListNode(0);
        ListNode * head = res;
        int carry = 0;
        while (l1ptr || l2ptr){
            if (!l1ptr){
                int sum = l2ptr->val + carry;
                res->next = new ListNode(sum % 10);
                carry = sum / 10;
                l2ptr= l2ptr->next;
                res = res->next;
            } else if (!l2ptr){
                int sum = l1ptr->val + carry;
                res->next = new ListNode(sum % 10);
                carry = sum / 10;
                l1ptr = l1ptr ->next;
                res = res->next;
            } else if (l1ptr && l2ptr) {
                int sum = l1ptr->val + l2ptr->val + carry;
                carry = sum / 10;   
                res->next = new ListNode(sum % 10);
                res = res->next;
                l1ptr = l1ptr -> next;
                l2ptr = l2ptr->next;
                }
        }
        if (carry){
            res->next = new ListNode(carry);
        }
        return head->next;
    }
};
