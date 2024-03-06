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
    // This solution is done by "Tortoise and hare algorithm "

    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next;

            if(fast != NULL){
                fast = fast -> next;
            }

            slow = slow -> next;
            
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};
