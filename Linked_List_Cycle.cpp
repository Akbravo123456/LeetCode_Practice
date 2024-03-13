class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)
        return false;
        ListNode *slow = head;
        ListNode *fast = head;
        do{
            if(fast == NULL || fast->next == NULL){
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }while(slow != fast);
        return true;
    }
};