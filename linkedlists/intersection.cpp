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
Node *intersectionPoint(Node *head1, Node *head2) {
    Node *cur1 = head1;
    Node *cur2 = head2;
    if (cur1 == nullptr || cur2 == nullptr) return nullptr;
    while (cur1 != cur2) {
        cur1 = cur1->next;
        cur2 = cur2->next;
        if (cur1 == cur2) return cur1;
        if (cur1 == nullptr) cur1 = head2;
        if (cur2 == nullptr) cur2 = head1;
    }
    return cur1;
}
