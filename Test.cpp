#include "doctest.h"
#include "BinaryTree.hpp"
#include <array>

using namespace std;
using namespace ariel;

BinaryTree <int> tree1;
BinaryTree <int> tree2;

TEST_CASE("add nodes"){

    

    // add to tree without adding root
    for( int i = 0; i< 20 ; i++){
        int rnd1 = rand () % 10;
        int rnd2 = rand () % 100;
        int rnd3 = rand () % 10;
        int rnd4 = rand () % 100;
        
        CHECK_THROWS(tree1.add_left(rnd1,rnd2));
        CHECK_THROWS(tree1.add_right(rnd3, rnd4));

    } 
    // added root
        tree1.add_root(1);

    // add nodes to tree left side
        for(int i = 1 ; i <=  20 ; i++){
            CHECK_NOTHROW(tree1.add_left(i,i+1));
        }

    // add nodes to tree right side
        for(int i = 21 ; i <=  40 ; i++){
            CHECK_NOTHROW(tree1.add_right(i,i+1));

        }

        // BUILDING A NEW BINARY-TREE
        tree2.add_root(1);
        tree2.add_left(1,2);
        tree2.add_left(2,4);
        tree2.add_right(2,5);
        tree2.add_right(1,3);
        tree2.add_left(4,12);
        tree2.add_left(5,10);
        tree2.add_right(10,11);
        tree2.add_right(3,6);
        tree2.add_right(6,7);
        tree2.add_left(6,8);
        tree2.add_left(3,9);
        tree2.add_left(9,12);
        tree2.add_right(7,13);
        //                          ---------[**tree2**]---------
        //                                       (1)
        //                                     /     \
        //                                   (2)     (3)
        //                                  /  \    /   \
        //                                (4)  (5)(9)   (6)
        //                                /    /  /     / \
        //                             (12) (10)(12)  (8)  (7)
        //                                    \              \
        //                                   (11)            (13)

        // throw: each node can has 2 sons!
        CHECK_THROWS(tree2.add_right(1,61));
        CHECK_THROWS(tree2.add_left(1,82));
        CHECK_THROWS(tree2.add_right(2,19));
        CHECK_THROWS(tree2.add_right(3,21));
        CHECK_THROWS(tree2.add_left(6,19));
        CHECK_THROWS(tree2.add_left(3,22));

        // throw: cant overwrite nodes
        CHECK_THROWS(tree2.add_right(7,17));
        CHECK_THROWS(tree2.add_right(3,17));
        CHECK_THROWS(tree2.add_right(2,18));
        CHECK_THROWS(tree2.add_left(6,25));
        CHECK_THROWS(tree2.add_left(6,32));
        CHECK_THROWS(tree2.add_left(9,39));

        // throw: cant add to non-existed nodes
        CHECK_THROWS(tree2.add_left(43,55));
        CHECK_THROWS(tree2.add_left(22,104));
        CHECK_THROWS(tree2.add_left(109,321));
        CHECK_THROWS(tree2.add_left(88,66));
        CHECK_THROWS(tree2.add_right(287,26));
        CHECK_THROWS(tree2.add_right(54,45));
        CHECK_THROWS(tree2.add_right(92,29));
        CHECK_THROWS(tree2.add_right(75,57));

        // Check: begin && end iterators for preorder, inorder, postorder
        array<int,13> in = {12,4,10,23,5,9,8,6,7,13,2,3,1};
        array<int,13> pre = {1,2,4,5,10,11,3,9,12,6,8,7,13};
        array<int,13> post = {12,4,5,10,2,3,9,12,8,7,3,6,1};
        unsigned long i = 0;
        for (auto it = tree2.begin_preorder(); it != tree2.end_preorder(); ++it) {
            CHECK_EQ(*(it) , pre.at(i));
            i++;
        }
        i = 0;
        for (auto it = tree2.begin_inorder(); it != tree2.end_inorder(); ++it) {
            CHECK_EQ(*(it) , in.at(i));
            i++;
        }
        i = 0;
        for (auto it = tree2.begin_postorder(); it != tree2.end_postorder(); ++it) {
            CHECK_EQ(*(it) , post.at(i));
            i++;
        }
        
        


}
    


        
    

