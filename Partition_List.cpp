class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* before_head = nullptr;
        ListNode* after_head = nullptr;
        ListNode* before = nullptr;
        ListNode* after = nullptr;

        while(head){
            if(head->val < x){
                if(!before){
                before = head;
                before_head = before;
            }
            else{
                before->next = head;
                before = before->next;
            }
        }
        else{
            if(!after){
                after = head;
                after_head = after;
                }else{
                    after->next = head;
                    after = after->next;
                }
                }
                head = head->next;
                }
               if(before) {
                before->next = after_head;
               }
               if(after){
                after->next = nullptr;
               }
               return before_head ? before_head : after_head;
               }
};