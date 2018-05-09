/*
    Author: Jordan Laidig
    Description: The Templated Node class that was provided.
    Date: 4/5/18
*/
#ifndef NODE_H
#define NODE_H
#include <cstdlib>
using namespace std;

template <class Item>
class Node
{
    public:
        typedef Item value_type;
        // CONSTRUCTOR
        Node(const Item& init_data=Item(), Node* init_link=NULL)
        {data_field = init_data; link_field = init_link;}
        Item& data() {return data_field;}
        Node* link() {return link_field;}
        void set_data(const Item& new_data) {data_field = new_data;}
        void set_link(Node* new_link) {link_field = new_link;}
        // CONST MEMBER FUNCTIONS
        const Item& data() const {return data_field;}
        const Node* link() const {return link_field;}
    private:
        Item data_field;
        Node *link_field;
};

#endif // NODE_H
