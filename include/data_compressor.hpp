#include"../include/tree/binary_tree.hpp"
#include"../include/hash/hash.hpp"
#include"../include/index.hpp"

class DataCompressor{
    private:
        static List::LinkedList<Tree::BinaryTree<Index>>* get_forest();
        static Tree::BinaryTree<Index>* join_trees(List::Cell<Tree::BinaryTree<Index>> *a, List::Cell<Tree::BinaryTree<Index>> *b);
        
    public:
        static Hash<Index> indexes;
        static Tree::BinaryTree<Index>* index_tree;
        static void build_tree();
};

void print_index(Index* index);
void delegate_code(Index* index, char* code);
