#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Order.h"

class Linked_List
{
    public:
        typedef Node<Order>::value_type data_type;
        typedef size_t size_type;
        // Constructor creates an empty list
        // Summary: Constructor creates a linked list object with count set at 0 and pointers set to NULL.
        Linked_List();
        Linked_List(const Linked_List& l);
        ~Linked_List();
        // Accessor functions for the list's head_ptr
        // Summary: Returns a pointer to the head Node of the list.
        Node<Order>* getHeadPtr() {return head_ptr;}
        // Summary: Returns a pointer to the head Node of the list.
        const Node<Order>* getHeadPtr()const {return head_ptr;}
        // Accessor functions for the list's tail_ptr
        // Summary: Returns a pointer to the end Node of the list.
        Node<Order>* getTailPtr() {return tail_ptr;}
        // Summary: Returns a pointer to the end Node of the list.
        const Node<Order>* getTailPtr()const {return tail_ptr;}

        // Summary: This function returns the number of Nodes in the list.
        size_type list_length() const {return node_count;}

        // Summary: This function returns true if the list is empty.
        bool isEmpty() const {return (node_count == 0);}
        void head_insert(const Node<Order>::value_type& value);
        void list_insert(Node<Order>* prev_ptr, const Node<Order>::value_type& value);
        void head_remove();
        void list_remove(Node<Order>* prev_ptr);
        void clear_list();
        void operator=(const Linked_List& list1);
    private:
        Node<Order>* head_ptr;
        Node<Order>* tail_ptr;
        size_type node_count;
};
void list_copy(const Linked_List& source_list, Linked_List& destination_list);

#endif // LINKED_LIST_H