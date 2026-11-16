
#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;

struct Node {
    char data;
    Node* next;
};

Node* top = NULL;

// Push operation
void push(char x) {
    Node* n = new Node;
    n->data = x;
    n->next = top;
    top = n;
}

// Pop operation
char pop() {
    if (top == NULL)
        return '\0';

    Node* t = top;
    char x = t->data;
    top = top->next;
    delete t;
    return x;
}

// Operator precedence
int precedence(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

// Check operator
bool isOperator(char x) {
    return (x == '+' || x == '-' ||
            x == '*' || x == '/' || x == '^');
}

// Infix to Prefix conversion
void infixToPrefix(char infix[]) {
    char prefix[100];
    char temp[100];
    int j = 0;

    int n = strlen(infix);

    // Reverse infix expression
    for (int i = n - 1; i >= 0; i--) {
        if (infix[i] == '(')
            temp[j++] = ')';
        else if (infix[i] == ')')
            temp[j++] = '(';
        else
            temp[j++] = infix[i];
    }
    temp[j] = '\0';

    // Convert reversed expression
    j = 0;

    for (int i = 0; temp[i] != '\0'; i++) {
        char x = temp[i];

        if (x == ' ')
            continue;

        if (isalnum((unsigned char)x))
            prefix[j++] = x;

        else if (x == '(')
            push(x);

        else if (x == ')') {
            while (top != NULL && top->data != '(')
                prefix[j++] = pop();
            pop();
        }

        else if (isOperator(x)) {
            while (top != NULL && top->data != '(' &&
                   (precedence(top->data) > precedence(x) ||
                   (precedence(top->data) == precedence(x)
                   && x == '^')))
                prefix[j++] = pop();

            push(x);
        }
    }

    while (top != NULL)
        prefix[j++] = pop();

    prefix[j] = '\0';

    // Reverse postfix to get prefix
    reverse(prefix, prefix + strlen(prefix));

    cout << "Prefix Expression: " << prefix;
}

int main() {
    char infix[100];

    cout << "Enter Infix Expression: ";
    cin.getline(infix, 100);

    infixToPrefix(infix);

    return 0;
}
