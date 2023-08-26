
void reverse(Node* &head, Node* cur, Node* prev)
{
    if (cur == NULL)
    {
        head = prev;
        return;
    }
    Node* forward = cur->next;
    cur->next = prev;  // Fixed this line to correctly reverse the links
    reverse(head, forward, cur);  // Changed 'prev' to 'cur' as the new previous node
}

Node* reverseLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node* cur = head;
    Node* prev = NULL;
    reverse(head, cur, prev);
    return head;
}
