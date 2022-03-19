#include <iostream>

using namespace std;

template <class T>
class Elem
{
public:
    T item;
    Elem* next;
    Elem* prev;
};

template <class T>
class List
{
private:
    Elem<T> *first;
    Elem<T> *last;
    int counter;
public:
    List()
    {
        first = NULL;
        last = NULL;
        counter = 0;
    };

    List(const T& src)
    {
        first = src->first;
        last = src->last;
        counter = src->counter;
    };
    
    ~List()
    {
        Elem<T>* p = first;    
        while(p != last->next) 
        {                      
            Elem<T>* temp = p; 
            p = p->next;       
            delete temp;       
        }
    };
    
    int entries()
    {
        return counter;
    }

    //return without remove
    T returnfirst()
    {
        return first->item;
    };

    T returnlast()
    {
        return last->item;
    };

    //return with remove
    T removefirst()
    {
        Elem<T>* temp = first;
        temp->next->prev = NULL;
        first = temp->next;
        T item;
        item = temp->item;
        delete temp;
        counter--;
        return item;
    };

    T removelast()
    {
        Elem<T>* temp = last;
        temp->prev->next = NULL;
        last = temp->prev;
        T item;
        item = temp->item;
        delete temp;
        counter--;
        return item;
    };

    //adding element
    void addfirst(T nitem)
    {
        Elem<T>* temp = new Elem<T>;
        if(temp == NULL)
            exit(1);
        temp->item = nitem;
        temp->next = this->first;
        temp->prev = NULL;
        if(counter == 0)
        {
            this->first = temp;
            this->last = temp;
        }
        else
        {
            this->first->prev = temp;
            this->first = temp;
        }
        counter++;
    }

    void addlast(T nitem)
    {
        Elem<T>* temp = new Elem<T>;
        if(temp == NULL)
            exit(1);
        temp->item = nitem;
        temp->next = NULL;
        temp->prev = this->last;
        if(counter == 0)
        {
            this->first = temp;
            this->last = temp;
        }
        else
        {
            this->last->next = temp;
            this->last = temp;
        }
        counter++;
    }

    void print()
    {
        for(Elem<T>* p = first; p != last->next; p = p->next)
        {
            cout << p->item << " ";
        }
        cout << endl;
    }
};