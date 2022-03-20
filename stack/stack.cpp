#include <iostream>

// Last In First Out
template <typename T>
class Stack
{
public:
    Stack() : top(nullptr), size(0) {}
    
    size_t getSize() const { return size; }

    bool is_empty() const { return top == nullptr; }

    T getTop() const { return top->data; }

    void push_back(T data)
    {
        if (is_empty()) top = new Node <T> (data);
        else top = new Node <T> (data, top);
        ++size;
    }

    T pop_back()
    {
        Node <T> * to_delete = top;
        T value = to_delete->data;
        top = top->prev;
        delete to_delete;
        --size;
        return value;
    }

    void clear()
    {
        while (size) pop_back();
    }

    ~Stack() { clear(); }

private:
    template <typename Type>
    class Node
    {
        public:
            explicit Node(Type data, Node * prev = nullptr) :
                data(data), prev(prev) {}
        
        Type data;
        Node * prev;
    };
    
    Node <T> * top;
    size_t size;
};
