class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        while(head != NULL){
            if(head->next != NULL && head->val == head->next->val){
                int duplicateVal = head->val;
                while (head!= NULL && head->val == duplicateVal) {
                    head = head->next;
                }
                prev->next=head;
            }else{
                prev=head;
                head=head->next;
            }
        }
        return dummy->next;
    }
};