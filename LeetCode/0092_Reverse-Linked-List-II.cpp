class Solution{
public:
    ListNode* reverseBetween(ListNode *head, int left, int right){
        if(left == right) return head;

        ListNode *ptr = new ListNode(0, head);
        ListNode *prev = ptr, *cur = head, *next;
        ListNode *ptrl;

        // find left
        for(int i = 0; i < left - 1; ++i){
            prev = cur;
            cur = cur->next;
        }
        ptrl = prev;
        prev = cur;
        cur = cur->next;

        // reverse the nodes from left to right
        for(int i = left; i < right; ++i){
            if(cur == nullptr){
                cout << i;
                return nullptr;
            }
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        // link the left-1 and right+1
        ptrl->next->next = next;
        ptrl->next = prev;

        return ptr->next;
    }
};
