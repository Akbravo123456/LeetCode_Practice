class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        int len=0;
        ListNode* temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        if(k==len) return head;
        int new_k=k%len;
        temp=head;
        while(temp->next){
            temp=temp->next;
        }
        ListNode* last_node=temp;
        int index=len-new_k;
        temp=head;
        ListNode* new_last;
        int var=0;
        while(temp){
            var++;
            if(var==index){
                last_node->next=head;
                head=temp->next;
                temp->next=NULL;
                return head;
            }
            temp=temp->next;
        }
        return head;
    }
};