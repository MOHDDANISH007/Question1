class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* cur = head;
        while (cur->next != nullptr) {
            if (cur->val == cur->next->val) {
                ListNode* nodeToDelete = cur->next; 
                cur->next = cur->next->next;
                delete nodeToDelete;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
