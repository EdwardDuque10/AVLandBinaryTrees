//
//  main.cpp
//  TreeDataStructures
//
//  Created by Edward Duque on 3/16/23.
//

#include <iostream>
#include <fstream>
#include <string>
#include "AVLnode.hpp"
#include "AVLtree.hpp"
#include "BinaryNode.hpp"
#include "BinaryTree.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    ifstream myFile(argv[1]);//creating a file variable and open it.
    string str;//string to be stored in the file.
    int value;//variable for the n of values in the file.
    
    //if it has less than three command line arguments.
    if (argc<3)
    {
        cout<<"Program can't be executed" << endl;
        return 1;
    }
        //else, the file can be read.
        cout<< "Reading from the file"<< endl;
        
        string avl="avl";//string for AVLtree
        string unbalanced="unbalanced";//string for unbalanced binary tree.

        //if the second argument is avl.
        if(argv[2]==avl)
        {
            cout<<"AVL tree: "<<endl;
            
            AVLTree root;//AVLTree object for the root.
            myFile >> value;//reads the number of values in the file.
            myFile >> str;//reads the first string.
            
            //for loop to iterate the whole file.
            for(int i=0; i<value; i++)
            {
                root.insert(str);//inserts string into the tree.
                myFile >> str;//reads next string.
                root.display(cout);//displays tree.
                cout<<endl;
            }
            //prints the height of the AVLtree.
            root.printHeight();
            
            //close file.
            myFile.close();
            
            //reopen file.
            myFile.open(argv[1]);
            
            //reads first string.
            myFile >> str;
            
            //while there are values in the file.
            while(myFile)
            {
                root.find(str);//looks for the str in the root.
                myFile >> str;//reads next string.
            }
            
        }
    
        //if the second argument is unbalanced.
        else if(argv[2]==unbalanced)
        {
            cout<<"Unbalanced: "<<endl;
            
            BinaryTree root2;//creates a BinaryTree object for the root.
            myFile >> value;//reads the n of values.
            myFile >> str;//reads the first string.
            
            //for loop to iterate the whole file.
            for(int count=0; count<value; count++)
            {
                root2.insert(str);//inserts the string into the tree.
                myFile >> str;//reads the next string.
            }
            
            //prints the height of the unbalanced binary tree.
            cout<<root2.treeHeight(root2.getroot())<<endl;
            
            //close file.
            myFile.close();
            
            //reopen file.
            myFile.open(argv[1]);
            //reads first string.
            myFile >> str;
            
            //while there are values in the file.
            while(myFile)
            {
                root2.find(str);//looks for the string.
                myFile >> str;//reads the next string.
            }
            
        }
    
   
}
