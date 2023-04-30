class Solution {
public:
    ListNode* merge2Lists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        if(list1->val < list2->val){
            list1->next = merge2Lists(list1->next, list2);
            return list1;
        }else{
            list2->next = merge2Lists(list1, list2->next);
            return list2;
        }

        return nullptr;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if(n == 0) return nullptr;

        int d = 1;

        while(n > 1){
            for(int i = 0; i < lists.size()-d; i = i + d*2){
                lists[i] = merge2Lists(lists[i], lists[i+d]);
                n--;
            }
            d <<= 1;
        }

        return lists[0];
    }
};
