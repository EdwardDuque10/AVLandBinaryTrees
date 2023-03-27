//
//  BinaryTree.hpp
//  
//
//  Created by Edward Duque on 3/20/23.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>
#include <iostream>
#include "BinaryNode.hpp"
#include <algorithm> 

class BinaryTree
{
private:
    TreeNode *_root;
public:
    BinaryTree(): _root(NULL) {}
    
    TreeNode *find(const std::string &findMe) const;
    
    void insert(const std::string &valueToAdd);
    void remove(const std::string &valueToDel);
    //function for height.
    int treeHeight(TreeNode *root);
    //function to get the root.
    TreeNode *getroot();
    
    friend std::ostream& operator<<(std::ostream &os, const BinaryTree &bt);
};

#endif /* BinaryTree_hpp */
