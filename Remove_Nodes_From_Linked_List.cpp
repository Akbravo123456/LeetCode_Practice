/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* curr=head;
        stack<ListNode*> stack;

        while(curr!=NULL){
            while (!stack.empty() && stack.top()->val < curr->val){
              stack.pop();  
            }
            stack.push(curr);
            curr= curr->next;
        }
        ListNode* nxt = NULL;
        while (!stack.empty()) {
            curr= stack.top();
            stack.pop();
            curr->next = nxt;
            nxt = curr;
        }
        return curr;
    }
};