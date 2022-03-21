#include <iostream>

template <typename T>
class BTree
{
public:
    BTree() : root(nullptr), size(0) {}

    bool isEmpty() const { return root == nullptr; }

    size_t getSize() const { return size; }

    void push(T data) { add(data, &root); }

    void pop(T data) 
    { 
        root = del(data, root); 
        --size;
    }
    
    void show() { print(root); }

    void clear() { while(size) pop(root->data); }

    ~BTree() { clear(); };

private:
    template <typename Type>
    class Node
    {
    public:
        Node(Type data = Type(),
             Node <Type> * left = nullptr,
             Node <Type> * right = nullptr) :
             data(data), left(left), right(right) {}
    
        Type data;
        Node <Type> * left;
        Node <Type> * right;
    };

    Node <T> * root;
    size_t size;

    void add(T data, Node <T> ** node)
    {
        if (*node == nullptr)
        {
            *node = new Node <T> (data);
            ++size;
            return;
        }
                
        if (data > (*node)->data) add(data, &(*node)->right);
        else if (data < (*node)->data) add(data, &(*node)->left);
    }

    // recursion call of sub-trees which on the way to node which we need to delete
    // and changes roots left or right pointer if its child was deleted
    Node <T> * del(T data, Node <T> * node)
    {
        if (data > node->data) node->right = del(data, node->right);
        else if (data < node->data) node->left = del(data, node->left);
        else // found Node which need to delete
        {
            // leaf
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                node = nullptr;
            }
            else if (node->right == nullptr) // only left child
            {
                Node <T> * to_delete = node;
                node = node->left;
                delete to_delete;           
            }
            else if (node->left == nullptr) // only right child
            {
                Node <T> * to_delete = node;
                node = node->right;
                delete to_delete;           
            }
            else // if both children
            {
                // we need set as new root Node with value which more than all values from left branch
                // and less than all values from rigth branch
                // so its most left Node from right branch (smallest value from right branch)
                Node <T> * min = node->right;
                while (min->left) min = min->left;

                // just change values is easier than nodes
                node->data = min->data;
                // delete min, but starts from new root right branch
                node->right = del(min->data, node->right);
            }            
        }

        return node;
    }

    void print(Node <T> * node)
    {
        if (node == nullptr) return;

        std::cout << node->data << " ";
        print(node->left);
        print(node->right);
    }
};
