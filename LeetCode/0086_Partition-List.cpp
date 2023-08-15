lass Solution{
public:
    ListNode* partition(ListNode *head, int x){
        ListNode *ptr1 = nullptr, *ptr2 = nullptr;
        ListNode *head1 = nullptr, *head2 = nullptr;

        while(head){
            if(head->val < x){
                if(!head1){
                    head1 = head;
                    ptr1 = head;
                }else{
                    ptr1->next = head;
                    ptr1 = head;
                }
                if(ptr2)
                    ptr2->next = nullptr;
            }else{
                if(!head2){
                    head2 = head;
                    ptr2 = head;
                }else{
                    ptr2->next = head;
                    ptr2 = head;
                }
                if(ptr1)
                    ptr1->next = nullptr;
            }
            head = head->next;
        }

        if(ptr1)
            ptr1->next = head2;
        else
            head1 = head2;

        return head1;
    }
};
