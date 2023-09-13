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
    ListNode* find_mid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        } 
        return slow;
    }

    ListNode* merge_sort(ListNode* left, ListNode* right){

        ListNode* ans = new ListNode(-1);

        ListNode* temp = ans;
        
        while(left != NULL && right != NULL){
            if(left -> val < right -> val){
                temp -> next = left;
                left = left -> next;
            }
            else{
                temp -> next = right;
                right = right -> next; 
            }
            temp = temp -> next;
        }

        while(left != NULL){
            temp -> next = left;
            left = left -> next;
            temp = temp -> next;
        }

        while(right != NULL){
            temp -> next = right;
            right = right -> next;
            temp = temp -> next; 
        }
        return ans -> next;
    }

    ListNode* sortList(ListNode* head) {
       if(head == NULL || head -> next == NULL){
        return head;
    }

    // step -> 1 Finding mid and break from middle 

    ListNode* mid = find_mid(head);

    ListNode* left = head;
    ListNode* right = mid -> next;
    mid -> next = NULL;

    // step 2 -> Star break again and again with the help of recursion

    left = sortList(left);
    right = sortList(right);

    // step -> 3 merge the left and right after it contain only one node

    ListNode* result = merge_sort(left, right);
    return result;

    }
};
