class Solution {
public:
ListNode*middle(ListNode*head){
            ListNode*slow = head;
            ListNode*fast = head;

            while(fast!=NULL && fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
            }
            return slow;
        }
        ListNode*reverse(ListNode*head){
            ListNode*curr=head;
            ListNode*prev=NULL;
            while(curr!=NULL){
                ListNode *next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            return prev;
        }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;

        ListNode*mid = middle(head);
        ListNode*n = reverse(mid->next);
        mid->next=NULL;

        ListNode*n1=head;
        ListNode*n2=n;
        ListNode*n3=NULL;
        ListNode*n4=NULL;

        while(n1!=NULL && n2!=NULL){
            n3=n1->next;
            n4=n2->next;

            n1->next=n2;
            n2->next=n3;

            n1=n3;
            n2=n4;
        }
    }
};