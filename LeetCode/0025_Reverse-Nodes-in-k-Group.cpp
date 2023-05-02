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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;
        if(k == 1) return head;

        ListNode *ptr1 = head, *ptr2 = head;

        // check if there are at least k node
        for(int i = 0; i < k-1; ++i){
            if(ptr2) ptr2 = ptr2->next;
            else return head;
        }
        if(!ptr2) return head;

        // update the head
        head = ptr2;
        ptr2 = ptr2->next;

        // reverse the middle part of k nodes
        ListNode *pre = ptr1, *ptr, *next;
        ptr = pre->next;
        next = ptr->next;
        for(int i = 0; i < k-1; ++i){
            ptr->next = pre;
            pre = ptr;
            ptr = next;
            if(next) next = next->next;
        }

        //update the next pointer of thelast ndoe
        ptr1->next = reverseKGroup(ptr2, k);
        
        return head;
    }
};
