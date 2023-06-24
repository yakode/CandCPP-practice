class Solution{
public:
    ListNode* middleNode(ListNode *head){
        ListNode *slow = head, *fast = head;

        while(fast){
            fast = fast->next;
            if(!fast) break;
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode *head){
        ListNode *prev = nullptr, *cur = head, *next;

        while(cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }

    void mergeList(ListNode *head, ListNode *head2){
        ListNode *ptr1 = head->next, *ptr2 = head2;
        ListNode *ptr = head;

        while(ptr2){
            ptr->next = ptr2;
            ptr2 = ptr2->next;
            ptr = ptr->next;
            if(ptr1 == ptr2) break;
            ptr->next = ptr1;
            ptr1 = ptr1->next;
            ptr = ptr->next;
        }
        if(ptr2){
            ptr->next = ptr2;
            ptr = ptr->next;
        }
        ptr->next = nullptr;
    }

    void reorderList(ListNode *head){
        if(!head->next) return;
        
        ListNode *head2 = reverseList(middleNode(head));
        mergeList(head, head2);
    }
};
