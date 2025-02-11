#include <iostream>
#include <cctype> 
#include <cstring> 

#define MAX 100

using namespace std;

class Stack {
private:
    char arr[MAX]; 
    int top; 
public:
    Stack() { top = -1; } 

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }
    
    void push(char x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    char peek() {
        if (isEmpty()) return -1;
        return arr[top];
    }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0; 
}

void infixToPostfix(const char* infix) {
    Stack s;
    char postfix[MAX]; 
    int j = 0; 

    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

      
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix[j++] = s.pop();
            }
            s.pop(); 
        }
        
        else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                postfix[j++] = s.pop();
            }
            s.push(c);
        }
    }

    
    while (!s.isEmpty()) {
        postfix[j++] = s.pop();
    }

    postfix[j] = '\0'; 
    cout << "Postfix Expression: " << postfix << endl;
}


int main() {
    char infix[MAX];
    cout << "Enter infix expression: ";
    cin >> infix;

    infixToPostfix(infix);

    return 0;
}