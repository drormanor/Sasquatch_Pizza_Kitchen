#include "./include/Order.h"
//#include "Order.h"


#include<cassert>
#include<iostream>

Order::Order()
{
    node_count = 0;
    head_ptr = NULL;
}
Order::Order(const Order & list2bcopy)
{
    node_count = 0;
    head_ptr = NULL;

    this->head_insert(list2bcopy.getHeadPtr()->data());
    Node<Pizza>* dest_cursor = head_ptr;
    
    for(const Node<Pizza>* source_cursor = list2bcopy.getHeadPtr()->link(); source_cursor != NULL; source_cursor = source_cursor->link())
    {
        this->list_insert(dest_cursor, source_cursor->data());
        dest_cursor = dest_cursor->link();
    }

}
Node<Pizza>* Order::getHeadPtr()
{
    return head_ptr;
}

const Node<Pizza>* Order::getHeadPtr()const
{
    return head_ptr;
}

Node<Pizza>* Order::getTailPtr()
{
    return tail_ptr;
}
const Node<Pizza>* Order::getTailPtr()const
{
    return tail_ptr;
}

size_t Order::list_length() const
{
    return node_count;
}

bool Order::isEmpty() const
{
    return (head_ptr == NULL);
}

void Order::head_insert(const Node<Pizza>::value_type& value)
{
    if (head_ptr == NULL)
    {
        head_ptr = new Node<Pizza>(value);
        tail_ptr = head_ptr;

    } else {
        Node<Pizza>* temp = new Node<Pizza>(value, head_ptr);
        head_ptr = temp;
    }
    node_count++;
}

void Order::list_insert(Node<Pizza>* prev_ptr, const Node<Pizza>::value_type& value)
{
    Node<Pizza>* temp = new Node<Pizza>(value, prev_ptr->link());
    prev_ptr->set_link(temp);
    if(temp->link() == NULL) tail_ptr = temp;
    node_count++;

}




void Order::head_remove()
{
    if(!isEmpty())
    {
        Node<Pizza>* remove_ptr = head_ptr;
        head_ptr = head_ptr->link();
        delete remove_ptr;
    }
    if (node_count == 1) tail_ptr = head_ptr;
    node_count--;
}
void Order::list_remove(Node<Pizza>* prev_ptr)
{
    if(!isEmpty())
    {
        
        if(prev_ptr->link() != NULL ) 
        {
            Node<Pizza>* remove_ptr = prev_ptr->link();
            prev_ptr->set_link(prev_ptr->link()->link());
            delete remove_ptr;
            if (prev_ptr == NULL) tail_ptr = prev_ptr;
            if (node_count == 1) { tail_ptr = head_ptr; }
            node_count--;
        }
    }
}
void Order::clear_list()
{
    while(head_ptr != NULL)
    {
        this->head_remove();
    }   
}

void Order::operator=(const Order& source_list)
{
    this->head_insert(source_list.getHeadPtr()->data());
    Node<Pizza>* dest_cursor = head_ptr;
    
    for(const Node<Pizza>* source_cursor = source_list.getHeadPtr()->link(); source_cursor != NULL; source_cursor = source_cursor->link())
    {
        this->list_insert(dest_cursor, source_cursor->data());
        dest_cursor = dest_cursor->link();
    }
}

Order::~Order()
{
    this->clear_list();
}

void list_copy(const Order& source_list, Order& destination_list )
{
    if(source_list.isEmpty()) return;

    destination_list.head_insert(source_list.getHeadPtr()->data());

    const Node<Pizza>* source_cursor;
    Node<Pizza>* dest_cursor = destination_list.getHeadPtr();
    for (source_cursor = source_list.getHeadPtr()->link(); source_cursor != NULL; source_cursor = source_cursor->link())
    {
                destination_list.list_insert(dest_cursor, source_cursor->data());
                dest_cursor = dest_cursor->link();
    }
    dest_cursor->set_link(NULL);
}



