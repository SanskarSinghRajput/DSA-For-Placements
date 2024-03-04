// Sort A Stack

// Function to insert an element in a sorted order 
void sortedInsert(stack<int> &stack, int num) {
    // base case if stack is empty OR 
    // before checking the number is greater than top of stack check stack is not empty 
    //After that then push it.
    if(stack.empty() || (!stack.empty() && stack.top() < num) ) {
        stack.push(num);
        return;
    }
    
    // Store top  element of stack into temp variable n
    int n = stack.top();
    // pop top of stack 
    stack.pop();
    
    //  Make recursive call for remaining stack elements
    sortedInsert(stack, num);

    // Push the  popped element back to stack . 
    //This means we are bringing the top element at its original position.
    stack.push(n);
}

// Function to sort a Stack
void sortStack(stack<int> &stack){
		//base case
    	if(stack.empty()) {
            return ;
        }
    
        // Store top  element of stack into temp variable num
    	int num = stack.top();
        // pop top of stack 
    	stack.pop();
    
    	// Make recursive call for remaining stack elements
    	sortStack(stack);
    
        // Insert the popped element in sorted way by calling function sortedInsert()
    	sortedInsert(stack, num);
}