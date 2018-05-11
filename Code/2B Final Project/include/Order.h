#include "Node.h"
#include "Pizza.h"
#include <cstdlib>

using namespace std;
class Order
{
    public:
        typedef Node<Pizza>::value_type data_type;
        typedef size_t size_type;
        // Constructor creates an empty list
        // ******************************************************************************************
        Order();
        // Summary: Constructor creates a linked list object with count set at 0.
        // ******************************************************************************************
        Order(const Order & list2bcopy);
        // Summary:  copy constructor creates a linked list object with count set at 0
        // and copy all of list2bcopy into it.
        // ******************************************************************************************
        
        // Accessor functions for the list's head_ptr
        // ******************************************************************************************
        Node<Pizza>* getHeadPtr();
        // Summary: Returns a pointer to the head Node of the list.
        // Preconditions: The list has been initialized.
        // Postconditions: A pointer to the head has been returned.
        // ******************************************************************************************
        // ******************************************************************************************
        const Node<Pizza>* getHeadPtr()const;
        // Summary: Returns a pointer to the head Node of the list.
        // Preconditions: The list has been initialized.
        // Postconditions: A pointer to the head has been returned.
        // ******************************************************************************************
        //
        // Accessor functions for the list's tail_ptr
        // ******************************************************************************************
        Node<Pizza>* getTailPtr();
        const Node<Pizza>* getTailPtr()const;
        // Summary: Returns a pointer to the end Node of the list.
        // Preconditions: The list has been initialized.
        // Postconditions: A pointer to the end of the list has been returned.
        // ******************************************************************************************
        // ******************************************************************************************
        size_type list_length() const;
        // Summary: This function returns the number of Nodes in the list.
        // Preconditions:  A list exists
        // Postconditions: Returns 0 if list is empty, otherwise it returns the number of items  in the list, i.e. count
        // ******************************************************************************************
        // ******************************************************************************************
        bool isEmpty() const;
        // Summary: This function returns true if the list is empty.
        // Preconditions:  A list object exists
        // Postconditions: Returns true if the list contains no Nodes and false if the list contains at least one Node.
        // ******************************************************************************************
        // ******************************************************************************************
        void head_insert(const Node<Pizza>::value_type& value);
        // Summary: This function inserts a new Node at the beginning of the list.
        // Preconditions:  A head_ptr exists and a new value has been passed in.
        // Postconditions: A new Node has been added to the beginning of the list with the value in the data_field at the head of the list.
        // ******************************************************************************************
        // ******************************************************************************************
        void list_insert(Node<Pizza>* prev_ptr, const Node<Pizza>::value_type& value);
        // Summary: This function inserts a new Node with value in the data field after the prev_ptr Node.
        // Preconditions: prev_ptr is a pointer to the Node that is before the the spot where we want to insert a new Node with data equal to value.
        // Postconditions: The list with one more Node that contains the value passed into the function.
        // ******************************************************************************************
        // ******************************************************************************************

        void head_remove();
        // Summary: This function removes the Node at the beginning of the list.
        // Preconditions: There is a list with head_ptr pointing to the beginning
        // of the list.
        // Postconditions: We have a list with the previous head Node of the list
        // removed.
        // *********************************************************************
        // *********************************************************************
        void list_remove(Node<Pizza>* prev_ptr);
        // Summary: This function removes the Node after the prev_ptr Node.
        // Preconditions: prev_ptr is a Node pointer that points to the Node
        // before the Node we want to delete.
        // Postconditions: The list has had one Node removed that use to be after
        // the Node pointed to by prev_ptr
        // *********************************************************************
        // *********************************************************************
        void clear_list();
        // Summary: This function empties the list.
        // Preconditions: There is a current list.
        // Postconditions: list has been cleared of Nodes. head_ptr now is NULL.
        // *********************************************************************
        // *********************************************************************
        void operator= (const Order& source_list);
        //  Summary: will clear list and copy source list nodes into list.
        // Preconditions: source list must not be empty.
        // postconditions: list will be be populated with copies of source 
        // list nodes

        ~Order();
        // Summary: The destructor empties the list.
        // *********************************************************************
        

        private:
             Node<Pizza>* head_ptr; // Points to front of list
             Node<Pizza>* tail_ptr; // Points to end of list
             size_type node_count;   // holds the number of Nodes in the list
 };

        // Non Member Functions
        // *********************************************************************
        void list_copy(const Order& source_list, Order& destination_list );
        //  summary: will copy all nodes from source list to destination list
        //  in the same order
        // *********************************************************************
