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

   ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
    }

    bool isPalindrome(ListNode* head) {
        // optimal solution
        if(head == nullptr){
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        // Now reversering the part where my slow is pointing
        ListNode* newNode  = reverse(slow->next);
        ListNode* first = head;
        ListNode* second = newNode;

       while(first != nullptr && second != nullptr) {
    if(first->val != second->val) {
        reverse(newNode);
        return false;
    }
    first = first->next;
    second = second->next;
}

        return true;










        // better  solution
        //  if(head == NULL){
        //     return false;
        // }

        // vector <int> arr;
        // ListNode* cur = head;
      
        // while(cur != NULL){
        //     arr.push_back(cur->val);
        //     cur = cur->next;
        // }
        // int s = 0;
        // int e = arr.size()-1;
        // while(s < e){
        //     if(arr[s] == arr[e]){
        //         s++;
        //         e--;
        //     }
        //     else{
        //         return false;
        //     }
        // }
        // return true;

    }
};
