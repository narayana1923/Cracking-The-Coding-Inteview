#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    Node *left;
    int data;
    Node *right;
    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

Node *insert(vector<int> v, int low, int high) {
    if (low > high) {
        return nullptr;
    }
    int mid = low + (high - low) / 2;
    Node *root = new Node(v[mid]);
    root->left = insert(v, low, mid - 1);
    root->right = insert(v, mid + 1, high);
    return root;
}

Node *createBST(vector<int> v) {
    if (v.size() == 0) return nullptr;
    return insert(v, 0, v.size() - 1);
}

void preorder(Node *root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int getHeight(Node *root) {
    if (root == nullptr) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v) {
        cin >> i;
    }
    Node *root = createBST(v);
    cout << getHeight(root);
    return 0;
}