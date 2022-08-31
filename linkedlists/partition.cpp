/**
 *  Cracking the coding interview edition 6
 *  Problem 2.4 Partition:
 *  Write code to partition linked list around a value x, such that
 *  nodes less than x come before all the nodes greater than or equal
 * to x. If x is in the list, the values of x only need to be after
 * the elements less than x. Example 3-->5-->8-->5-->10-->2-->1 (x =
 * 5) 3-->1-->2-->10-->5-->5-->
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

Node *partition(Node *head, int k) {
    Node *smallerHead = nullptr, *smallerTail = nullptr;
    Node *greaterHead = nullptr, *greaterTail = nullptr;
    Node *equalHead = nullptr, *equalTail = nullptr;
    while (head) {
        if (head->data < k) {
            if (smallerHead == nullptr) {
                smallerHead = smallerTail = head;
            } else {
                smallerTail->next = head;
                smallerTail = head;
            }
        } else if (head->data > k) {
            if (greaterHead == nullptr) {
                greaterHead = greaterTail = head;
            } else {
                greaterTail->next = head;
                greaterTail = head;
            }
        } else {
            if (equalHead == nullptr) {
                equalHead = equalTail = head;
            } else {
                equalTail->next = head;
                equalTail = head;
            }
        }
        head = head->next;
    }
    if(greaterTail) 
        greaterTail->next=nullptr;
    if(!smallerHead){
        if(equalHead){
            equalTail->next=greaterHead;
            return equalHead;
        }
        else{
            return greaterHead;
        }
    }
    smallerTail->next = equalHead;
    if(equalHead) equalTail->next = greaterHead;
    else smallerTail->next=greaterHead;
    return smallerHead;
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
    head = partition(head, k);
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}