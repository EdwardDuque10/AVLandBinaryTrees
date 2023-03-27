//
//  BinaryTree.cpp
//  
//
//  Created by Edward Duque on 3/20/23.
//

#include "BinaryTree.hpp"

#include <iostream>
#include <algorithm>

using namespace std;

TreeNode* findHelper(const string &, const TreeNode *);
TreeNode* insertHelper(TreeNode *intoSubTree, const TreeNode *newNode);
void printHelper(const TreeNode *subtree, ostream &os);
void treePrint(const TreeNode *subtree, ostream &os);

TreeNode*
BinaryTree::find(const string &findMe) const
{
    return findHelper(findMe, _root);
}

TreeNode* findHelper(const string &val, const TreeNode *nodePtr)
{
    if (!nodePtr) // no nodes left to search !
        return NULL;
        
    if (nodePtr->value() == val)
        return (TreeNode *) nodePtr;
        
    if ( val > nodePtr->value()  )
        return findHelper(val, nodePtr->right() );
    else // if val < ...
        return findHelper(val, nodePtr->left() );
}

void
BinaryTree::insert(const std::string &valueToAdd)
{
    // already in tree?
    if (find( valueToAdd ) /*!= NULL*/ )
    {
        return;
    }
    
    TreeNode *newTreeNode = new TreeNode(valueToAdd);
    _root = insertHelper(_root, newTreeNode);
}

TreeNode* insertHelper(TreeNode *intoSubTree, const TreeNode *newNode)
{
    // no node to insert? tree will be the same as it is now
    if (!newNode) //if (newNode == NULL)
    {
        return (TreeNode *) intoSubTree;
    }
    
    // empty subtree? the new tree will have only the node we are inserting
    if (!intoSubTree) //if (intoSubTree == NULL)
    {
        return (TreeNode *) newNode;
    }


    // note: this helper function assumes the node is not already present!

    // should we be inserting into left side?
    if     ( newNode->value() < intoSubTree->value() )
    {
        // insert into left subtree, and update our left subtree pointer accordingly
        intoSubTree->left() = insertHelper( intoSubTree -> left() , newNode );

        // update left subtree's "parent" pointer
        intoSubTree->left()->parent() = intoSubTree;
    }
    else // >, so must need to insert into right side
    {
        // insert into right subtree, and update our right subtree pointer accordingly
        intoSubTree->right() = insertHelper( intoSubTree -> right() , newNode );
                
        // update right subtree's "parent" pointer
        intoSubTree->right()->parent() = intoSubTree;
    }
    
    return intoSubTree;
}

void
BinaryTree::remove(const std::string &valueToDelete)
{
    TreeNode *toDel = find(valueToDelete);

    if (!toDel)
        return;
    
    // test for which case we are in ....
    
    if (toDel->isLeaf())
    {
        // think about this ... there is only one node in tree!
        if (toDel == _root)
        {
            _root = NULL;
            return;
        }
        
        TreeNode *parent = toDel->parent();
        if (parent->left() == toDel)
            parent->left() = NULL;
        else // must be right child
            parent->right() = NULL;
            
        //toDel->parent() = toDel->left() = toDel->right() = NULL;
    }
    // check for one child case
    else if ( (toDel->left() && !toDel->right() ) // have left but no right child
                            ||
                 (!toDel->left() && toDel->right() ) // have no left but yes on right child
              )
    {
        if (toDel == _root)
        {
            if (toDel->left()) // is the only child on the left?
                _root = toDel->left();
            else // the only child is on the right
                _root = toDel->right();
                
            _root->parent() = NULL;
            return;
        }
        
        TreeNode *subtreeToMove;
        if (toDel->left()) // left subtree is the 1 child we have
            subtreeToMove = toDel->left();
        else // right subtree is the 1 child we have
            subtreeToMove = toDel->right();
        
        TreeNode *parent = toDel -> parent();
        if (parent->left() == toDel)
            parent->left() = subtreeToMove;
        else
            parent->right() = subtreeToMove;

        subtreeToMove->parent() = parent;
    }
    else // i have 2 children
    {
        TreeNode *largestInLeft;
        largestInLeft = toDel->left();
        while(largestInLeft->right() != NULL)
        {
            largestInLeft = largestInLeft->right();
        }
        
        string dataToKeep = largestInLeft -> value();
        
        remove (dataToKeep);
        toDel->value() = dataToKeep;
        
        
    }
    
}

ostream& operator<<(ostream &stream, const BinaryTree &bt)
{
    //printHelper( bt._root , stream );
    treePrint( bt._root , stream );
    return stream;
}

void printHelper(const TreeNode *subtree, ostream &os)
{
    if (!subtree)
        return;
    
    printHelper(subtree->left(), os);
    os << subtree->value() << endl;
    printHelper(subtree->right(), os);
}

void treePrint(const TreeNode *subtree, ostream &os)
{
    if (!subtree)
        return;
    
    treePrint(subtree->right(), os);
    for(unsigned int ntabs =0; ntabs < subtree->depth() ; ntabs++)
        os << "         ";
    os << subtree->value() << endl;
    treePrint(subtree->left(), os);
}
//calculates the height of the tree.
int
BinaryTree::treeHeight(TreeNode *root)
{
    if(root==0)
        return 0;
    
    else{
        int leftSide= treeHeight(root->left());//looks in the left side.
        int rightSide= treeHeight(root->right());//looks in the right side.
        
        return max(leftSide, rightSide) + 1;//calculates the max between the two sides and add 1.
        
    }
    
}
//returns the root of the tree.
TreeNode *BinaryTree::getroot()
{
    return _root;
}
