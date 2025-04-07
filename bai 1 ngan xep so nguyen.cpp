#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

// Cai dat StackInt su dung mang
class StackInt {
private:
    int *arr;
    int top;
    int capacity;
public:
    StackInt(int size) {
        capacity = size;
        arr = new int[size];
        top = -1;
    }
    ~StackInt() { delete[] arr; }
    bool IsEmpty() { return top == -1; }
    bool IsFull() { return top == capacity - 1; }
    void PushStack(int x) {
        if (IsFull()) {
            cout << "Stack day!\n";
            return;
        }
        arr[++top] = x;
    }
    int PopStack() {
        if (IsEmpty()) {
            cout << "Stack rong!\n";
            return -1;
        }
        return arr[top--];
    }
    int PeekStack() {
        if (IsEmpty()) return -1;
        return arr[top];
    }
    void Clear() { top = -1; }
};

// Cai dat LinkedStackInt su dung danh sach lien ket
struct Node {
    int data;
    Node *next;
};

class LinkedStackInt {
private:
    Node *top;
public:
    LinkedStackInt() { top = NULL; }
    ~LinkedStackInt() { Clear(); }
    bool IsEmpty() { return top == NULL; }
    void PushStack(int x) {
        Node *newNode = new Node;
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }
    int PopStack() {
        if (IsEmpty()) {
            cout << "Stack rong!\n";
            return -1;
        }
        Node *temp = top;
        int data = top->data;
        top = top->next;
        delete temp;
        return data;
    }
    int PeekStack() {
        if (IsEmpty()) return -1;
        return top->data;
    }
    void Clear() {
        while (!IsEmpty()) PopStack();
    }
};

// Dao so su dung stack
int ReverseNumber(int num) {
    stack<int> s;
    while (num > 0) {
        s.push(num % 10);
        num /= 10;
    }
    int reversed = 0, factor = 1;
    while (!s.empty()) {
        reversed += s.top() * factor;
        s.pop();
        factor *= 10;
    }
    return reversed;
}

// Kiem tra xau doi xung su dung stack
bool IsPalindrome(string str) {
    stack<char> s;
    for (size_t i = 0; i < str.length(); i++) s.push(str[i]);
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] != s.top()) return false;
        s.pop();
    }
    return true;
}

// Doi so thap phan sang nhi phan
string DecimalToBinary(int num) {
    stack<int> s;
    while (num > 0) {
        s.push(num % 2);
        num /= 2;
    }
    string binary = "";
    stringstream ss;
    while (!s.empty()) {
        ss << s.top();
        s.pop();
    }
    binary = ss.str();
    return binary;
}

// Chuyen bieu thuc trung to sang hau to
int GetPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string InfixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";
    for (size_t i = 0; i < infix.length(); i++) {
        char c = infix[i]; {
        if (isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && GetPrecedence(s.top()) >= GetPrecedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}
}
// Tinh gia tri bieu thuc hau to
int EvaluatePostfix(string postfix) {
    stack<int> s;
    for (size_t i = 0; i < postfix.length(); i++) {
        char c = postfix[i]; {
        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.top();
} }

int main() {
    cout << "Dao so 1234: " << ReverseNumber(1234) << endl;
    cout << "Xau 'madam' doi xung: " << (IsPalindrome("madam") ? "Dung" : "Sai") << endl;
    cout << "So 25 sang nhi phan: " << DecimalToBinary(25) << endl;
    string infix = "3+(4*5)-6";
    string postfix = InfixToPostfix(infix);
    cout << "Bieu thuc hau to: " << postfix << endl;
    cout << "Gia tri bieu thuc: " << EvaluatePostfix(postfix) << endl;
    return 0;
}

