class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;

        ListNode tmp(-1, head);
        ListNode *pre = &tmp, *ptr = head;

        if(head->next) head = head->next;

        while(ptr && ptr->next){
            // from 0->1->2->3
            //   to 0->2->1->3
            // pre->0
            // ptr->1

            pre->next = ptr->next;
            // 0->2->3, 1->2->3

            ptr->next = ptr->next->next;
            // 0->2->3, 1->3

            pre->next->next = ptr;
            // 0->2->1->3

            pre = ptr;
            ptr = ptr->next;
            // pre->1
            // ptr->3
        }
        
        return head;
    }
};
