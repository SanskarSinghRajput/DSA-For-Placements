// Insert An Element At Its Bottom In A Given Stack

// Function to insert an element at the bottom of a stack.
void solve(stack<int>& s, int x) {
    // base case if Stack is empty then push the element x to stack and after that return. 
    // Means x is inserted in bottom of stack
    if(s.empty()) {
        s.push(x);
        return ;
    }
    
    // Store top  element of stack into temp variable num
    int num = s.top();
    // pop top of stack 
    s.pop();
    
    // Make recursive call for remaining stack elements
    solve(s, x);
    
    // Push the  popped element back to stack . 
    //This means we are bringing the top element at its original position.
    s.push(num);
}


stack<int> pushAtBottom(stack<int>& myStack, int x){
    solve(myStack, x);
    return myStack;
}
