#include <iostream>
#include <stack>
using namespace std;

class MyStack {
    stack<int> s1, s2;

   public:
    void push(int data) {
        while (!isEmpty() && peek() < data) {
            s2.push(peek());
            pop();
        }
        s1.push(data);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop() {
        s1.pop();
    }

    int peek() {
        return s1.top();
    }

    bool isEmpty() {
        return s1.empty();
    }
};

int main() {
    int n;
    cin >> n;
    MyStack s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.push(x);
    }
    while (!s.isEmpty()) {
        cout << s.peek() << " ";
        s.pop();
    }
    return 0;
}