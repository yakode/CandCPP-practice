class Solution{
public:
    ListNode* middleList(ListNode *head){
        ListNode *slow = head, *fast = head;

        while(fast && fast->next){
            fast = fast->next->next;
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

    bool isPalindrome(ListNode *head){
        ListNode *head2 = reverseList(middleList(head));

        while(head && head2){
            if(head->val != head2->val) return false;
            head = head->next;
            head2 = head2->next;
        }
        
        return true;
    }
};
