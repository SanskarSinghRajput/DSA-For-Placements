// Reverse Stack Using Recursion 

void insertAtBottom(stack<int> &s, int element) {
    // base case if Stack is empty then push the element x to stack and after that return. 
    // Means x is inserted in bottom of stack
    if(s.empty()) {
        s.push(element);
      	return ;
    }
    
    // Store top  element of stack into temp variable num
    int num = s.top();
    // pop top of stack 
    s.pop();
    
    //recursive call
    insertAtBottom(s, element);
    
    // Push the  popped element back to stack . 
    //This means we are bringing the top element at its original position.
    s.push(num);
}

void reverseStack(stack<int> &stack) {
  	//base case
    if(stack.empty()) {
        return ;
    }
    
    // Store top element of stack in a variable
    int num = stack.top();
    // Pop top of the stack
    stack.pop();
    
    // Make recursive call for remaining stack elements
    reverseStack(stack);
    
    // Insert the popped element to the bottom of reversed stack by calling insertAtBottom() function
    insertAtBottom(stack,num);
}