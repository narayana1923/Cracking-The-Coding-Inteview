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

void delete_middle_node(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;
    while(fast && fast->next){
        prev= slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
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
    delete_middle_node(head);
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}