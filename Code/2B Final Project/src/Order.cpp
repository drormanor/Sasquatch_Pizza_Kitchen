#include "./include/Order.h"
//#include "Order.h"

#include <cassert>
#include <iostream>

Order::Order()
{
    pizza_count = 0;
    head_ptr = NULL;
}

void Order::set_phone(string phone)
{
    customer_phone = phone;
}

void Order::set_name(string name)
{
    customer_name = name;
}
void Order::set_cookTime(int cookTime)
{
    this->cook_time = cook_time;
}

string Order::get_phone(string phone) const
{
    return customer_phone;
}
string Order::get_name(string name) const
{
    return customer_name;
}

int Order::get_cookTime() const
{
    return cook_time;
}

Node<Pizza> *Order::getHeadPtr()
{
    return head_ptr;
}

const Node<Pizza> *Order::getHeadPtr() const
{
    return head_ptr;
}

size_t Order::list_length() const
{
    return pizza_count;
}

bool Order::isEmpty() const
{
    return (head_ptr == NULL);
}

void Order::head_insert(const Node<Pizza>::value_type &value)
{
    if (head_ptr == NULL)
    {
        head_ptr = new Node<Pizza>(value);
    }
    else
    {
        Node<Pizza> *temp = new Node<Pizza>(value, head_ptr);
        head_ptr = temp;
    }
    pizza_count++;
}

void Order::head_remove()
{
    if (!isEmpty())
    {
        Node<Pizza> *remove_ptr = head_ptr;
        head_ptr = head_ptr->link();
        delete remove_ptr;
    }
    
        pizza_count--;
}

void Order::clear_list()
{
    while (head_ptr != NULL)
    {
        this->head_remove();
    }
}

void Order::take_order()
{
    string name, phone;
    cout << "Please enter the customer name: ";
    cin >> name;
    set_name(name);
    cout << "Please enter the customer phone number: ";
    cin >> phone;
    set_phone(phone);

    char check = 'y';

    while (tolower(check) == 'y')
    {
        cout << "Add a pizza:\n";
        add_pizza();
        
        cout << "Would you like to add another pizza? y/n";
        cin >> check;
    }

}

// HERE!!!!!!
void Order::print_order()
{
}
bool Order::is_ready()
{
}
bool Order::is_delivered()
{
}
Order::~Order()
{
    this->clear_list();
}

void Order::add_pizza()
{
    Pizza *temp = new Pizza;
    char pizza_size;
    size_type topping;
    cout << "Please select the size of pizza (s for small, m for medium, or l for large): ";
    cin >> pizza_size;
    temp->set_pizza_size(tolower(pizza_size));

    if (cooking_time[pizza_size] > order_time) 
        {
            order_time = cooking_time[pizza_size];
        }

    cout << "Please choose up to 5 toppings (cheese and sauce are included)\n";
    cout << "If you are done or do not want extra toppings choose 0\n\n";

    size_type i = 0;
    while (i < Max_toppings)
    {
        print_topping_list();
        cout << "Enter the toping code: ";
        cin >> topping;
        if (topping == 0)
        {
            return;
        }
        else if (topping > Topping_list_size - 1)
        {
            cout << "\n\nYou have enterd a incorrect code. please try again!!!\n\n";
            continue;
        }
        else
        {
            if (temp->add_topping(toppings[topping]))
                i++;
            else
                cout << "you already have 5 toppings\n";
            return;
        }

        head_insert(*temp);
    }
}
void Order::print_topping_list() const
{
    cout << "Code\t\t\tTopping\n";
    cout << "-----------------------------\n";
    for (size_type i = 1; i < Topping_list_size; i++)
    {
        cout << "\t" << i << "\t\t" << toppings[i] << endl;
    }
    cout << "-----------------------------\n";
}
