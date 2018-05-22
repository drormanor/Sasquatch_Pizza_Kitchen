#include "Order.h"
#include <iomanip>
#include <ios>
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

void Order::set_house(string new_house)
{
    house_number = new_house;
}

void Order::set_street(string new_street)
{
    street = new_street;
}
void Order::set_city(string new_city)
{
    city = new_city;
}
void Order::set_zip(string new_zip)
{
    zip = new_zip;
}
void Order::set_cookTime(time_t ct)
{
    cook_time = ct;
}

void Order::set_order_time(time_t t)
{
    order_time = t;
}

string Order::get_phone() const
{
    return customer_phone;
}
string Order::get_name() const
{
    return customer_name;
}
string Order::get_house() const
{
    return house_number;
}
string Order::get_street() const
{
    return street;
}
string Order::get_city() const
{
    return city;
}
string Order::get_zip() const
{
    return zip;
}
time_t Order::get_cookTime() const
{
    return cook_time;
}
time_t Order::get_order_time() const
{
    return order_time;
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
    set_name(source_list.get_name());
    set_phone(source_list.get_phone());
    set_house(source_list.get_house());
    set_street(source_list.get_street());
    set_city(source_list.get_city());
    set_zip(source_list.get_zip());
    set_cookTime(source_list.get_cookTime());
    this->order_time = source_list.get_order_time();
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
    //getting the customer name
    string name, phone, new_house, new_street, new_zip, new_city;
    cout << "Please enter the customer name: ";
    getline(cin, name);
    set_name(name);
    cout << "Customer address:\n";
    cout << "Please enter the House Number: ";
    getline(cin, new_house);
    set_house(new_house);

    cout << "Please enter the Street name: ";
    getline(cin, new_street);
    set_street(new_street);

    cout << "Please enter the city name: ";
    getline(cin, new_city);
    set_city(new_city);

    cout << "Please enter the zip code number: ";
    getline(cin, new_zip);
    set_zip(new_zip);

    cout << "Please enter the customer phone number: ";
    getline(cin, phone);
    is_phone_number(phone);
    set_phone(phone);

    char check = 'y';

    while (tolower(check) != 'n')
    {

        cout << "\n\nAdd a pizza:\n";
        add_pizza();

        cout << "Would you like to add another pizza? y/n ";
        cin >> check;
        while (!(tolower(check) == 'n' || tolower(check) == 'y'))
        {
            cout << "You have entered the wrong answer!!!\n";
            cout << "Would you like to add another pizza??? y/n ";
            cin >> check;
        }
    }
    set_order_time();

}

void Order::print_order()
{
    time_t temp_order_time = order_time;
    tm *st = localtime(&temp_order_time);
    cout << setw(15) << left << customer_name << "   ";
    cout << setw(15) << left << format_phone(customer_phone) << "   ";
    cout << setw(get_house().length()+1) << left << get_house() << setw(get_street().length()+1) << left  << get_street() << setw(get_city().length()+1) << left << get_city() << setw(get_zip().length()+1) << left << get_zip();
    cout << setw(15) << left << "\nOrder Time: " << put_time(st, "%m/%d/%Y at %H:%M");
    cout << endl;
    
    if (is_ready())
        cout << "Order will be delivered in " << ((Deliverry_time + cook_time) - (time(NULL) - order_time)) << " sec." << endl;
    else if (is_delivered())
        cout << "Order is Delivered!\n";
    else
        cout << "Order will be ready in " << (cook_time - (time(NULL) - order_time)) << " sec." << endl;

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
    int topping;
    cout << "\n\nPlease select the size of pizza (s for small, m for medium, or l for large): ";
    cin >> pizza_size;
    cin.ignore();
    validate_pizza_size(pizza_size);
    temp->set_pizza_size(tolower(pizza_size));

    if (cooking_time[pizza_size] > cook_time)
    {
        cook_time = cooking_time[pizza_size];
    }

    size_type i = 0;

    cout << "\n\nPlease choose up to 5 toppings (cheese and sauce are included)\n";

    while (i < Max_toppings)
    {

        cout << "\nIf you are done or do not want extra toppings choose 0\n";
        cout << "\nTo remove the last topping enter -1\n\n";

        print_topping_list();

        cout << "\nEnter the toping code (enter 0 to exit or -1 to remove last topping): ";
        cin >> topping;
        while (!cin.good())
        {
            cin.clear();
            fflush(stdin);
            cout << "\nWrong entry!!! (enter 0 to exit or -1 to remove last topping): ";
            cin >> topping;
        }
            
            if (topping == 0)
            {
                break;
            }
            else if (topping == -1 && i > 0)
            {
                i--;
                temp->remove_last_topping();
            }
            else if (topping > Topping_list_size - 1 || topping < -1)
            {
                cout << "\n\nYou have entered a incorrect code. please try again!!!\n\n";
                cin.clear();
                fflush(stdin);
            }

            else
            {
                if (temp->add_topping(toppings[topping]))
                {
                    i++;
                    cout << "\n\nYou added: " << toppings[topping] << " to this pizza" << endl;
                }
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

// will check if the number entered is a valid format
void is_phone_number(string &ph_num)
{
    bool invalid_num;
    do
    {
        invalid_num = false;
        for (size_t i = 0; i < ph_num.length() - 1; i++)
        {
            if (!isdigit(ph_num[i]))
            {
                invalid_num = true;
                break;
            }
        }
        if (ph_num.length() != 10)
        {
            invalid_num = true;
        }
        if (invalid_num)
        {
            cout << ph_num << " is invalid format.( correct format:2223335555 with no spaces).\n";
            cout << "Please enter the customer phone number: ";
            getline(cin, ph_num);
        }
    } while (invalid_num);
}

// will print the phone number it this format (xxx)xxx-xxxx
string format_phone(string ph_num)
{

    ph_num = ph_num.insert(0, "(");
    ph_num = ph_num.insert(4, ")");
    ph_num = ph_num.insert(8, "-");

    return ph_num;
}

void validate_pizza_size(char &size)
{
    bool invalid;
    do
    {
        invalid = false;
        size = tolower(size);
        if (size == 's' || size == 'm' || size == 'l')
        {
            invalid = false;
        }
        else
            invalid = true;
        if (invalid)
        {
            cout << size << " is invalid size.\n";
            cout << "\n\nPlease select the size of pizza again \n(s for small, m for medium, or l for large): ";
            cin >> size;
        }
    } while (invalid);
}

void print_order_header()
{
    cout << setw(15) << left << "Customer Name" << sep << setw(15) << left << "Phone Number" << sep << setw(15) << left << "Address";
    cout << line;
}