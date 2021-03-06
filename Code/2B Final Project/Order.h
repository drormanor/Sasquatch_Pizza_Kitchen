#include "Node.h"
#include "Pizza.h"
#include <cstdlib>
#include <time.h>
#include <string>
#include <unordered_map>
#include <stdio.h>
#include <iomanip>

using namespace std;
static const string line = "\n-----------------------------------------------------------------\n";
static const string sep = " | ";

class Order
{
public:
  typedef Node<Pizza>::value_type data_type;
  typedef size_t size_type;
  static const size_type Deliverry_time = 120;

  static const size_type Topping_list_size = 20;
  

  // Constructor
  // ******************************************************************************************
  Order();
  // Summary: Constructor creates a linked list object with count set at 0.
  // ******************************************************************************************

  void set_phone(string phone);
  // Summary:  setter for the customer phone
  // ******************************************************************************************

  void set_name(string name);
  // Summary:  setter for the customer name
  // ******************************************************************************************

  void set_house(string new_house);
  // Summary:  setter for the customer house number
  // ******************************************************************************************

  void set_street(string new_street);
  // Summary:  setter for the customer street
  // ******************************************************************************************

  void set_city(string new_city);
  // Summary:  setter for the customer city
  // ******************************************************************************************

  void set_zip(string new_zip);
  // Summary:  setter for the customer zip code
  // ******************************************************************************************

  void set_cookTime(time_t ct);
  // Summary:  setter for the order cook time
  // ******************************************************************************************

    void set_order_time(time_t t);
  // Summary: a timestamp will be created and stored
  // ******************************************************************************************

  string get_phone() const;
  // Summary:  getter for the customer phone
  // ******************************************************************************************

  string get_name() const;
  // Summary:  getter for the customer name
  // ******************************************************************************************

  string get_house() const;
  // Summary:  getter for the customer house number
  // ******************************************************************************************

  string get_street() const;
  // Summary:  getter for the customer street name
  // ******************************************************************************************

  string get_city() const;
  // Summary:  getter for the customer city
  // ******************************************************************************************

  string get_zip() const;
  // Summary:  getter for the customer zip code
  // ******************************************************************************************

  time_t get_cookTime() const;
  // Summary:  getter for the order cook time
  // ******************************************************************************************

  time_t get_order_time() const;
  // Summary: a timestamp will be returned
  // ******************************************************************************************

  Node<Pizza> *getHeadPtr();
  // Summary: Returns a pointer to the head Node of the list.
  // Preconditions: The list has been initialized.
  // Postconditions: A pointer to the head has been returned.
  // ******************************************************************************************

  const Node<Pizza> *getHeadPtr() const;
  // Summary: Returns a pointer to the head Node of the list.
  // Preconditions: The list has been initialized.
  // Postconditions: A pointer to the head has been returned.
  // ******************************************************************************************

  size_type list_length() const;
  // Summary: This function returns the number of Nodes in the list.
  // Preconditions:  A list exists
  // Postconditions: Returns 0 if list is empty, otherwise it returns the number of items
  // in the list, i.e. count
  // ******************************************************************************************

  bool isEmpty() const;
  // Summary: This function returns true if the list is empty.
  // Preconditions:  A list object exists
  // Postconditions: Returns true if the list contains no Nodes and false if the list 
  // contains at least one Node.
  // ******************************************************************************************

  void head_insert(const data_type &value);
  // Summary: This function inserts a new Node at the beginning of the list.
  // Preconditions:  A head_ptr exists and a new value has been passed in.
  // Postconditions: A new Node has been added to the beginning of the list with the 
  // value in the data_field at the head of the list.
  // ******************************************************************************************

  void list_insert(Node<Pizza> *prev_ptr, const Node<Pizza>::value_type &value);
  // Summary: This function inserts a new Node with value in the data field after the
  // prev_ptr Node.
  // Preconditions: prev_ptr is a pointer to the Node that is before the the spot where we 
  // want to insert a new Node with data equal to value.
  // Postconditions: The list with one more Node that contains the value passed into 
  // the function.
  // ******************************************************************************************

