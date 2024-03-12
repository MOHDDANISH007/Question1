Node* reverse(Node* head){
    if(head == nullptr){
        return head;
    }

    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while(current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

Node *addOne(Node *head)
{
    if(head == nullptr){
        return head;
    }

    head = reverse(head); // Reverse the list

    Node* temp = head;
    int carry = 1;

    while(temp != nullptr){
        int sum = carry + temp->data;
        temp->data = sum % 10;
        carry = sum / 10;
        if(carry == 0){
            break;
        } 
        temp = temp->next;
    }

    head = reverse(head); // Reverse the list again to restore original order

    if(carry != 0){
        Node* newNode = new Node(carry);
        newNode->next = head;
        head = newNode;
    }
    
    return head;
}
