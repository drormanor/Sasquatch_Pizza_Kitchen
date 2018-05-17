#include "Order.h"
#include <iomanip>

#include <cassert>
#include <iostream>

Order::Order()
{
    pizza_count = 0;
    head_ptr = NULL;
    cook_time = 0;
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
void Order::list_insert(Node<Pizza> *prev_ptr, const Node<Pizza>::value_type &value)
{
    Node<Pizza> *temp = new Node<Pizza>(value, prev_ptr->link());
    prev_ptr->set_link(temp);
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
void Order::operator=(const Order &source_list)
{
    this->head_insert(source_list.getHeadPtr()->data());
    Node<Pizza> *dest_cursor = head_ptr;

    for (const Node<Pizza> *source_cursor = source_list.getHeadPtr()->link(); source_cursor != NULL; source_cursor = source_cursor->link())
    {
        this->list_insert(dest_cursor, source_cursor->data());
        dest_cursor = dest_cursor->link();
    }
}
void Order::take_order()
{
    string name, phone;
    cout << "Please enter the customer name: ";
    getline(cin, name);
    set_name(name);
    cout << "Please enter the customer phone number: ";
    getline(cin, phone);
    set_phone(phone);

    char check = 'y';

    while (tolower(check) != 'n')
    {

        cout << "Add a pizza:\n";
        add_pizza();

        cout << "Would you like to add another pizza? y/n ";
        cin >> check;
        while (!(tolower(check) == 'n' || tolower(check) == 'y'))
        {
            cout << "You have enterd the wrong answer!!!\n";
            cout << "Would you like to add another pizza??? y/n ";
            cin >> check;
        }
    }
    set_start_time();
    print_order();
}

void Order::print_order()
{

    cout << setw(15) << left << customer_name;
    cout << setw(15) << left << customer_phone;
    cout << setw(22) << left << ctime(&order_time);
    cout << "Order will be ready in " << cook_time - (time(NULL) - order_time) << " min." << endl;

    cout << "order detail:" << endl;

    Node<Pizza> *cursor = head_ptr;
    while (cursor != NULL)
    {

        cursor->data().print_Pizza();
        cursor = cursor->link();
    }
}
bool Order::is_ready()
{
    if (time(NULL) > order_time + cook_time)
        return true;
    else
        return false;
}
bool Order::is_delivered()
{
    if (time(NULL) > (order_time + cook_time + Deliverry_time))
        return true;
    else
        return false;
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

    if (cooking_time[pizza_size] > cook_time)
    {
        cook_time = cooking_time[pizza_size];
    }

    size_type i = 0;
    while (i < Max_toppings)
    {
        cout << "Please choose up to 5 toppings (cheese and sauce are included)\n";
        cout << "If you are done or do not want extra toppings choose 0\n\n";
        print_topping_list();

        cout << "Enter the toping code (enter 0 to exit): ";
        cin >> topping;
        if (topping == 0)
        {
            break;
        }
        else if (topping > Topping_list_size - 1)
        {
            cout << "\n\nYou have enterd a incorrect code. please try again!!!\n\n";
        }
        else
        {
            if (temp->add_topping(toppings[topping]))
                i++;
            else
            {
                cout << "you already have 5 toppings\n";
                return;
            }
        }
    }
    temp->print_Pizza();
    head_insert(*temp);
}
void Order::print_topping_list() const
{

    cout << setw(5) << "Code";
    cout << sep << setw(20) << "Topping" << endl;
    cout << "-----------------------------\n";
    for (size_type i = 1; i < Topping_list_size; i++)
    {
        cout << setw(5) << i << sep;
        cout << setw(20) << toppings[i] << endl;
    }
    cout << "-----------------------------\n";
}
