/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution{
public:
    ListNode* swapNodes(ListNode* head, int k){
        ListNode *kleft, *kright, *tmp;
        
        tmp = head;
        for(int i = 0; i < k; ++i){
            kleft = tmp;
            tmp = tmp->next;
        }
        kright = head;
        while(tmp != nullptr){
            tmp = tmp->next;
            kright = kright->next;
        }

        swap(kleft->val, kright->val);

        return head;
    }
};
