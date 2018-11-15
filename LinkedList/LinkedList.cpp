#include <iostream>
using namespace std;

template<typename T>
struct Node
{
    Node<T>* next;
    T data;
    Node(const T& _data,Node<T>* _next = nullptr)
    {
        this->data = _data;
        this->next = _next;
    }
};


template<typename T>
class LinkedList
{
public:
    LinkedList()
    {
        this->first = this->last = nullptr;
        this->size = 0;
    }
    LinkedList(const LinkedList& other)
    {
        this->copy(other);
    }
    LinkedList& operator=(const LinkedList& other)
    {
        if(this != &other)
        {
            this->erase();
            this->copy(other);
        }
        return *this;
    }
    ~LinkedList()
    {
        this->erase();
    }
    void pushBack(const T& _data)
    {
        Node<T>* toAdd = new Node<T>(_data,nullptr);
        if(this->isEmpty())
        {
            this->first = this->last = toAdd;
        }
        else
        {
            this->last->next = toAdd;
            this->last = toAdd;
        }
        this->size++;
    }
    void pushFront(const T& _data)
    {
        Node<T>* toAdd = new Node<T>(_data,nullptr);
        if(this->isEmpty())
        {
            this->first = this->last = toAdd;
        }
        else
        {
            toAdd->next = this->first;
            this->first = toAdd;
        }
        this->size++;
    }
    void popBack()
    {
        Node<T>* temp = this->first;
        Node<T>* toDel;
        while(temp != this->last)
        {
            temp = temp->next;
        }
        toDel = temp->next;
        last = temp;
        delete toDel;
        size--;
    }
    void popFront()
    {
        Node<T>* temp = this->first;
        this->first = this->first->next;
        delete temp;
        size--;
    }
    size_t getSize() const
    {
        return this->size;
    }
    bool isEmpty()
    {
        return this->size == 0;
    }
    void print ()
    {
        Node<T>* temp = this->first;
        for(size_t i=0; i<this->size; i++)
        {
            cout<<temp->data<<endl;
            temp = temp->next;
        }
        cout<<"Size: "<<this->size<<endl;
    }
    T getFirstElement() const
    {
        return this->first->data;
    }
    T getLastElement() const
    {
        return this->last->data;
    }
    void insertAt(const T& _data,size_t index)
    {
        if(index < 0 || index > this->size) throw "Invalid index";
        else
        {
            Node<T>* temp = this->first;
            Node<T>* toInsert = new Node<T>(_data);     // 5 6 4 7
            for(size_t i=0; i<index-2; i++)
            {
                temp = temp->next;
            }
            toInsert->next = temp->next;
            temp->next = toInsert;
            this->size++;
        }
    }
    void popAt(size_t index)
    {
        if(index < 0 || index > this->size) throw "Invalid index";
        Node<T>* temp = this->first;
        Node<T>* toDel;
        for(size_t i=0; i<index-2; i++)
        {
            temp = temp->next;
        }
        toDel = temp->next;
        temp->next = temp->next->next;
        delete toDel;
        this->size--;
    }
    void changeDataAt(size_t index,const T& _data)
    {
      if(index < 0 || index > this->size) throw "Invalid index";
      Node<T>* temp = this->first;
      for(size_t i=0; i<index-1; i++)
      {
          temp = temp->next;
      }
      temp->data = _data;
    }
private:
    size_t size;
    Node<T>* first;
    Node<T>* last;
    void erase()
    {
        while(this->size !=0)
        {
            this->popBack();
        }
    }
    void copy(const LinkedList& other)
    {
        if(other.getSize() == 0)
        {
            this->first = this->last = nullptr;
        }
        else
        {
            Node<T>* temp = other.first;
            this->pushBack(temp->data);
            while(temp->next)
            {
                temp = temp->next;
                this->pushBack(temp->data);
            }
        }
        this->size = other.getSize();
    }
};


int main()
{


    return 0;
}
