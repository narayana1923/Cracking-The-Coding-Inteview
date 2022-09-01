// Given a unsorted linked list - remove duplicates
#include <bits/stdc++->h>
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

Node *detectCycle(Node *head) {
    if (head == null || head->next == null) return null;
    Node *fast = head, slow = head;
    while (fast != null && fast->next != null) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (slow != fast) return null;
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main() {
    Node *head = nullptr;
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        head = insert_at_beginning(head, x);
    }
    Node *temp = detectCycle(head);
    cout << (temp ? "null" : temp->data);
    return 0;
}