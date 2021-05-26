#include "doctest.h"
#include "BinaryTree.hpp"

using namespace std;
using namespace ariel;

BinaryTree <int> tree;

TEST_CASE("add nodes"){

    

    // add to tree without adding root
    for( int i = 0; i< 20 ; i++){
        int rnd1 = rand () % 10;
        int rnd2 = rand () % 100;
        int rnd3 = rand () % 10;
        int rnd4 = rand () % 100;
        
        CHECK_THROWS(tree.add_left(rnd1,rnd2));
        CHECK_THROWS(tree.add_right(rnd3, rnd4));

    } 
    // added root
        tree.add_root(1);

    // add nodes to tree left side
        for(int i = 1 ; i <=  20 ; i++){
            CHECK_NOTHROW(tree.add_left(i,i+1));
        }

    // add nodes to tree right side
        for(int i = 21 ; i <=  40 ; i++){
            CHECK_NOTHROW(tree.add_right(i,i+1));

        }
}
    


        
    

