//
//  AVLtree.hpp
//  
//
//  Created by Edward Duque on 3/17/23.
//

#ifndef AVLtree_hpp
#define AVLtree_hpp

#include <stdio.h>

#include "AVLnode.hpp"

#include <iostream>
#include <string>

class AVLTree
{
private:
  AVLNode *_root;    // for a tree, all we need to know is its root
public:
  // default tree is empty
  AVLTree():_root(nullptr) {}

  // add a value to the tree
  void insert(string newVal);

  // rempove a value from the tree
  void remove(string val);
  
  //prints height of the tree.
  void printHeight();
   
  //finds an specific value in the tree.
  AVLNode *find(const std::string &findMe) const;

  // "nicely" display the tree (sideways)
  std::ostream& display(std::ostream &os) const;
};

#endif /* AVLtree_hpp */
