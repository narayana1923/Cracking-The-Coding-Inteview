/**
 * You have two numbers represented by linked list, where each node
 * contains a single digit. Digits are stored in reverse order.(1's
 * digit is at the head) Write a function that adds two such numbers
 * and returns a number in similar list format. example: 7-->1-->6 +
 * 5-->9-->2 = 2-->1-->9 which is (617 + 295  = 912) What if digits
 * are not stored in reverse order(i.e 1's digit is at tail)
 * (6--1-->7) + (2-->9-->5) = (9-->1-->2)
 *
 */

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

Node *sum_lists_iterative(Node *head1, Node *head2) {
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;
    Node *list = nullptr;
    Node *listTail = nullptr;
    int value = 0, carry = 0;
    while (head1 || head2) {
        value = carry + (head1 ? head1->data : 0) +
                (head2 ? head2->data : 0);
        if (value > 9) {
            carry = 1;
            value %= 10;
        } else {
            carry = 0;
        }
        Node *temp = new Node(value);
        if (list) {
            listTail->next = temp;
        } else {
            list = temp;
        }
        listTail = temp;
        if (head1) head1 = head1->next;
        if (head2) head2 = head2->next;
    }
    if (carry) listTail->next = new Node(carry);
    return list;
}

Node *sum_lists_recursive(Node *head1, Node *head2, int carry = 0) {
    if (head1 == nullptr && head2 == nullptr && carry == 0)
        return nullptr;
    int value = carry;
    if (head1) value += head1->data;
    if (head2) value += head2->data;
    Node *temp = new Node(value % 10);
    temp->next = sum_lists_recursive(head1 ? head1->next : head1,
                                     head2 ? head2->next : nullptr,
                                     value > 9 ? 1 : 0);
    return temp;
}

void sum_lists_iterative_inplace(Node *head1, Node *head2) {
    Node **cur1 = &head1, **cur2 = &head2;
    int carry = 0;
    while (*cur1) {
        int val = (*cur1)->data + carry;
        if (cur2) {
            val += (*cur2)->data;
            cur2 = &((*cur2)->next);
        }
        if (val > 9)
            carry = 1;
        else
            carry = 0;
        (*cur1)->data = val % 10;
        cur1 = &((*cur1)->next);
    }
    *cur1 = *cur2;
    while (carry) {
        if (*cur1 == nullptr) *cur1 = new Node(0);
        int val = (*cur1)->data + carry;
        if (val > 9)
            carry = 1;
        else
            carry = 0;
        (*cur1)->data = val % 10;
        cur1 = &((*cur1)->next);
    }
}

int length(Node *head) {
    int len = 0;
    while (head){
        len++;
        head = head->next;
    }
    return len;
}

void padList(Node *&list, int padding) {
    while (padding--) {
        Node *temp = new Node(0);
        temp->next = list;
        list = temp;
    }
}

Node *followup_recursive(Node *head1, Node *head2, int &carry) {
    if (head1 == nullptr && head2 == nullptr && carry == 0) {
        return nullptr;
    }

    Node *result =
        followup_recursive(head1 ? (head1->next) : nullptr,
                           head2 ? (head2->next) : nullptr, carry);

    int value =
        carry + (head1 ? head1->data : 0) + (head2 ? head2->data : 0);
    Node *temp = new Node(value % 10);
    temp->next = result;
    result = temp;
    carry = (value > 9) ? 1 : 0;
    return result;
}

Node *followup(Node *head1, Node *head2) {
    int len1 = length(head1);
    int len2 = length(head2);
    if (len1 > len2) {
        padList(head2, len1 - len2);
    } else {
        padList(head1, len2 - len1);
    }
    int carry = 0;
    Node *list = followup_recursive(head1, head2, carry);
    if (carry) {
        Node *temp = new Node(carry);
        temp->next = list;
        list = temp;
    }
    return list;
}

int main() {
    Node *head1 = nullptr, *head2 = nullptr;
    int m, n;
    cin >> m >> n;
    int x;
    for (int i = 0; i < m; i++) {
        cin >> x;
        head1 = insert_at_beginning(head1, x);
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        head2 = insert_at_beginning(head2, x);
    }
    sum_lists_iterative_inplace(head1, head2);
    Node *temp = head1;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}