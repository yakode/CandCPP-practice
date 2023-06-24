class Solution{
public:
    ListNode* middleNode(ListNode *head){
        ListNode *slow = head, *fast = head;

        while(fast){
            fast = fast->next;
            if(!fast) return slow;
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};
