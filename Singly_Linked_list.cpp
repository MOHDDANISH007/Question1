#include<iostream>
using namespace std;
// creating class
class node{
    public:
    int data;
    node* next;

    // copy constructor
    node(int data){
        this->data = data;
        this->next = nullptr;
    }
    // creating destructor
    ~node(){
        int value = this->data;
        cout << "The value is deleted = " << value << endl;

    }
    // display the data
    void display(){
        cout << data << endl;
    }
};
// inserting node at head position in the linked list
void insert_head(node* &head, int data){

    if(head == NULL){
        return;
    }
    else{
        node* temp = new node(data);
        temp->next = head;
        head = temp; 

    }
}
// inserting node at tail position in the linked list
void insert_tail(node* &tail, int data){
    if(tail == nullptr){
        return;
    }
    else{
        node* temp = new node(data);
        tail->next = temp;
        tail = temp;
    }
}
// inserting node at any position in the linked list
void inserting_k_position(node* &head, node* &tail, int data, int position){
    if(head == NULL){
        return;
    }
    else{
        if(position == 1){
            insert_head(head, data);
            return;
        }
        int cnt = 1;
        node* cur = head;
        node* prev = nullptr;
        while(cnt < position){
            prev = cur; 
            cur = cur->next;
            cnt ++;
        }

        if(prev->next == NULL){
            insert_tail(tail,data);
            return;
        }
        node* temp = new node(data);
        prev->next = temp;
        temp->next = cur;
    }
}
// deleting the node.
void deleting(node* &head, node* &tail, int position){
    if(head == NULL){
        return;
    }

    else{
        node* cur = head;
        node* prev = nullptr;
        int cnt = 1;
        while(cnt < position){
            prev = cur;
            cur = cur->next;
            cnt++;
        }
        // adding extra condition for 0th index
        if(position == 0){
            head = head->next;
            delete cur;
            return;
        }
        // and for last index also because managing the tail and head condition
        if(prev == tail){
            tail = prev;  // Update the tail to the previous node
            delete cur;
            return;
        }
        prev->next = cur->next;
        cur->next = NULL;
        delete cur;
    }
}

// display the linked list
void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }cout << "NULL"<< endl;
}

int main(){
    node* n1 = new node(10);
    node* head = n1;
    node* tail = n1;
    // insert_head(head, 20);
    // insert_head(head, 30);
    // insert_head(head, 40);
    // insert_head(head, 50);
    // insert_head(head, 60);

    insert_tail(tail,20);
    insert_tail(tail,30);
    insert_tail(tail,40);
    insert_tail(tail,50);

    inserting_k_position(head, tail, 5, 1);
    deleting(head, tail, 6);

    // n1->display();
    print(head);

    cout << " head = "<< head->data <<endl;
    cout << " Tail = "<< tail->data << endl;
}
