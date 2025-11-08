#include <iostream>
#include <cmath>
using namespace std;

char stack1[50];
int top1 = -1;

void push(char x) { stack1[++top1] = x; }
char pop() { return stack1[top1--]; }
int prec(char c) {
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return 0;
}

void infixToPostfix(char in[], char out[]) {
    int i=0, j=0;
    char c;
    while(in[i] != '\0') {
        c = in[i];
        if((c>='0' && c<='9') || (c>='A'&&c<='Z') || (c>='a'&&c<='z'))
            out[j++] = c;
        else if(c=='(')
            push(c);
        else if(c==')') {
            while(stack1[top1] != '(')
                out[j++] = pop();
            pop();
        }
        else { // operator
            while(top1!=-1 && prec(stack1[top1]) >= prec(c))
                out[j++] = pop();
            push(c);
        }
        i++;
    }
    while(top1!=-1) out[j++] = pop();
    out[j] = '\0';
}

int evalPostfix(char p[]) {
    int st[50], top=-1;
    int i=0;
    while(p[i] != '\0') {
        char c = p[i];
        if(c>='0' && c<='9')
            st[++top] = c - '0';
        else {
            int b = st[top--];
            int a = st[top--];
            switch(c){
                case '+': st[++top] = a + b; break;
                case '-': st[++top] = a - b; break;
                case '*': st[++top] = a * b; break;
                case '/': st[++top] = a / b; break;
            }
        }
        i++;
    }
    return st[top];
}

int main() {
    char infix[50], postfix[50];
    cout << "Enter infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);
    cout << "Postfix: " << postfix << endl;

    cout << "Value: " << evalPostfix(postfix);
    return 0;
}
