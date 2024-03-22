class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      if(!head || k == 1)
      return head;
      ListNode* current = head;
      ListNode* prevTail = NULL;

      while(current){
        int count=0;
        ListNode* ghead = current;
        ListNode* next = NULL;
        ListNode* prev = NULL; 

      while(current && count < k){
        current = current->next;
        count++;
      }

      if(count < k){
        if(prevTail)
        prevTail->next=ghead;
        break;
      } 
      
      current = ghead;
      while(count--){
        next = current -> next;
        current->next=prev;
        prev = current;
        current = next;
      }
      if(prevTail)
      prevTail->next = prev;
      else
      head=prev;
      prevTail = ghead;
    }
    return head;
    }
};