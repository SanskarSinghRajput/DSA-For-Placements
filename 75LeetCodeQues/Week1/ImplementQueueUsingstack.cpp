#include <stack>

using namespace std;

class MyQueue {
    stack<int> s0, s1; // Two stacks: s0 for push operations, s1 for pop and peek operations
    int front = 0; // Variable to store the front element of the queue
public:
    MyQueue() {
        // Constructor
    }
    
    // Function to push an element into the queue
    void push(int x) {
        // If s0 is empty, update the front element of the queue
        if (s0.empty())
            front = x;

        s0.push(x); // Push the element onto stack s0
    }
    
    // Function to pop the front element from the queue
    int pop() {
        // If stack s1 is empty, transfer elements from stack s0 to s1
        if (s1.empty()) {
            while (!s0.empty()) {
                int x = s0.top();
                s0.pop();
                s1.push(x);
            }
        }
        // Pop the front element from stack s1
        int x = s1.top();
        s1.pop();
        return x;
    }
    
    // Function to return the front element of the queue without removing it
    int peek() {
        // If stack s1 is not empty, return the top element of s1
        if (!s1.empty()) {
            return s1.top();
        }
        // Otherwise, return the front element stored in the variable front
        return front;
    }
    
    // Function to check if the queue is empty
    bool empty() {
        // The queue is empty if both stacks s0 and s1 are empty
        return s0.empty() && s1.empty();
    }
};
