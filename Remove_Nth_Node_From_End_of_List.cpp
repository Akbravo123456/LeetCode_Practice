class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;
        ListNode* nth = dummy;

        for (int i = 0; i < n + 1; ++i) {
            current = current->next;
        }

        while (current != nullptr) {
            current = current->next;
            nth = nth->next;
        }

        ListNode* temp = nth->next;
        nth->next = nth->next->next;
        delete temp;

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
