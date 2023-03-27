//
//  AVLnode.hpp
//  
//
//  Created by Edward Duque on 3/17/23.
//

#ifndef AVLnode_hpp
#define AVLnode_hpp

#include <stdio.h>
#include <string>
using namespace std; 

class AVLNode
{
private:
  string _val;        // actual value stored in AVL Node
  AVLNode *_left;  // pointer to node's left child (may be null)
  AVLNode *_right; // pointer to node's right child (may be null)
  int _height;     // height of subtree rooted at this node.
public:
  // basic constructor for a node. Has no children, so height is 1
  AVLNode(string val):_val(val), _left(nullptr), _right(nullptr), _height(1) {}

  // accessors/modifiers for instance variables.
  string value() const {return _val;}
  string& value() {return _val;}
  
  AVLNode* left() const {return _left;}
  AVLNode* &left() {return _left;}

  AVLNode* right() const {return _right;}
  AVLNode* &right() {return _right;}

  int height() const {return _height;}
  int &height()  {return _height;}

  // is this a leaf node (with no children)?
  bool isLeaf() const {return !_left && !_right;}
  
  // print out node value and heights of children
  std::ostream& print(std::ostream &os) const;
  
  // insert value into subtree rooted at this node
  AVLNode* insert(string newVal, AVLNode *intoSubTree);

  // remove value from subtree rooted at this node
  AVLNode* remove(string existingVal, AVLNode *fromSubTree);

  // overload << to display this node (not entire subtree rooted at node)
  friend  std::ostream& operator<<(std::ostream &os, const AVLNode &n);
};


#endif /* AVLnode_hpp */


