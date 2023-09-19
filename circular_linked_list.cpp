#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    // copy constructor
    node(int data){
        this->data = data;
        this->next = nullptr;
    }
    ~node(){
        int value = this->data;
        cout << "The deleted value is " << value << endl;
    }
};
// inserting element in circular linked list at tail
void insert_element(node* &head, node* &tail, int data) {
    node* temp = new node(data);

    if (head == nullptr){
        
        head = temp;
        tail = temp;
        temp->next = head;
    }
    else{

        temp->next = head;  // New node points to the head of the circular list
        tail->next = temp;  // Tail now points to the new node
        tail = temp;  // Update tail to the new node
    }
}
// insert at head in the linked list
void insert_at_head(node* &head, int data) {
    if (head == nullptr) {
        return;
    } else {
        node* temp = new node(data);
        temp->next = head;
        

        // Update tail to the new node
        node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = temp;

        head = temp; // Update head to the new node

       
    }

}
// insert at k position in linked list
void insert_at_k_position(node* &head, node* &tail, int position, int data){
    if(head == NULL){
        return;
    }
    else{
        if(position == 0){
            insert_at_head(head, data);
            return;
        }
        int cnt = 1;
        node* cur = head;
        while(cnt < position-1 && cur != nullptr){
            cur = cur->next;
            cnt++;
        }
        if(tail == cur){
            insert_element(head,tail,data);
            return;
        }
        
        node* temp = new node(data);
        temp->next = cur->next;
        cur->next = temp;
    }
}
// deleting node in the linked list
void deleting(node* &head, node* &tail, int position) {
    if (head == nullptr) {
        return;
    }

    if (position == 0) {
        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = head->next;
        delete head;
        head = temp->next;
        return;
    }

    int cnt = 1;
    node* prev = head;
    node* cur = head->next;

    while (cnt < position && cur != head) {
        prev = cur;
        cur = cur->next;
        cnt++;
    }

    if (cur == head) {
        cout << "Invalid position. Cannot delete at position " << position << endl;
        return;
    }
    if(cur == tail){
        tail = prev;
        prev->next = cur->next;
        delete cur;
        return;
    }

    prev->next = cur->next;
    delete cur;
}

// display the linked list
void display(node* tail) {

    node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }
    cout << "Linked List = ";

    do{
        cout << tail -> data << "->";
        tail = tail -> next;
    } while(tail != temp);

    cout <<"NULL" << endl;
} 
int main(){
    node* n1 = nullptr;
    node* head = n1;
    node* tail = n1;
    insert_element(head, tail, 10);
    insert_element(head, tail, 20);
    insert_element(head, tail, 30);
    insert_element(head, tail, 40);
    insert_element(head, tail, 50);

    insert_at_k_position(head, tail, 0, 23);

    insert_at_k_position(head, tail, 7, 80);

    deleting(head, tail, 6);


    display(head);

    cout << "Head = " << head->data << endl;
    cout  << "Tail = "<< tail->data << endl;


}
