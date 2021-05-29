#include <iostream>


namespace ariel{
    template<typename T> class BinaryTree{
        private:
        struct Node{
            T value;
            Node* right;
            Node* left;
        };
        Node* root;
        
        public:
        BinaryTree<T>() : root (nullptr){}
        // ~BinaryTree<T> (){}
        
        BinaryTree<T> add_root (const T& val){
            return *this;
        }
        
        BinaryTree<T> add_left (const T& parent, const T& child){
            return *this;
        }

        BinaryTree<T> add_right(const T& parent, const T& child){
            return *this;
        }
        
        friend std::ostream& operator<<(std::ostream& output, const BinaryTree& t){
            return output;
        }

        // T get_root(){
        //     return root.value;
        // }

    

        
            // pre order iterator
        class preIterator{
            private:
                Node* node;

            public:

                preIterator (Node* p = nullptr) : node(p){
                    
                }

                preIterator& operator++(){
                    return *this;
                }

                bool operator<(preIterator& it){
                    return false;
                }

                bool operator != (const preIterator& it){
                    return false;
                }

                T& operator * (){
                    return node -> value;
                }

                T& operator -> (){
                    return &(node -> value);
                }

        };

        class inIterator{
             private:
                Node* node;

            public:

                inIterator (Node* p = nullptr) : node(p){
                    
                }

                inIterator& operator++(){
                    return *this;
                }

                bool operator<(inIterator& it){
                    return false;
                }

                bool operator != (const inIterator& it){
                    return false;
                }

                T& operator * (){
                    return node -> value;
                }

                T& operator -> (){
                    return &(node -> value);
                }           
            
        };

        class postIterator{
             private:
                Node* node;

            public:

                postIterator (Node* p = nullptr) : node(p){
                    
                }

                postIterator& operator++(){
                    return *this;
                }

                bool operator<(postIterator& it){
                    return false;
                }

                bool operator != (const postIterator& it){
                    return false;
                }

                T& operator * (){
                    return node -> value;
                }

                T* operator -> (){
                    return &(node -> value);
                }           
            
        };

        preIterator begin_preorder(){
            return preIterator{root};
        }

        preIterator end_preorder(){
            return preIterator{root};
        }

        inIterator begin_inorder(){
            return inIterator{root};
        }

        inIterator end_inorder(){
            return inIterator{root};
        }

        postIterator begin_postorder(){
            return postIterator{root};
        }

        postIterator end_postorder(){
            return postIterator{root};
        }
        

        inIterator end(){
            return inIterator{root};
        }

        inIterator begin(){
            return inIterator{root};
        }

        
    };
}