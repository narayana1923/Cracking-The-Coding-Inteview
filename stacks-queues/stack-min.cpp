#include <climits>
#include <iostream>
using namespace std;

class Stack {
    int *arr;
    int size;
    int top;

   public:
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack is full\n";
        } else {
            int temp[getSize()];
            int i = -1;
            while (!isEmpty() && peek() < x) {
                temp[++i] = peek();
                pop();
            }
            arr[++top] = x;
            for (int j = i; j >= 0; j--) {
                arr[++top] = temp[j];
            }
            cout << x << " Inserted element into stack\n";
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack has no elements\n";
        } else {
            cout << arr[top] << " is removed from stack\n";
            top--;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return INT_MAX;
        } else {
            return arr[top];
        }
    }

    int getSize() {
        return top + 1;
    }

    int getMin() {
        return peek();
    }

    int printStack() {
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    Stack s(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.push(x);
    }
    s.printStack();
    cout << s.getMin();
    s.pop();
    cout << s.getMin();
    return 0;
}