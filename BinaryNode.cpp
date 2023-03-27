//
//  BinaryNode.cpp
//  
//
//  Created by Edward Duque on 3/20/23.
//

#include "BinaryNode.hpp"

bool
TreeNode::isLeaf() const
{
    return !_right && !_left;
    /*
    if (!_right && !_left)
        return true;
    else
        return false;
    */
}


unsigned int
TreeNode::depth() const
{
    unsigned int ancestorCount=0;
    
    TreeNode *curr = (TreeNode *) this;
    while(curr->_parent!=NULL)
    {
        ancestorCount++;
        curr = curr->_parent;
    }
    
    return ancestorCount;
}
