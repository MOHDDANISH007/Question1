#include<iostream>
#include<map>
using namespace std;

class node {
public:
    int data;
    node* next;

    // constructor
    node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    // destructor
    ~node() {
        int value = this->data;
        cout << "The value which is deleted is " << value << endl;
    }
};

// inserting the value in the linked list at head
void inserting_value(node*& head, int data) {
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}

// inserting the value in the linked list at tail
void inserting_value_tail(node*& tail, int data) {
    node* temp = new node(data);
    if (tail == nullptr) {
        tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}

// inserting the value in the linked list at middle position
void inserting_value_middle(node*& tail, node*& head, int data, int position) {
    if (position == 1) {
        inserting_value(head, data);
        return;
    }
    node* temp = new node(data);
    node* cur = head;
    int cnt = 1;
    while (cnt < position - 1) {
        cur = cur->next;
        cnt++;
    }
    if (cur->next == nullptr) {
        inserting_value_tail(tail, data);
        return;
    }
    temp->next = cur->next;
    cur->next = temp;
}

// deletion of node in the linked list
void deletion(node*& tail, node*& head, int position) {
    if (head == nullptr) {
        cout << "Linked list is empty, no need to delete." << endl;
        return;
    }
    node* cur = head;
    node* prev = nullptr;
    if (position == 1) {
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete cur;
        return;
    }
    int cnt = 1;
    while (cnt < position) {
        prev = cur;
        cur = cur->next;
        cnt++;
    }
    prev->next = cur->next;
    if (cur == tail) {
        tail = prev;
    }
    cur->next = nullptr;
    delete cur;
}

#include<iostream>
#include<map>
using namespace std;

class node {
public:
    int data;
    node* next;

    // constructor
    node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    // destructor
    ~node() {
        int value = this->data;
        cout << "The value which is deleted is " << value << endl;
    }
};

// inserting the value in the linked list at head
void inserting_value(node*& head, int data) {
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}

// inserting the value in the linked list at tail
void inserting_value_tail(node*& tail, int data) {
    node* temp = new node(data);
    if (tail == nullptr) {
        tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}

// inserting the value in the linked list at middle position
void inserting_value_middle(node*& tail, node*& head, int data, int position) {
    if (position == 1) {
        inserting_value(head, data);
        return;
    }
    node* temp = new node(data);
    node* cur = head;
    int cnt = 1;
    while (cnt < position - 1) {
        cur = cur->next;
        cnt++;
    }
    if (cur->next == nullptr) {
        inserting_value_tail(tail, data);
        return;
    }
    temp->next = cur->next;
    cur->next = temp;
}

// deletion of node in the linked list
void deletion(node*& tail, node*& head, int position) {
    if (head == nullptr) {
        cout << "Linked list is empty, no need to delete." << endl;
        return;
    }
    node* cur = head;
    node* prev = nullptr;
    if (position == 1) {
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete cur;
        return;
    }
    int cnt = 1;
    while (cnt < position) {
        prev = cur;
        cur = cur->next;
        cnt++;
    }
    prev->next = cur->next;
    if (cur == tail) {
        tail = prev;
    }
    cur->next = nullptr;
    delete cur;
}

// checking linked list is circular or not by using hashmap
bool iscircular(node*& head) {
    if (head == nullptr) {
        cout << "Linked list is empty, no need to check." << endl;
        return false;
    }

    map<node*, bool> visited;
    node* temp = head;
    
    while (temp != nullptr) {
        if (visited[temp]) {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

// traversing linked list
void traversing(node* &head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    node* n1 = new node(8);
    node* head = n1;
    node* tail = n1;

    inserting_value_tail(tail, 9);
    inserting_value_tail(tail, 10);
    inserting_value_tail(tail, 11);
    inserting_value_tail(tail, 12);
    traversing(head);

    inserting_value_middle(tail, head, 14, 6);
    traversing(head);

    deletion(tail, head, 5);
    traversing(head);

    tail->next = head;

    if (iscircular(head)) {
        cout << "Linked list is circular" << endl;
    }
    else {
        cout << "Linked list is not circular" << endl;
    }

    cout << "Head at = " << head->data << endl;
    cout << "Tail at = " << tail->data << endl;

    return 0;
}
