/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *deleteLast(Node *list){
    // Write your code here
    if(list == nullptr){ // checking is my linked list is empty or not if yes then no need to delete anything..
        return list;
    }
    else{
        Node* prev = nullptr; // creating previous node..
        Node* cur = list; // creating current node for traversing upto last node..
        while(cur -> next != nullptr){ 
            prev = cur;
            cur = cur -> next;
        }
        prev -> next = nullptr;
        delete cur;
    }
    return list;
}
