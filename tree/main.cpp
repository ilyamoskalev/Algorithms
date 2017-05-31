#include <iostream>
#include <cassert>

struct BinaryTreeNode {

    BinaryTreeNode(const int &data)
            :_data(data), _left(nullptr), _right(nullptr) {}

    ~BinaryTreeNode() {
        delete _left;
        delete _right;
    }

    int _data;
    BinaryTreeNode* _left;
    BinaryTreeNode* _right;
};

class BinaryTree {

public :
    BinaryTree()
            :_root(nullptr) {}

    ~BinaryTree() {
        delete _root;
    }

    void TraverseDFS(){
        TraverseDFS(_root);
    }

    void add(const int &data);


private :
    void TraverseDFS(BinaryTreeNode* node);

    BinaryTreeNode* _root;
};


void BinaryTree::add(const int &data) {
    BinaryTreeNode* node = new BinaryTreeNode(data);
    if (_root == nullptr) {
        _root = node;
        return;
    }
    BinaryTreeNode* nextNode = _root;
    while (true) {
        if (data < nextNode->_data) {
            if (nextNode->_left != nullptr) {
                nextNode = nextNode->_left;
            } else {
                nextNode->_left = node;
                return;
            }
        } else {
            if (nextNode->_right != nullptr) {
                nextNode = nextNode->_right;
            } else {
                nextNode->_right = node;
                return;
            }
        }
    }
}


void BinaryTree::TraverseDFS(BinaryTreeNode* node) {
    if( node == nullptr )
        return;
    TraverseDFS( node->_left );
    TraverseDFS( node->_right );
    std::cout << node->_data << ' ';
};


int main() {
    int count = 0;
    std::cin >> count;
    assert( count > 0);
    BinaryTree tree;
    for(int i = 0; i < count; ++i){
        int tmp = 0;
        std::cin >> tmp;
        tree.add(tmp);
    }
    tree.TraverseDFS();
    return 0;
}