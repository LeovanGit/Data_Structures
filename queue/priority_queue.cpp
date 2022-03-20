#include <iostream>

// find most priority element when pop
template <typename T>
class PQueue
{
public:
    PQueue() : front(nullptr), back(nullptr), size(0) {}

    T getFront() const { return front->data; }
    T getBack() const { return back->data; }

    bool is_empty() const { return front == nullptr; }
    size_t getSize() const { return size; }

    void push(T data, size_t priority)
    {
        if (is_empty())
        {
            front = new Node <T> (data, priority);
            back = front;
        }
        else
        {
            back->next = new Node <T> (data, priority, nullptr, back);
            back = back->next;
        }

        ++size;
    }

    T pop()
    {
        Node <T> * to_delete = find_most_priority();
        T value = to_delete->data;

        --size;

        // remain 1 Node
        if (front == back)
        {            
            delete to_delete;
            front = nullptr;
            back = front;
            return value;
        }

        // most priority is front
        if (front == to_delete)
        {
            front = front->next;
            to_delete->next->prev = nullptr;
            delete to_delete;
            return value;
        }

        // most priority is back
        if (back == to_delete)
        {
            back = back->prev;
            to_delete->prev->next = nullptr;
            delete to_delete;
            return value;
        }
        
        to_delete->prev->next = to_delete->next;
        to_delete->next->prev = to_delete->prev;
        delete to_delete;
        return value;
    }
    
    void clear()
    {
        while (size) pop();
    }

    ~PQueue() { clear(); }

private:
    template <typename Type>
    class Node
    {
    public:
        explicit Node(Type data = Type(),
                      size_t priority = 0,
                      Node <Type> * next = nullptr,
                      Node <Type> * prev = nullptr) :
            priority(priority), data(data), next(next), prev(prev) {}

        size_t priority; // lower value more priority
        Type data;
        Node <Type> * next;
        Node <Type> * prev; 
    };

    Node <T> * front; // first
    Node <T> * back;  // last
    size_t size;

    Node <T> * find_most_priority()
    {
        Node <T> * tmp = front->next;
        Node <T> * max = front;

        for (size_t i = 0; i != size - 1; ++i)
        {
            if (tmp->priority < max->priority) max = tmp;
            tmp = tmp->next;
        }

        return max;
    }
};

