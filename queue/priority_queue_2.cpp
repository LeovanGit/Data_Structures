#include <iostream>

// sort by priority when push
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
            if (front->priority > priority) // add to front
            {
                front = new Node <T> (data, priority, front);
            }
            else if (back->priority <= priority) // add to back
            {
                Node <T> * tmp = back;
                back = new Node <T> (data, priority);
                tmp->next = back;
            }
            else // add inside
            {
                Node <T> * place_after = front;
                
                for (size_t i = 0; i != size - 2; ++i)
                {
                    if (place_after->next->priority > priority) break;
                    place_after = place_after -> next;
                }

                place_after->next = new Node <T> (data, priority, place_after->next);
            }                        
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

    ~PQueue() { clear(); }

private:
    template <typename Type>
    class Node
    {
    public:
        explicit Node(Type data = Type(),
                      size_t priority = 0,
                      Node <Type> * next = nullptr) :
            data(data), priority(priority), next(next) {}

        Type data;
        size_t priority;
        Node <Type> * next;
    };

    Node <T> * front; // first
    Node <T> * back;  // last

    size_t size;
};
