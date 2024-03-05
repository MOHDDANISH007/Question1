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
  ListNode* reverse(ListNode* temp, ListNode* prev) {
    if (temp == nullptr) {
        return prev;
    } else {
        ListNode* nextNode = temp->next;
        temp->next = prev;
        return reverse(nextNode, temp);
    }
}

ListNode* reverseList(ListNode* head) {
    // Using Recursion
    ListNode* temp = head;
    ListNode* prev = nullptr;
    ListNode* newHead = reverse(temp, prev); 
    return newHead;

        // Using while loop and pointer changing
        // if(head == nullptr){
        //     return head;
        // }

        // ListNode* front = head ;
        // ListNode* prev  = nullptr;

        // while(front != nullptr){
        //     front = front->next;
        //     head->next = prev;
        //     prev  = head;
        //     head = front;
        // }
        // // head = prev;
        // return prev;


        // ListNode* cur = head;
        
        // using stack data structure
        // stack<int> st;

        // while(cur != nullptr){
        //     st.push(cur->val);
        //     cur = cur->next;
        // }

        // cur = head;

        // while(cur != nullptr){
        //     cur->val = st.top();
        //     st.pop();
        //     cur = cur->next;
        // }

        // return head;
    }
};
