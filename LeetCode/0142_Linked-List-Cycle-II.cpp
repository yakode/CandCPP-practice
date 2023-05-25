class Solution{
public:
    ListNode *detectCycle(ListNode *head){
        ListNode *fast = head, *slow = head;

        while(fast){
            if(!fast->next) return nullptr;

            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow) break;
        }
        if(!fast) return nullptr;

        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};
