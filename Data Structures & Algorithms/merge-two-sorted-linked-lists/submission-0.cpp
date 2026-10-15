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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * result = nullptr;
        ListNode * resulthead = nullptr;
        ListNode * l1 = list1;
        ListNode * l2 = list2;

        if ((l1 == nullptr )&& (l2 == nullptr)) return nullptr;
        else if ((l1 == nullptr) && (l2)) return l2;
        else if ((l2 == nullptr) && l1) return l1;
        else {
            if (l1->val > l2->val){
                result = new ListNode(l2->val);
                resulthead = result;
                l2 = l2->next;
            } else {
                result = new ListNode(l1->val);
                resulthead = result;
                l1 = l1->next;
            }
        }

        while (l1 || l2){
            if (l1 && l2){
                if (l1->val > l2->val){
                    result->next = l2;
                    l2= l2->next;
                    result = result->next;
                } else {
                    result->next = l1;
                    l1 = l1->next;
                    result = result->next;
                }
            } else if (l1 && !l2){
                result->next = l1;
                break;
            } else if (l2 && !l1){
                result->next = l2;
                break;
            }
        }
        return resulthead;
    }
};
