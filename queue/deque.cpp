#include <iostream>

template <typename T>
class Deque
{
public:
    Deque() : left(nullptr), right(nullptr), size(0) {}

    bool isEmpty() const { return left == nullptr; }
    size_t getSize() const { return size; }

    void push_front(T data)
    {
        if (isEmpty())
        {
            left = new Node <T> (data);
            right = left;
        }
        else
        {
            left = new Node <T> (data, left);
            left->next->prev = left;
        }

        ++size;
    }

    T pop_front()
    {
        Node <T> * to_delete = left;
        T value = to_delete->data;
        left = left->next;        
        delete to_delete;
        
        if (size == 1) right = nullptr;
        else left->prev = nullptr;

        --size;
        return value;
    }

    void push_back(T data)
    {
        if (isEmpty())
        {
            right = new Node <T> (data);
            left = right;
        }
        else
        {
            right = new Node <T> (data, nullptr, right);
            right->prev->next = right;
        }

        ++size;
    }

    T pop_back()
    {
        Node <T> * to_delete = right;
        T value = to_delete->data;
        right = right->prev;
        delete to_delete;
        
        if (size == 1) left = nullptr;
        else right->next = nullptr;

        --size;
        return value;
    }

    void clear() { while(size) pop_front(); }

    ~Deque() { clear(); }

private:
    template <typename Type>
    class Node
    {
    public:
        Node(Type data = Type(), 
             Node <Type> * next = nullptr,
             Node <Type> * prev = nullptr) :
            data(data), next(next), prev(prev) {}

        Type data;
        Node <Type> * next;
        Node <Type> * prev;
    };

    Node <T> * left;
    Node <T> * right;
    size_t size;
};
