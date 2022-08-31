// Given a unsorted linked list - remove duplicates
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

void remove_dups(Node *head) {
    unordered_set<int> s;
    Node* prev=nullptr;
    while (head) {
        if (s.find(head->data) == s.end()) {
            s.insert(head->data);
            if(prev){
                prev->next=head;
                prev = prev->next;
            }
            else prev = head;
        } 
        head = head->next;
    }
    prev->next=nullptr;
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
    remove_dups(head);
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}