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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;

        ListNode* t1 = l1;
        ListNode* t2 = l2;

        // Push values of l1 into st1
        while (t1 != nullptr) {
            st1.push(t1->val);
            t1 = t1->next;
        }

        // Push values of l2 into st2
        while (t2 != nullptr) {
            st2.push(t2->val);
            t2 = t2->next;
        }

        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;

        // Pop values from stacks and add to the linked list
        while (!st1.empty() || !st2.empty()) {
            int sum = carry;

            if (!st1.empty()) {
                sum += st1.top();
                st1.pop();
            }

            if (!st2.empty()) {
                sum += st2.top();
                st2.pop();
            }

            // Create a new node with the sum % 10
            ListNode* node = new ListNode(sum % 10);
            carry = sum / 10;

            // Connect the new node to the result linked list
            cur->next = node;
            cur = node;
        }

      

        if (carry != 0) {
            ListNode* node = new ListNode(carry);
            cur->next = node;
            cur = node;
        }

        stack<int> st3;

        ListNode* temp3 = dummy->next;

        while (temp3 != nullptr) {
            st3.push(temp3->val);
            temp3 = temp3->next;
        }

        temp3 = dummy->next;

      
        while (!st3.empty()) {
            // Update the value before moving to the next node
            temp3->val = st3.top();
            st3.pop();
            temp3 = temp3->next;
        }

        // Return the result linked list starting from the next of the dummy node
        return dummy->next;
    }
};


