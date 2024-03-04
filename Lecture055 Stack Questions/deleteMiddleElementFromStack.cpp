// Delete middle element from a stack

// Function to remove the middle element from a stack using recursion
void solve(stack<int>& inputStack, int count, int size) {
    // Base case: If the count reaches half of the size (middle element reached), remove the element and return
    if (count == size / 2) {
        inputStack.pop(); // Remove the middle element
        return;
    }
    
    // Remove the top element from the stack
    int num = inputStack.top();
    inputStack.pop();
    
    // Recursive call to solve for the remaining elements
    solve(inputStack, count + 1, size);
    
    // Push back the element that was removed (except for the middle element)
    inputStack.push(num);
}

// Function to delete the middle element from a stack
void deleteMiddle(stack<int>& inputStack, int N) {
    int count = 0; // Counter to keep track of the number of elements processed
    solve(inputStack, count, N); // Call the solve function to remove the middle element
}
