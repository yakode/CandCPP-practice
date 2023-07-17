class Solution{
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2){
        stack <ListNode*> s1, s2;
        ListNode *ans = nullptr;
        int c = 0;

        while(l1){
            s1.push(l1);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2);
            l2 = l2->next;
        }

        while(!s1.empty() && !s2.empty()){
            int val1, val2, val;
            val1 = s1.top()->val;
            val2 = s2.top()->val;
            val = (val1 + val2 + c) % 10;
            c = (val1 + val2 + c) / 10;
            s1.pop();
            s2.pop();
            ListNode *tmp = new ListNode(val, ans);
            ans = tmp;
        }
        while(!s1.empty()){
            int val = (s1.top()->val + c) % 10;
            c = (s1.top()->val + c) / 10;
            s1.pop();
            ListNode *tmp = new ListNode(val, ans);
            ans = tmp;
        }
        while(!s2.empty()){
            int val = (s2.top()->val + c) % 10;
            c = (s2.top()->val + c) / 10;
            s2.pop();
            ListNode *tmp = new ListNode(val, ans);
            ans = tmp;
            
        }
        if(c > 0){
            ListNode *tmp = new ListNode(c, ans);
            ans = tmp;
        }

        return ans;
    }
};
