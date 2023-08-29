class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        int count = 0;
        if(head == NULL){
            return head;
        }
        // Count the number of nodes in the current group
        while (cur != nullptr && count < k) {
            cur = cur->next;
            count++;
        }

        // If there are at least k nodes, reverse the current group
        if (count == k) {
            cur = head;
            ListNode* prev = nullptr;
            ListNode* next = nullptr;
            while (count > 0) {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
                count--;
            }
            if (next != nullptr) {
                head->next = reverseKGroup(next, k); // Recurse for the next group
            }
            return prev; // prev now points to the new start of the reversed group
        }
        return head;
    }
};
