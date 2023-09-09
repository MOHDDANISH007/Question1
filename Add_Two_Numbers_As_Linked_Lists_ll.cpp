Node<int> *reverse(Node<int> *head){

    Node<int> *curr=head;

    Node<int> *prev=NULL;

    Node<int> *next=head;

 

    while(curr!=NULL){

        next=curr->next;

        curr->next=prev;

        prev=curr;

        curr=next;

    }

    return prev;

}

 

void insertAtTail(Node<int> *&head, Node<int> *&tail,int value){

    Node<int> *temp=new Node<int>(value);

    if(head==NULL){

        head=temp;

        tail=temp;

        return;

    }else{

        tail->next=temp;

        tail=temp;

    }

}

 

Node<int> *add(Node<int> *&num1 ,Node<int> * &num2){

    int carry=0;

    Node<int> *ansHead=NULL;

    Node<int> *ansTail=NULL;

 

    while(num1!=NULL || num2!=NULL || carry!=0){

        int val1=0;

        if(num1!=NULL) 

            val1=num1->data;

        

        int val2=0;

        if(num2!=NULL)

            val2=num2->data;

        

        int sum=carry+val1+val2;

        int digit=sum%10;

 

        insertAtTail(ansHead,ansTail,digit);

 

        carry=sum/10;

        if(num1!=NULL)

            num1=num1->next;

        if(num2!=NULL)

            num2=num2->next;

    }

    return ansHead;

}

 

Node<int>* addTwoLists(Node<int>* first, Node<int>* second) {

 

    first=reverse(first);

    second=reverse(second);

 

    Node<int> *ans=add(first,second);

 

    ans=reverse(ans);

 

    return ans;

}
