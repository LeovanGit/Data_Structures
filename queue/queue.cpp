#include <iostream>

// First In First Out
template <typename T>
class Queue
{
public:
    Queue() : front(nullptr), back(nullptr), size(0) {}

    T getFront() const { return front->data; }
    T getBack() const { return back->data; }

    bool is_empty() const { return front == nullptr; }
    size_t getSize() const { return size; }

    void push(T data)
    {
        if (is_empty())
        {
            front = new Node <T> (data);
            back = front;
        }
        else
        {
            back->next = new Node <T> (data);
            back = back->next;
        }

        ++size;
    }

    T pop()
    {
        Node <T> * to_delete = front;
        T value = to_delete->data;
        front = front->next;
        delete to_delete;
        --size;

        if (size == 0) back = nullptr;
        return value;
    }
    
    void clear()
    {
        while (size) pop();
    }

    ~Queue() { clear(); }

private:
    template <typename Type>
    class Node
    {
    public:
        explicit Node(Type data = Type(), Node <Type> * next = nullptr) :
            data(data), next(next) {}

        Type data;
        Node <Type> * next;
    };

    Node <T> * front; // first
    Node <T> * back;  // last

    size_t size;
};
