//code for store class here
//include everything we need and get the standard namespace
#include <sstream>
#include <iostream>
#include <iomanip>
#include "store.h"

using namespace std;


Store::Store() { // default constructor; set everything to 0 or null
  num_customers_ = 0;
  num_products_ = 0;
  num_transactions_ = 0;
}
// Make setters and getters for the private variables
void Store::num_products(int product_count) {
  num_products_ = product_count;
}
int Store::num_products() {
  return num_products_;
}

void Store::num_customers(int customer_count) {
  num_customers_ = customer_count;
}
int Store::num_customers() {
  return num_customers_;
}

void Store::num_transactions(int transaction_count) {
  num_transactions_ = transaction_count;
}
int Store::num_transactions() {
  return num_transactions_;
}
// Now time for the constructors! ADD methods for each parameter, UPDATE method for customer,
// GET method for product and transaction, make_purchase method
bool Store::add_product(product item) {
  // This method is bool because if the product is not in range, we'll return false
  if (num_products_ >= 100) return false; 
  products_[num_products_++] = item;
  return true;
}
 
bool Store::add_customer(Person customer) {
  if (num_customers_ >= 100) return false;
  customers_[num_customers_++] = customer;
  return true;
}
bool Store::update_customer(int index, Person customer) {
  if (index < 0 || index >= num_customers_) {
    return false;  // check that index is in bounds of customers array
  }
  customers_[index] = customer;  // customer at that index is changed to this customer
  return true;
}

product Store::get_product(int index) {
  if (index >= 0 && index < num_products_) 
    return products_[index];   // output products_[index]
  return product();
}

bool Store::add_transaction(transaction ntransaction) {
  if (num_transactions_ >= 100) {
    return false;  // if out of bounds
  }
  transactions_[num_transactions_++] = ntransaction;
  return true;
}

transaction Store::get_transaction(int index) {
  if (!(index < 0 || index >= num_transactions_)) { // if it's not erroneous
    return transactions_[index];
  }
  return transaction();
}

bool Store::make_purchase(Person customer, product item, int amount) {
  // See if the customer exists in the store
  int customer_index = find_customer(customer); // gets the customer we're looking fot
  if (customer_index == -1 || amount <= 0 || num_transactions_ >= 100) {
    return false; // if the person doesn't exist or the transaction couldn't exist, do nothing
  }
  // Get the person's credit card information
  credit_card card = customers_[customer_index].person_credit_card();
  if (!card.make_purchase(item.price*amount)) {
    return false;  // if ya broke, you can't buy it (over the limit)
  }
  customers_[customer_index].person_credit_card(card); // save new balance
  // update transactions
  transaction t;
  t.transaction_number = num_transactions_ + 1;
  t.customer = customers_[customer_index];
  t.purchased_item = item;
  t.quantity = amount;
  return add_transaction(t);
}

  // Information methods: return the info of the store's products, transactions, purchases, and all store info
  // Returns a string listing all products associated with the store
  std::string Store::product_info() {
    std::ostringstream oss;
    // Output the Product Name and Price for every product
    for (int i = 0; i < num_products_; i++) {
      oss << products_[i].product_info();
    }
  return oss.str();
  }
  // Returns a string of all the transactions the store has made
  std::string Store::transaction_info() {
    std::ostringstream oss;
    // Output the Transaction ID, Customer, Product, and Amount for each transaction
    for (int i = 0; i < num_transactions_; i++) {
      oss << transactions_[i].transaction_info(); // transaction_info outputs all that stuff
  }
  return oss.str();
}

std::string Store::customer_info() {
  std::ostringstream oss;
  for (int i = 0; i < num_customers_; i++)
    oss << customers_[i].person_info();
  return oss.str();
}
std::string Store::store_info() {  // Return all the numerical info from the store
  std::ostringstream oss;
  // Output the number of customer_info, product_info, and transaction_info for the store
  oss << "Store Info:\nCustomers:\n" << customer_info();
  oss << "Products:\n" << product_info();
  oss << "All Transactions: " << transaction_info() << endl;
  return oss.str();
}

std::string Store::purchase_history(Person cust) {
  std::ostringstream oss;
  // Output the transaction information for each transaction 
  for (int i = 0; i < num_transactions_; i++) {
    if (transactions_[i].customer.name() == cust.name() && 
      transactions_[i].customer.phone() == cust.phone()) {
      oss << transactions_[i].transaction_info();
    }
  }
  return oss.str();
}
