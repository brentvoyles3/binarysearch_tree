#include <iostream>
#include <exception>

using namespace std;

template <typename K, typename V>
class Entry {                       // a (key, value) pair
public:                     // public types
    typedef K Key;                  // key type
    typedef V Value;                    // value type
public:                     // public functions
    Entry(const K& k = K(), const V& v = V())       // constructor
        : _key(k), _value(v) { }
    const K& key() const {
        return _key;
    }       // get key (read only)
    const V& value() const {
        return _value;
    }       // get value (read only)
    void setKey(const K& k) {
        _key = k;
    }       // set key
    void setValue(const V& v) {
        _value = v;
    }       // set value
private:
    //key
    K _key;
    //value
    V _value;
}; // Entry

/*
 * Linked List Binary Search Tree Implementation
 */
class Node {
public:
    //key value
    int value;
    //left tree child
    Node* left;
    //right tree child
    Node* right;
    //parent
    Node * parent;
    //const
    bool inTree;
    Node (int val) {
        value = val;
        left= NULL;
        right = NULL;
        parent = NULL;
    } // Node

    /*
     * Insert a value into the binary search tree.
    */
    Node * insertNode(Node * root, int key) {
        Node * temp;
        //base case
        if (root == NULL) {
            return new Node(key);
          // if root value > key traverse left - recursive case
        } else if (root->value > key) {
                temp = insertNode(root->left, key);
                root->left = temp;
                //else root value is < key traverse right - recursive case
            } else {
                temp = insertNode(root->right, key);
                root->right = temp;
            }
            return root;
    } // insertNode

    //Implement last
    Node * removeNode(Node * root, int key) {
        Node * temp = root;
        Node * par = NULL;
        //if key value is not found in search tree
        if (searchNode(root, key)->value == -1) {
            cout << key << " not found" << endl;
            return temp;
        } // else remove node
        return temp;
    } //removeNode

    /*
     * Search for a key in the binary search tree
     */
    Node * searchNode(Node * temp, int key) {
                //Base case, if key value is not in bst
        if (temp == NULL) {
            cout << "X ";
            return new Node(-1);
            //Base case, if node w/ key is found
        } else if (temp->value == key ) {
            return temp;
            //if search val is > current, recursive call
        } else if (temp->value <= key ) {
            cout << temp->value << ", ";
            return searchNode(temp->right,key);
            //if search val is < current recursive call
        } else if (temp->value > key) {
            cout << temp->value << ", ";
            return searchNode(temp->left, key);
            //Alt base
        } else {
            cout << "X ";
            return new Node(-1);
        }
} // searchNode

}; // Node - bst

/*
 * Main method for handling user input and calling BST functions
 */
int main() {
    cout << "Enter numbers, one line for each:" << endl;
    int input;
    Node bSearchTree(0);
    Node * rootNode = NULL;
    do {
        int idx = 0;
        cin >> input;
        if (input != -1) {
            rootNode = bSearchTree.insertNode(rootNode, input);
        }
    } while (input != -1);
    int searchInput;
    do {
        cout << "Enter a number you want to search for:" << endl;
        cin >> searchInput;
        if (searchInput != -1) {
            Node * searchN = bSearchTree.searchNode(rootNode, searchInput);
            if (searchN->value > 0) {
                cout << searchN->value << ", number is found." << endl;
            } else {
                cout << "number is not found." << endl;
            }
        } // if more searching
    } while (searchInput != -1) ;
    cout << "Goodbye!" << endl;
    return 0;
} // main

