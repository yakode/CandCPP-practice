class Solution{
public:
    ListNode* deleteDuplicates(ListNode *head){
        ListNode *dummy = new ListNode(101, head);
        ListNode *ptr = dummy;

        while(ptr && ptr->next && ptr->next->next){
            if(ptr->next->val == ptr->next->next->val){
                while(ptr->next && ptr->next->next && ptr->next->val == ptr->next->next->val){
                    ptr->next = ptr->next->next;
                }
                ptr->next = ptr->next->next;
            }else{
                ptr = ptr->next;
            }  
        }

        return dummy->next;
    }
};
