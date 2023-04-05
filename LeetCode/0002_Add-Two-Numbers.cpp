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
        ListNode *ptr = new ListNode(0);
        ListNode *ans = ptr, *prev = nullptr; 
        int c = 0;  // carry
        while(l1 && l2){
            c = c + l1->val + l2->val;
            ptr->val = c % 10;
            if(c > 0) c /= 10;
            ptr->next = new ListNode(0);
            prev = ptr;
            ptr = ptr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            c = c + l1->val;
            ptr->val = c % 10;
            if(c > 0) c /= 10;
            ptr->next = new ListNode(0);
            prev = ptr;
            ptr = ptr->next;
            l1 = l1->next;
        }
        while(l2){
            c = c + l2->val;
            ptr->val = c % 10;
            if(c > 0) c /= 10;
            ptr->next = new ListNode(0);
            prev = ptr;
            ptr = ptr->next;
            l2 = l2->next;
        }
        ptr->val = c;
        if(ptr->val == 0 && prev != nullptr) prev->next = nullptr;
        return ans;
    }
};
