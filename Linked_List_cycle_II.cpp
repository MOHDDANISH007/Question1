/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* floydcycle(ListNode* &head) {
        if (head == nullptr) {
            cout << "Linked list is empty, no need to check." << endl;
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (slow != nullptr && fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
            }
            slow = slow->next;
            if (slow == fast) {
                return slow;
            }
        }

        return nullptr;
    }

    ListNode* detectCycle(ListNode* head) {
        ListNode* intersection = floydcycle(head);
        ListNode* slow = head;

        if (intersection == nullptr) {
            return nullptr;
        }

        while (slow != intersection) {
            intersection = intersection->next;
            slow = slow->next;
        }

        if (slow == intersection) {
            return slow;
        }

        // Add a return statement for the case where there is no cycle
        return nullptr;
    }
};
