//
// Created by rohtanza on 11/3/23.
//

#ifndef BST_BST_H
#define BST_BST_H

#include <iostream>
#include <climits>
#include <queue>

using namespace std;

template<typename T>
class BST {
    class Node {
    public:
        T value;
        Node *left;
        Node *right;
        unsigned int height;
    public:
        explicit Node(T value) : value(value), left(nullptr), right(nullptr), height(0) {}

    };

    Node *root;

public:
    /*all the methods below are helper functions
     * to call in main, so we don't have to make our
     * root public
     * */

    void Delete(T value);

    void insert(T value);

    void displayTree();

    bool isEmpty();

    string searchNode(T value);

    void inOrder();

    void preOrder();

    void postOrder();

    T findMax();


    T findMin();

    Node *successor(T value);

    Node *predecessor(T value);

    void levelOrderTraversal();

    BST() : root(nullptr) {}

private:

    Node *successor(Node *root, T value);

    Node *predecessor(Node *root, T value);

    void levelOrderTraversal(Node *root);

    T findMax(Node *root);

    T findMin(Node *root);

    Node *insert(Node *node, T value);

    unsigned int height(Node *node);

    void display(Node *node, int level);

    Node *search(Node *root, T value);

    void inOrder(Node *node);

    void preOrder(Node *node);

    void postOrder(Node *node);

    Node *deleteNode(Node *root, T delvalue);


};

template<typename T>
typename BST<T>::Node *BST<T>::insert(typename BST<T>::Node *node, T value) {

    if (node == nullptr) {
        return new Node(value);
    }
    if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    }
    node->height = 1 + max(height(node->left), height(node->right));
    return node;;

}

template<typename T>
void BST<T>::insert(T value) {
    root = insert(root, value);
}


template<typename T>
typename BST<T>::Node *BST<T>::deleteNode(BST::Node *root, T delvalue) {
    if (root == NULL)
        return root;
    if (root->value > delvalue) {
        root->left = deleteNode(root->left, delvalue);
        return root;
    } else if (root->value < delvalue) {
        root->right = deleteNode(root->right, delvalue);
        return root;
    }
    if (root->left == NULL) {
        Node *temp = root->right;
        delete root;
        return temp;
    } else if (root->right == NULL) {
        Node *temp = root->left;
        delete root;
        return temp;
    } else {
        Node *succParent = root;
        Node *succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        root->value = succ->value;
        delete succ;
        return root;
    }
}

template<typename T>
void BST<T>::Delete(T value) {
    root = deleteNode(root, value);
}


template<typename T>
void BST<T>::levelOrderTraversal(BST::Node *root) {
    if (root == nullptr) {
        return;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        cout << node->value << " ";
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
}

template<typename T>
void BST<T>::levelOrderTraversal() {
    levelOrderTraversal(root);

}

template<typename T>
T BST<T>::findMin(BST::Node *root) {
    if (root == nullptr)
        return T();
    else if (root->left == nullptr)
        return root->value;
    return findMin(root->left);
}


template<typename T>
T BST<T>::findMax(BST::Node *root) {
    if (root == nullptr)
        return T();
    else if (root->right == nullptr)
        return root->value;
    return findMax(root->right);
}

template<typename T>
T BST<T>::findMin() {
    return findMin(root);
}

template<typename T>
T BST<T>::findMax() {
    return findMax(root);
}

template<typename T>
void BST<T>::postOrder(BST::Node *node) {
    if (node == nullptr)
        return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->value << " ";

}

template<typename T>
void BST<T>::preOrder(BST::Node *node) {
    if (node == nullptr)
        return;
    cout << node->value << " ";
    preOrder(node->left);
    preOrder(node->right);
}

template<typename T>
void BST<T>::inOrder(BST::Node *node) {
    if (node == nullptr)
        return;
    inOrder(node->left);
    cout << node->value << " ";
    inOrder(node->right);

}

template<typename T>
void BST<T>::inOrder() {
    inOrder(root);
}

template<typename T>
void BST<T>::preOrder() {
    preOrder(root);
}

template<typename T>
void BST<T>::postOrder() {
    postOrder(root);
}


template<typename T>
typename BST<T>::Node *BST<T>::search(BST::Node *root, T value) {

    if (root == nullptr || root->value == value) return root;

    if (value < root->value)
        return search(root->left, value);
    else return search(root->right, value);

}

template<typename T>
string BST<T>::searchNode(T value) {
    Node *temp = search(root, value);
    if (temp == nullptr) return "Not found";
    else return (to_string(temp->value) + " found");
}


template<typename T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}

template<typename T>
void BST<T>::display(BST::Node *node, int level) {

    if (node == nullptr)
        return;

    display(node->right, level + 1);

    if (level != 0) {
        for (int i = 0; i < level - 1; ++i) {
            cout << "| \t\t";
        }
        cout << "----->" << node->value << endl;
    } else cout << node->value << endl;
    display(node->left, level + 1);

}

template<typename T>
void BST<T>::displayTree() {
    display(root, 0);
}

template<typename T>
unsigned int BST<T>::height(BST::Node *node) {
    if (node == nullptr)
        return -1;
    return node->height;
}

template<typename T>
typename BST<T>::Node *BST<T>::predecessor(BST::Node *root, T value) {
    Node *pre = nullptr;
    while (root) {
        if (root->value < value) {
            pre = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return pre;
}

template<typename T>
typename BST<T>::Node *BST<T>::predecessor(T value) {
    return predecessor(root, value);
}

template<typename T>
typename BST<T>::Node *BST<T>::successor(BST::Node *root, T value) {
    return successor(root, value);
}


template<typename T>
typename BST<T>::Node *BST<T>::successor(T value) {
    Node *succ = nullptr;
    while (root) {
        if (root->value > value) {
            succ = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return succ;
}


#endif //BST_BST_H
