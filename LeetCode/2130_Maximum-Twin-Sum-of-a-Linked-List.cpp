// two pointer!
class Solution{
public:
    int pairSum(ListNode* head){
        int maxSum = 0, twinSum;
        ListNode *half1, *half2;
        ListNode *prev, *ptr; 

        // find the head of the second half (head2)
        // half1 is a temperate pointer to find half2
        half1 = head->next;
        half2 = head;
        while(half1->next){
            half1 = half1->next->next;
            half2 = half2->next;
        }
        half1 = head;
        half2 = half2->next;
        
        // reverse the second half of linked list
        prev = half2;
        while(prev->next){
            ptr = prev->next;
            prev->next = prev->next->next;
            ptr->next = half2;
            half2 = ptr;
        }

        // calculate each twin sum
        while(half2){
            twinSum = half1->val + half2->val;
            if(twinSum > maxSum) maxSum = twinSum;
            half1 = half1->next;
            half2 = half2->next;
        }

        return maxSum;
    }
};

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
