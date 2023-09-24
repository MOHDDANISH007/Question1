void insert_at_bottom(stack<int> &stack, int element){
    if(stack.empty() == true){
        stack.push(element);
        return;;
    }
    int num = stack.top();
    stack.pop();
    insert_at_bottom(stack, element);
    stack.push(num);
}
void reverseStack(stack<int> &stack) {
    // step 1 = checking it is empty or not because after it reverse then try to insert the elements. 
    if(stack.empty() == true){
        return;
    }
    // step = 2 taking out one by one element 
    int num = stack.top();
    stack.pop();
    reverseStack(stack);
     
    // step 3 = after revers the stack then try to push element in that stack.
    insert_at_bottom(stack,num);
    return;
}
