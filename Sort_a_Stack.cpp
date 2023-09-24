#include <bits/stdc++.h>
void sort_insert(stack<int> &stack, int num){
	if(stack.empty() == true || (! stack.empty() && stack.top() <= num ) ){
		stack.push(num);
		return;
	}
	int nums = stack.top();
	stack.pop();
	// recursive call
	sort_insert(stack, num);
	stack.push(nums);
	return;
}
void sortStack(stack<int> &stack)
{
	// step 1 = Checking the base case.
	if(stack.empty() == true){
		return;
	}
	int num = stack.top();
	stack.pop();
	// step = 2 recursive call
	// step = 3 remove the element one by one.
	sortStack(stack);
	// step = 4 after element will remove now to check which element in the stack is smaller
	sort_insert(stack, num);
}
