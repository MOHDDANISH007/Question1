/****************************************************************

    Following is the class structure of the Node class:

    class Node
    {
    public:
        int data;
        Node *next;
        Node()
        {
            this->data = 0;
            next = NULL;
        }
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
        Node(int data, Node* next)
        {
            this->data = data;
            this->next = next;
        }
    };

*****************************************************************/
Node* getMiddle(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node* reverse(Node* head){
    Node* cur = head;
    Node* prev = NULL;
    Node* next1 = head;

    while(cur != NULL){
        next1 = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next1;
    }
    return prev;
}

bool isPalindrome(Node *head)
{
    if(head -> next == NULL){
        return true;
    }

    Node* middle = getMiddle(head);
    Node* temp = middle->next;
    middle->next = reverse(temp);

    Node* head1 = head;
    Node* head2 = middle->next;

    while(head2 != NULL){
        if(head1 -> data != head2 -> data){
            return false;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    
    return true;
}
