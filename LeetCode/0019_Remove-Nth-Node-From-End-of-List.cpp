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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr1 = head, *ptr2 = head, *pre = nullptr;

        while(n--) ptr1 = ptr1->next;

        while(ptr1){
            pre = ptr2;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        // delete ptr2
        // ... ptr2 ...
        // ... ptr2
        // ptr2 ...
        // ptr2

        if(pre) pre->next = ptr2->next;
        else head = ptr2->next;

        return head;
    }
};
