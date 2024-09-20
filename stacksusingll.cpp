#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class Stack {
private:
    Node *top;
public:
    Stack();
    ~Stack();
    void push(int x);
    int pop();
    int peek(int pos);
    bool isEmpty();
    int stackTop();
    void display();
};

// Constructor
Stack::Stack() {
    top = nullptr;
}

// Destructor
Stack::~Stack() {
    Node *p = top;
    while (top != nullptr) {
        top = top->next;
        delete p;
        p = top;
    }
}

// Pushes an element onto the stack
void Stack::push(int x) {
    Node *t = new Node;
    //CHECK FOR FAILURE OF NODE CREATION
    if (t == nullptr) {
        cout << "Stack overflow" << endl;                                                  
        return;                      
    } 
    //THESE ABOVE LINES ARE TO CHECK IF THERE IS NOT ENOUGH MEMORY IN
    // HEAP TO CREATE A NEW NODE IN WHICH CASE THERE WOULD BE A STACK OVERFLOW
    //IN MOST MODERN COMPUTERS, WE RARELY RUN INTO THIS ISSUE BUT IT IS STILL RECOMMENDED TO BE ON THE SAFE SIDE
    t->data = x;
    t->next = top;
    top = t;
}

// Pops an element from the stack
int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack underflow" << endl;
        return -1;
    }
    Node *p = top;
    int x = p->data;
    top = top->next;
    delete p;
    return x;
}

// Returns whether the stack is empty
bool Stack::isEmpty() {
    return top == nullptr;
}

// Returns the top element of the stack without popping it
int Stack::stackTop() {
    if (top) {
        return top->data;
    }
    return -1;  // Stack is empty
}

// Peeks at the element at a given position
int Stack::peek(int pos) {
    if (isEmpty()) {
        return -1;
    } else {
        Node *p = top;
        for (int i = 0; p != nullptr && i < pos - 1; i++) {
            p = p->next;
        }
        if (p != nullptr) {
            return p->data;
        } else {
            return -1;  // Invalid position
        }
    }
}

// Displays the elements of the stack
void Stack::display() {
    Node *p = top;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// Main function
int main() {
    Stack stk;

    stk.push(7);
    stk.push(5);
    stk.push(9);
    stk.push(19);
    stk.display();

    cout << "Peek at position 3: " << stk.peek(3) << endl;  // Should return the value at the 3rd position from the top

    return 0;
}
