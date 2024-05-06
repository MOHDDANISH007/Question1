class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        // Brute force approach....

        // ListNode* dummy = new ListNode(0);
        // dummy->next = head;
        // ListNode* prev = dummy;
        // ListNode* current = head;

        // while (current != nullptr) {
        //     ListNode* runner = current->next;
        //     bool removeCurrent = false;

        //     while (runner != nullptr) {
        //         if (runner->val > current->val) {
        //             removeCurrent = true;
        //             break;
        //         }
        //         runner = runner->next;
        //     }

        //     if (removeCurrent) {
        //         prev->next = current->next;
        //     } else {
        //         prev = current;
        //     }

        //     current = current->next;
        // }

        // return dummy->next;



        // Optimal Appproach

        stack<int> st;
        ListNode* cur = head;

        // Step 1: Use stack to track nodes with decreasing values
        while (cur != nullptr) {
            // Maintain a stack with decreasing values
            while (!st.empty() && cur->val > st.top()) {
                st.pop(); // Pop from stack until we find a greater value or stack is empty
            }
            st.push(cur->val); // Push current value onto the stack
            cur = cur->next; // Move to the next node
        }

        // Step 2: Convert stack to vector and reverse the vector
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top()); // Store stack elements into a vector
            st.pop();
        }
        reverse(ans.begin(), ans.end()); // Reverse the vector to get nodes in correct order

        // Step 3: Build a new linked list from the vector
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for (int val : ans) {
            ListNode* newNode = new ListNode(val); // Create a new node
            curr->next = newNode; // Link the new node to the current node
            curr = curr->next; // Move the current pointer forward
        }

        // Step 4: Clean up and return the new head of the modified linked list
        ListNode* newHead = dummy->next;
        delete dummy; // Delete the dummy node
        return newHead;
    }
};
