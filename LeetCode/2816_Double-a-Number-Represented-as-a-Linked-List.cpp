class Solution{
    ListNode* reverse(ListNode *head){
        ListNode *ptr = nullptr, *tmp;
        while(head){
            tmp = new ListNode(head->val, ptr);
            ptr = tmp;
            head = head->next;
        }
        return ptr;
    }

public:
    ListNode* doubleIt(ListNode *head){
        ListNode *head2 = reverse(head), *ans;
        ListNode* ptr = head2, *prev = nullptr;
        int c = 0;
        
        while(ptr){
            ptr->val = ptr->val * 2 + c;
            c = ptr->val / 10;
            ptr->val %= 10;
            prev = ptr;
            ptr = ptr->next;
        }
        
        ans = reverse(head2);
        if(c > 0){
            ptr = new ListNode(c, ans);
            ans = ptr;
        }
            
        return ans;
    }
};
