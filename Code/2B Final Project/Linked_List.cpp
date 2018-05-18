#include "Linked_List.h"
/*
    Author: Jordan Laidig
    Title: Linked_List
    Description: The default constructor that creates an empty list.
    Date: 3/8/18
*/
Linked_List::Linked_List()
{
    head_ptr = NULL;
    tail_ptr = NULL;
    node_count = 0;
}
/*
    Author: Jordan Laidig
    Title: Linked_List
    Description: The copy constructor that allows a list
    to be created using the values from another list.
    Date: 3/13/18
*/
Linked_List::Linked_List(const Linked_List& l)
{
    head_ptr = NULL;
    tail_ptr = NULL;
    node_count = 0;
    const Node<Order>* cursor;
    for(cursor = l.getHeadPtr(); cursor != NULL; cursor = cursor->link())
    {
        list_insert(tail_ptr,cursor->data());
    }
}
/*
    Author: Jordan Laidig
    Title: ~Linked_List
    Description: The default constructor that uses the clear_list
    function to delete all the data in the list.
    Date: 3/13/18
*/
Linked_List::~Linked_List()
{
    clear_list();
}
/*
    Author: Jordan Laidig
    Title: head_insert
    Description: Inserts a node at the beginning of the list.
    Date: 3/8/18
*/
void Linked_List::head_insert(const Node<Order>::value_type& value)
{
    Node<Order> *n = new Node<Order>(value);
    if(head_ptr == NULL)
    {
        head_ptr = n;
        tail_ptr = n;
    }
    else
    {
        n->set_link(head_ptr);
        head_ptr = n;
    }
    node_count++;
    return;
}
/*
    Author: Jordan Laidig
    Title: list_insert
    Description: puts a node after the given node and adds it into the list.
    Date: 3/8/18
*/
void Linked_List::list_insert(Node<Order>* prev_ptr, const Node<Order>::value_type& value)
{
    Node<Order> *n = new Node<Order>(value);
    if(head_ptr == NULL)
    {
        head_ptr = n;
        tail_ptr = n;
    }
    else if(prev_ptr == tail_ptr)
    {
        n->set_link(prev_ptr->link());
        prev_ptr->set_link(n);
        tail_ptr = n;
    }
    else
    {
        n->set_link(prev_ptr->link());
        prev_ptr->set_link(n);
    }
    node_count++;
    return;
}
/*
    Author: Jordan Laidig
    Title: list_copy
    Description: This function takes in one linked list and then copies it into another one.
    The data stays the smae but the memory locations are different.
    Date: 3/12/18
*/
void list_copy(const Linked_List& source_list, Linked_List& destination_list)
{
    const Node<Order>* cursor;
    for(cursor = source_list.getHeadPtr(); cursor != NULL; cursor = cursor->link())
    {
        if(destination_list.getHeadPtr() == NULL)
        {
            destination_list.head_insert(cursor->data());
        }
        else
        {
            destination_list.list_insert(destination_list.getTailPtr(),cursor->data());
        }
    }
    return;
}
/*
    Author: Jordan Laidig
    Title: head_remove
    Description: Removes the node at the front of the list.
    Date: 3/13/18
*/
void Linked_List::head_remove()
{
    if(head_ptr == NULL) //checks if the list is empty.
    {
        return;
    }
    else if(node_count == 1) //checks if there is only one node in the list.
    {
        delete head_ptr;
        head_ptr = NULL;
        tail_ptr = NULL;
    }
    else
    {
        Node<Order>* remove_ptr = head_ptr;
        head_ptr = head_ptr->link();
        delete remove_ptr;
    }
    node_count--; //lowers the count of nodes in the list.
    return;
}
/*
    Author: Jordan Laidig
    Title: list_remove
    Description: Removes the Node after the Node that is passed in.
    Date: 3/13/18
*/
void Linked_List::list_remove(Node<Order>* prev_ptr)
{
    if(node_count == 1 || node_count == 0)
    {
        return;
    }
    else if(prev_ptr == tail_ptr)
    {
        return;
    }
    else if(prev_ptr->link() == tail_ptr)
    {
        Node<Order>* remove_ptr = prev_ptr->link();
        prev_ptr->set_link(remove_ptr->link());
        delete remove_ptr;
        tail_ptr = prev_ptr;
    }
    else
    {
        Node<Order>* remove_ptr = prev_ptr->link();
        prev_ptr->set_link(remove_ptr->link());
        delete remove_ptr;
    }
    node_count--;
    return;
}
/*
    Author: Jordan Laidig
    Title: clear_list
    Description: Removes all Nodes in the list.
    Date: 3/13/18
*/
void Linked_List::clear_list()
{
    while(node_count != 0)
    {
        head_remove();
    }
    return;
}
/*
    Author: Jordan Laidig
    Title: operator=
    Description: The overloaded assignment operator that allows you to set one list's data equal to another.
    Date: 3/13/18
*/
void Linked_List::operator=(const Linked_List& list1)
{
    clear_list();
    const Node<Order>* cursor;
    for(cursor = list1.getHeadPtr(); cursor != NULL; cursor = cursor->link())
    {
        if(head_ptr == NULL)
        {
            head_insert(cursor->data());
        }
        else
        {
            list_insert(tail_ptr,cursor->data());
        }
    }
    return;
}
/*
    Author: Jordan Laidig
    Title: print_list
    Description: Prints out all the orders in the list.
    Date: 5/18/18
*/
void Linked_List::print_list()
{
    cout << "The Sasquatch Pizza Kitchen";
    cout << "Orders that are completed: \n";
    if(head_ptr == NULL)
        return;
    for(Node<Order>* cursor = head_ptr; cursor != NULL; cursor = cursor->link())
    {
        if(cursor->data().is_ready() == true)
            cursor->data().print_order();
    }
    cout << "\nOrders that are in progress: \n";
    for(Node<Order>* cursor = head_ptr; cursor != NULL; cursor = cursor->link())
    {
        if(cursor->data().is_ready() == false)
            cursor->data().print_order();
    }

}
/*
    Author: Jordan Laidig
    Title: delivery_check
    Description: Checks to see if an order in the list is delivered and then deletes it from the list.
    Date: 5/18/18
*/
void Linked_List::delivery_check()
{
    if(head_ptr == NULL)
        return;
    Node<Order>* cursor = head_ptr;
    if(cursor->data().is_delivered() == true)
        head_remove();
    while(cursor->link() != NULL)
    {
        if(cursor->link()->data().is_delivered() == true)
            list_remove(cursor);
        cursor = cursor->link();
    }
}
/*
    Author: Jordan Laidig
    Title: create_order
    Description: Uses the order classes take order function in order to add an order to the list.
    Date: 5/18/18
*/
void Linked_List::create_order()
{
    Order *temp = new Order;
    temp->take_order();
    list_insert(tail_ptr, *temp);
}
