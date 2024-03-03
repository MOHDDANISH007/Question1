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
    void length(ListNode* head, int& length){
        if(head == nullptr){
            return;
        }
        else{
            ListNode* cur = head;
            while(cur!=nullptr){
                length++;
                cur = cur->next;
            }
        }
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Optimal solution
        if(head == nullptr){
            return head;
        }

        ListNode* first  = head;
        ListNode* second = head;
        ListNode* prev   = nullptr; 

        // Move the first pointer n nodes ahead
        for (int i = 0; i < n; i++) {
            first = first->next;
    }

    // Move both pointers until the first pointer reaches the end
    while (first != nullptr) {
        prev   = second; 
        second = second->next;
        first  = first->next;
    }

    // Check if the node to be deleted is the head
    if (prev == nullptr) {
        head = head->next;
        delete second;
    } else {
        prev->next = second->next;
        delete second; 
    }
 

        // // Brute force approach
        // if(head == nullptr){
        //     return head;
        // }
        // int len = 0;
        // length(head, len);

        // int delete_from_beginning = len - n + 1;

        // ListNode* cur = head;
        // ListNode* prev = nullptr;
        // int i = 1;

        // while(i < delete_from_beginning && cur != nullptr){
        //     prev = cur;
        //     cur = cur->next;
        //     i++;
        // }

        // if(i == delete_from_beginning && cur != nullptr){
        //     if(prev == nullptr){
        //         // If the node to be deleted is the head
        //         head = cur->next;
        //     } else {
        //         prev->next = cur->next;
        //     }
        //     delete cur;
        // }
        return head;
    }
};
