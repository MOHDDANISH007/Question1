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
    void deleteNode(ListNode* root) {
        if(root == nullptr){
            return;
        }

        ListNode* prev = root;
        ListNode* cur  = root->next;

        swap(prev->val, cur->val);

        prev->next = cur->next;
        cur->next  = nullptr;
        delete(cur);
    }
};
