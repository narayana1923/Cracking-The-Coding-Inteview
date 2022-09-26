#include <bits/stdc++.h>
using namespace std;

class Stack {
    int size;
    int *arr;
    int *top;

   public:
    Stack(int size) {
        this->size = size / 3;
        arr = new int[size];
        top = new int[size / 3];
        top[0] = 0;
        top[1] = size / 3;
        top[2] = 2 * (size / 3);
    }
    void push(int stackNo, int data) {
        if (top[stackNo] >= (stackNo * size) + 3) {
            cout << "Overflow" << endl;
            return;
        }
        arr[top[stackNo]] = data;
        top[stackNo]++;
    }

    void pop(int stackNo) {
        if (top[stackNo] == stackNo * (size)) {
            cout << "UnderFlow" << endl;
            return;
        }
        top[stackNo]--;
    }

    int peek(int stackNo) {
        if (top[stackNo] == stackNo * (size)) {
            cout << "UnderFlow" << endl;
            return;
        }
        return arr[top[stackNo]];
    }

    bool isEmpty(int stackNo) {
        return top[stackNo]==stackNo*size;
    }

    bool isFull(int stackNo) {}

    int size(int stackNo) {}
};

int main() {
    return 0;
}