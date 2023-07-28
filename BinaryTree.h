#ifndef _BINARYTREE_H
#define _BINARYTREE_H
//Header file for binary tree
template <typename E>                   // base element type
  class BinaryTree<E> {                 // binary tree
  public:                       // public types
    class Position;                 // a node position
    class PositionList;                 // a list of positions
  public:                       // member functions
    int size() const;                   // number of nodes
    bool empty() const;                 // is tree empty?
    Position root() const;              // get the root
    PositionList positions() const;             // list of nodes
  };

template <typename E>                   // base element type
  class Position<E> {                   // a node position
  public:
    E& operator*();                     // get element
    Position left() const;              // get left child
    Position right() const;             // get right child
    Position parent() const;                // get parent
    bool isRoot() const;                // root of tree?
    bool isExternal() const;                // an external node?
  };

#endif

