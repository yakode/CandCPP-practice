// recursion
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        
        return nullptr;
    }
};

// while loop
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = nullptr, *ptr;

        while(list1 && list2){
            if(list1->val < list2->val){
                if(head == nullptr){
                    head = new ListNode(list1->val);
                    ptr = head;
                }else{
                    ptr->next = new ListNode(list1->val);
                    ptr = ptr->next;
                }
                list1 = list1->next;
            }else{
                if(head == nullptr){
                    head = new ListNode(list2->val);
                    ptr = head;
                }else{
                    ptr->next = new ListNode(list2->val);
                    ptr = ptr->next;
                }
                list2 = list2->next;
            }
        }

        while(list1){
            if(head == nullptr){
                head = new ListNode(list1->val);
                ptr = head;
            }else{
                ptr->next = new ListNode(list1->val);
                ptr = ptr->next;
            }
            list1 = list1->next;
        }

        while(list2){
            if(head == nullptr){
                head = new ListNode(list2->val);
                ptr = head;
            }else{
                ptr->next = new ListNode(list2->val);
                ptr = ptr->next;
            }
            list2 = list2->next;
        }

        return head;
    }
};
