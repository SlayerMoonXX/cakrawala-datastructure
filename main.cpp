#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* findMin(Node* root) {
    if (root == nullptr) return nullptr;
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* findMax(Node* root) {
    if (root == nullptr) return nullptr;
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}

int height(Node* root) {
    if (root == nullptr) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

int countLeaves(Node* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->right->right = new Node(40);

    cout << "Minimum value: " << findMin(root)->data << endl;
    cout << "Maximum value: " << findMax(root)->data << endl;
    cout << "Height of tree: " << height(root) << endl;
    cout << "Number of leaves: " << countLeaves(root) << endl;

    return 0;
}
