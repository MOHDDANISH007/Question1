/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertattail(Node* &head, Node* &tail, int data){
        Node* temp = new Node(data);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail -> next = temp;    
            tail = temp;     
        }
    }
    Node* copyRandomList(Node* head) {
        // step 1 = create copy linked list
        Node* clonehead = NULL;
        Node* clonetail = NULL;

        Node* temp = head;
        while(temp != NULL){
            insertattail(clonehead, clonetail, temp->val);
            temp = temp->next;
        }

        // step 2 = mapping

        unordered_map <Node* , Node*> mapping;

        temp = head;
        Node* clonenode = clonehead;

        while(temp != NULL){
            mapping[temp]  = clonenode;
            temp  = temp->next;
            clonenode = clonenode->next;
        }

        // step 3 = copu random pointer

        temp = head;

        clonenode = clonehead;

        while(temp != NULL){
            clonenode -> random = mapping[temp->random];
            clonenode = clonenode->next;
            temp = temp->next;
        }
        return clonehead;

    }
};
