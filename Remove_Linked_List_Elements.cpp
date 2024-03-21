class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
        return NULL;
        head->next=removeElements(head->next,val);
        if(head->val == val){
            ListNode* nextNode = head->next;
            delete head;
            return nextNode;
        }
        return head;
    }
};