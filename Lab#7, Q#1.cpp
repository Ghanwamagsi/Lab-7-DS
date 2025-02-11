#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top; 
public:
    Stack() { top = NULL; }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        std::cout << value << " pushed into stack.\n";
    }
 
    void pop() {
        if (top == NULL) {
            std::cout << "Stack Underflow! Cannot pop from an empty stack.\n";
            return;
        }
        Node* temp = top;
        std::cout << top->data << " popped from stack.\n";
        top = top->next;
        delete temp;
    }

    void peek() {
        if (top == NULL) {
            std::cout << "Stack is empty.\n";
            return;
        }
        std::cout << "Top element is: " << top->data << "\n";
    }

    
    bool isEmpty() {
        return top == NULL;
    }

    
    void display() {
        if (top == NULL) {
            std::cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        std::cout << "Stack elements: ";
        while (temp != NULL) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    s.display();
    s.peek();
    
    s.pop();
    s.display();

    return 0;
}