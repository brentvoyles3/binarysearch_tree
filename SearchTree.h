#ifndef _SEARCH_TREE_HPP
#define _SEARCH_TREE_HPP

#include <list>
//#include "BinaryTree.h"

typedef int Elem;
  class LinkedBinaryTree {
  protected:
    struct Node {
          Elem elt;
          Node * left;
          Node * right;
    };
  public:
      class Position {                  // position in the tree
    private:
      Node* v;                      // pointer to the node
    public:
      Position(Node* _v = NULL) : v(_v) { }     // constructor
      E& operator*()                    // get element
        { return v->elt; }
      Position left() const             // get left child
        { return Position(v->left); }
      Position right() const                // get right child
        { return Position(v->right); }
      Position parent() const               // get parent
        { return Position(v->par); }
      bool isRoot() const               // root of the tree?
        { return v->par == NULL; }
      bool isExternal() const               // an external node?
        { return v->left == NULL && v->right == NULL; }
      friend class LinkedBinaryTree;            // give tree access
    };
    typedef std::list<Position> PositionList;
  public:
    LinkedBinaryTree();                 // constructor
    int size() const;                   // number of nodes
    bool empty() const;                 // is tree empty?
    Position root() const;              // get the root
    PositionList positions() const;             // list of nodes
    void addRoot();                 // add root to empty tree
    void expandExternal(const Position& p);     // expand external node
    Position removeAboveExternal(const Position& p);    // remove p and parent
    // housekeeping functions omitted...
  protected:                        // local utilities
    void preorder(Node* v, PositionList& pl) const; // preorder utility
  private:
    Node* _root;                    // pointer to the root
    int n;                      // number of nodes
  };
  
#endif
