class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* Next=NULL;
        while(head){
            Next=head->next;
            head->next=prev;            
            prev=head;   
            head=Next;
        }
        head=prev;
        return head;
    }
};