#include <iostream>

// realization using nested class
// and methods was renamed according to STL
template <typename T>
class List
{
public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    size_t getSize() const { return size; }

    bool is_empty() const { return head == nullptr; }

    void push_back(T data)
    {
        Node <T> * node = new Node <T> (data);

        if (is_empty())
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }

        ++size;
    }

    void push_front(T data)      
    {
        Node <T> * tmp = new Node <T> (data, head);
        if (is_empty()) tail = tmp;
        head = tmp;
        ++size;        
    }

    void pop_front()
    {
        Node <T> * tmp = head;
        head = head->next;
        delete tmp;
        --size;
    }

    void pop_back()
    {
        removeAt(size - 1);
    }

    void insert(T data, size_t i)
    {
        if (i == 0)
        {
            push_front(data);
            return;
        }

        Node <T> * tmp = find(i - 1);
        tmp->next = new Node <T> (data, tmp->next);
        ++size;
    }

    void removeAt(size_t i)
    {
        if (i == 0)
        {
            pop_front();
            return;
        }

        Node <T> * tmp = find(i - 1);
        Node <T> * to_delete = tmp->next;
        tmp->next = to_delete->next;
        delete to_delete;
        --size;
    }

    void clear()
    {
        while (size) pop_front();
        tail = nullptr;
        size = 0;
    }
    
    T& operator[](const size_t i)
    {
        size_t count = 0;
        Node <T> * tmp = head;

        while(tmp && count != i)
        {
            tmp = tmp->next;
            ++count;
        }

        return tmp->data;
    }

    ~List() { clear(); }

private:
    template <typename Type>
    class Node
    {
    public:
        // Type() - call type's default constructor, because we dont know which type is it
        explicit Node(Type data = Type(), Node * next = nullptr) : data(data), next(next) {}

        Type data;
        Node * next;
    };

    Node <T> * head;
    Node <T> * tail;

    size_t size;

    Node <T> * find(size_t i)
    {
        Node <T> * tmp = head;
        for (size_t j = 0; j != i; ++j)
        {
            tmp = tmp->next;
        }
        return tmp;
    }
};