  void head_remove();
  // Summary: This function removes the Node at the beginning of the list.
  // Preconditions: There is a list with head_ptr pointing to the beginning
  // of the list.
  // Postconditions: We have a list with the previous head Node of the list
  // removed.
  // ******************************************************************************************

  void clear_list();
  // Summary: This function empties the list.
  // Preconditions: There is a current list.
  // Postconditions: list has been cleared of Nodes. head_ptr now is NULL.
  // ******************************************************************************************

  void operator=(const Order &source_list);
  //  Summary: will clear list and copy source list nodes into list.
  // Preconditions: source list must not be empty.
  // postconditions: list will be be populated with copies of source
  // list nodes
  // ******************************************************************************************
 
  void take_order();
  // Summary: This function will take all info from user and store in the variables
  // also, will create the pizza nodes and store them in a linked list.
  // Precondition: an Order object instantiated.
  // Postconditions: an order object is populated with pizza nodes and customer info and the  
  // order detail will print out.
  // ******************************************************************************************

  void print_order();
  // Summary: this function will print summary of all object info.
  // Preconditions: an Order object instantiated and information was collected
  // Postconditions: the customer info is printed as wee as the time the order was placed.
  // and a list of all the pizzas in the order
  // ******************************************************************************************

  bool is_ready();
  // Summary: this function will check if an order is ready.
  // Preconditions: object has been created and pizza list is not empty
  // Postconditions: a bool is returned after comparing the current time
  // to order_time + cook_time
  // ******************************************************************************************

  bool is_delivered();
  // Summary: this function will check if an order was delivered.
  // Preconditions: object has been created and pizza list is not empty
  // Postconditions: a bool is returned after comparing the current time
  // to the order_time + cook_time + delivery_time;
  // ******************************************************************************************
  

  ~Order();
  // Summary: The destructor empties the list.
  // *********************************************************************
 
 
private:
  time_t cook_time;
  unordered_map<char, int> cooking_time{{'s', 120}, {'m', 240}, {'l', 360}};
  const string toppings[Topping_list_size]{"End",
                                           "Artichoke hearts",
                                           "Capers",
                                           "Tomatoes",
                                           "Mushrooms",
                                           "Onions",
                                           "Olives",
                                           "Red peppers",
                                           "Roasted Garlic",
                                           "Roasted peppers",
                                           "Sun dried tomatoes",
                                           "Sweet corn",
                                           "Feta Cheese",
                                           "Extra Cheese",
                                           "Bacon",
                                           "Pepperoni",
                                           "Prosciutto",
                                           "Sausage",
                                           "Chicken",
                                           "Anchovies"};
  string customer_name;
  string customer_phone;
  string house_number;
  string street;
  string city;
  string zip;
  Node<Pizza> *head_ptr; // Points to front of list
  size_type pizza_count; // holds the number of Nodes in the list
  time_t order_time; //store the time when the order was placed

  void set_order_time() { order_time = time(nullptr); };
  // Summary: a timestamp will be created and stored
  // *********************************************************************

	void add_pizza();
  // Summary: a pizza will be added to the order
  // Preconditions: an Order object instantiated
  // Postconditions: the user will be prompt to enter the size of the pizza
  // and the toppings the customer orders.
  // *********************************************************************

  void print_topping_list() const;
  // Summary: a list of the available toppings will print to the screen
  // Postconditions: the list will print with the index and the topping name
  // *********************************************************************

};

void list_copy(const Order &source_list, Order &destination_list);
//  summary: will copy all nodes from source list to destination list
//  in the same order
// *********************************************************************

void is_phone_number(string& pnum);
//  summary: will check if a string is a phone number
// *********************************************************************

string format_phone(string ph_num);
//  summary: will print the phone number it this format (xxx)xxx-xxxx
// *********************************************************************

void validate_pizza_size(char &size);
  // Summary: will validate that the size is either 's', 'm' or 'l'
  // ********************************************************************
void print_order_header();
    // Summary: will print the header for the order details
    // ********************************************************************



