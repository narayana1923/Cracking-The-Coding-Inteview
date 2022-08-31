#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

Node *insert_at_beginning(Node *head, int data) {
    Node *temp = new Node(data);
    temp->next = head;
    return temp;
}

int kth_last(Node *head, int k) {
    Node *temp = head;
    for (int i = 0; i < k-1; i++) {
        temp = temp->next;
        if (temp == nullptr) return -1;
    }
    while (temp && temp->next) {
        head = head->next;
        temp = temp->next;
    }
    return head->data;
}

int main() {
    Node *head = nullptr;
    int n, k;
    cin >> n >> k;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        head = insert_at_beginning(head, x);
    }
    cout << kth_last(head, k);
    return 0;
}