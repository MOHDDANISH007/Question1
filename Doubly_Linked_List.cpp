#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;

    // creating copy constructor
    node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
    // creating destructor
    ~node(){
        int value = this->data;
        cout << "The value which is deleted = " << value << endl;
    }

};
// inserting element in the linked list
void insert_at_head(node* &head, int data){
    if(head == NULL){
        return;
    }
    else{
        node* temp = new node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
// inserting element at tail position
void insert_at_tail(node* &tail, int data){
    if(tail == nullptr){
        return;
    }
    else{
        node* temp = new node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
// inserting at any position element in the linked list
void insert_at_k_position(node* &head, node* &tail, int data, int position){
    if(head == nullptr){
        return;
    }
    else{
        // checking for first condition

        if(position == 0){
            insert_at_head(head, data);
            return;
        }
        node* prev = nullptr;
        node* cur = head;
        int cnt = 1;
        while(cnt < position && cur ->next != nullptr){
            prev = cur;
            cur = cur->next;
            cnt++;
        }
        // checking for last condition
        if(cur->next == NULL){
            insert_at_tail(tail, data);
            return;
        }
        node* temp = new node(data);
        prev->next = temp;
        temp->prev = prev;
        temp->next = cur;
        cur->prev = temp;
    }
}
// deleting the node 
void deleting(node* &head, node* &tail, int position){
    if(head == NULL){
        return;
    }
    else{
        node* prev = nullptr;
        node* cur = head;

        int cnt = 1;

        if(position == 1){
            head = head->next;
            head->prev = NULL;
            delete cur;
            return;
        }

        while(cnt < position && cur->next != nullptr){
            prev = cur;
            cur = cur->next;
            cnt++;
        }

        if(cur == tail){
            tail = prev;
            tail->next = nullptr;
            delete cur;
            return;
        }
        cur->prev = NULL;
        prev->next = cur->next;
        cur->next = NULL;
        delete cur;
    }
}
// get the length of linked list
int getlength(node* &head){
    node* temp = head;
    int length = 0;
    while(temp != nullptr){
        temp = temp->next;
        length++;
    }
    return length;
}
// display the linked list
void display(node* &head){
    node* temp = head;
    cout << "Linked List = ";
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }cout << "NULL" << endl;
}
int main(){
    node* n1 = new node(10);
    node* head = n1;
    node* tail = n1;
    // insert_at_head(head, 20);
    // insert_at_head(head, 30);
    // insert_at_head(head, 40);
    // insert_at_head(head, 50);
    insert_at_tail(tail, 20);
    insert_at_tail(tail, 30);
    insert_at_tail(tail, 40);
    insert_at_tail(tail, 50);

    // insert_at_k_position(head, tail, 60, 6);

    cout << "The length of entire linked list is = "<< getlength(head) << endl;

    deleting(head, tail, 6);


    display(head);

    

    cout << "Head = "<<head->data << endl;
    cout << "Tail = "<<tail->data << endl;




}
