class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        
        unordered_map<ListNode*, bool> nodeMap;
        
        while(headA != nullptr) {
            nodeMap[headA] = true;
            headA = headA->next;
        }
        
        while(headB != nullptr) {
            if(nodeMap.find(headB) != nodeMap.end()) {
                cout << headB->val << endl;
                return headB;
            }
            headB = headB->next;
        }
        
        return nullptr;
    }
};
