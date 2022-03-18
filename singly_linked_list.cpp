#include <iostream>

template <typename T>
class List;

template <typename T>
class Node
{
    friend class List <T>;
    template <typename Type>
    friend std::ostream & operator<<(std::ostream & os, const List <Type> & list);

public:
    Node(T data) : data(data), next(nullptr) {}

    T getData() const { return data; }

private:
    T data;
    Node * next;
};

template <typename T>
class List
{
    // class template didnt work on friend declaration, so
    // you need to create another template 
    template <typename Type>
    friend std::ostream & operator<<(std::ostream & os, const List <Type> & list);

public:
    List() : head(nullptr), tail(nullptr) {}

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
    }

    void remove_first()
    {
        if (is_empty()) return;
        
        Node <T> * tmp = head;
        head = head->next;
        delete tmp;
    }

    void remove_last()
    {
        if (is_empty()) return;

        if (head == tail)
        {
            delete tail;
            head = nullptr;
            tail = nullptr;

            return;
        }

        Node <T> * tmp = head;
        while (tmp->next != tail) tmp = tmp->next;
        tmp->next = nullptr;
        delete tail;
        tail = tmp;
    }

    Node <T> * find(T data)
    {
        if (is_empty()) return nullptr;

        Node <T> * tmp = head;
        while(tmp && tmp->data != data) tmp = tmp->next;

        return tmp;
    }

    Node <T> * operator[](const size_t i)
    {
        if (is_empty()) return nullptr;

        size_t count = 0;
        Node <T> * tmp = head;
        while(tmp && count != i)
        {
            tmp = tmp->next;
            ++count;
        }

        return tmp;
    }

    void clear()
    {
        if (is_empty()) return;

        Node <T> * tmp = head;
        while(tmp)
        {
            Node <T> * current = tmp;
            tmp = tmp->next;
            delete current;
        }
        
        head = nullptr;
        tail = nullptr;
    }

    ~List() { clear(); }

private:
    Node <T> * head;
    Node <T> * tail;
};

template <typename T>
std::ostream & operator<<(std::ostream & os, const List <T> & list)
{
    if (!list.is_empty())
    {
        Node <T> * tmp = list.head;

        while (tmp != nullptr)
        {
            os << tmp->data << " -> ";
            tmp = tmp->next;
        }
    }

    return os;
}

// int main()
// {
//     List <int> list;
    
//     if (list.is_empty())
//     {
//         list.push_back(3);
//         list.push_back(-5);
//         list.push_back(8);
//         std::cout << list << "\n";

//         list.remove_first();
//         std::cout << list << "\n";

//         list.remove_last();
//         std::cout << list << "\n";

//         list.remove_first();
//         std::cout << list << "\n";

//         list.push_back(10);
//         std::cout << list << "\n";

//         list.remove_last();
//         std::cout << list << "\n";

//         list.push_back(0);
//         list.push_back(3);
//         list.push_back(11);
//         list.push_back(0);
//         std::cout << list << "\n";

//         std::cout << list[1]->getData() << "\n";

//         std::cout << list.find(3) << " " << list.find(0)->getData() << "\n";

//         list.clear();

//         if (list.is_empty()) std::cout << "CLEAR\n";
//     }

//     List <float> list_f;
//     list_f.push_back(3.5f);
//     list_f.push_back(-5.0f);
//     list_f.push_back(8.1f);
//     std::cout << list_f << "\n";


//     return 0;
// }
