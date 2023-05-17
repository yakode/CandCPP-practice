// stack
class Solution{
public:
    int pairSum(ListNode* head){
        int n = 0;
        int maxSum = 0;
        ListNode *ptr = head;
        stack<int> s;

        // count the size of linked-list
        while(ptr != nullptr){
            ptr = ptr->next;
            n++;
        }

        // push node of the first half into stack
        ptr = head;
        for(int i = 0; i < n/2; ++i){
            s.push(ptr->val);
            ptr = ptr->next;
        }

        // calculate each twin sum
        for(int i = 0; i < n/2; ++i){
            if(s.top() + ptr->val > maxSum)
                maxSum = s.top() + ptr->val;
            s.pop();
            ptr = ptr->next;
        }

        return maxSum;
    }
};

// reverse the seond half
class Solution{
public:
    int pairSum(ListNode* head){
        int n = 0;
        int maxSum = 0, twinSum;
        ListNode *ptr = head, *head2, *cur;
        stack<int> s;

        // count the size of linked-list
        while(ptr != nullptr){
            ptr = ptr->next;
            n++;
        }

        // reverse the nodes of the second half
        ptr = head;
        for(int i = 0; i < n/2; ++i){
            ptr = ptr->next;
        }
        head2 = ptr;

        while(ptr->next != nullptr){
            cur = ptr->next;
            ptr->next = ptr->next->next;
            cur->next = head2;
            head2 = cur;
        }

        // calculate each twin sum
        while(head2 != nullptr){
            twinSum = head->val + head2->val;
            if(twinSum > maxSum) maxSum = twinSum;
            head = head->next;
            head2 = head2->next;
        }

        return maxSum;
    }
};
