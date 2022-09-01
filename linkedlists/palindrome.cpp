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

bool is_palindrome(Node*& head1,Node* head2){
    if(head2==nullptr) return true;
    bool ans = is_palindrome(head1,head2->next);
    if(!ans) return false;
    ans = head1->data ==head2->data;
    head1=head1->next;
    return ans;
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
    cout<<boolalpha<<is_palindrome(head,head);
    return 0;
}