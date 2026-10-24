// Team 14: Riggs McLeod and Christian Nobles
// Import the necessary libraries and all the files
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
// store.h already imports the other files (address and cc in Person)
#include "store.h"

using namespace std; 

// Helper function - If the first line of a file starts with a digit, skip it

int main()
{
	//add to store and other variables
	srand(time(0)); // Seed the random number generator with the current time
	Store store;
	string line;
	// products.txt: name, description, and price for products
	product products[100];
	int num_prods = 0;
    ifstream pin("products.txt"); 	// open products.txt to read
	getline(pin, line); // skip the count line
	ifstream pin("products.txt");
	getline(pin, line);
	string name;
	string desc;
	while (num_prods < 100 && getline(pin, name) && !name.empty()) {
        if (!getline(pin, desc) || !getline(pin, line || line.empty()) break; // read description
        products[num_prods++] = make_product(name, desc, stod(line));		// converts string to double and increments num_prods
    }
	// credit_card.txt: name, number, limit, and balance
	string card_names[100];
	credit_card cards[100];
	int num_cards = 0;
	ifstream cin_file("credit_card.txt");	// Open credit_card.txt
	while (num_cards < 100 && getline(cin_file, line) && !line.empty()) {
		card_names[num_cards] = line;		// read name of the cardholder
		getline(cin_file, line);	// read credit card number
		cards[num_cards].cc_number = stoi(line);	// store in the struct
		getline(cin_file, line);	// read credit limit
		cards[num_cards].limit = stod(line);		// store in the struct
		getline(cin_file, line);	// read current balance
		cards[num_cards].current_balance = stod(line);	// store in the struct
		num_cards++;
	}

	// people.txt: name, phone, line1, (possibly) line2, city, state, zip
	Person people[100];
	int num_people = 0;
	ifstream fin("people.txt");
	while (num_people < 100 && getline(fin, line) && !line.empty()) {
		string cname = line, phone;
		address addr;
		// gets lines from file: phone, address lines, city, state, and zip
		getline(fin, phone);
		getline(fin, addr.address_line1);
		getline(fin, addr.address_line2);		// possibly blank
		getline(fin, addr.city);
		getline(fin, addr.state);
		getline(fin, addr.zip);

		credit_card card;		// default, then match by name
		card.cc_number = 0;
		card.limit = 0;
		card.current_balance = 0;
		for (int i = 0; i < num_cards; i++) {
			if (card_names[i] == cname) {
				card = cards[i]; 
			}
		}
		people[num_people++] = Person(name, phone, addr, card);
	}
	// add everything to the store
	for (int i = 0; i < num_prods; i++)
		store.add_product(products[i]);
	for (int i = 0; i < num_people; i++)
		store.add_customer(people[i]);
	// Print store info after you finish importing info
	// from text files and add them to your store
	cout << store.store_info() << endl; 

	//make random number of random transactions
	int n = 11 + rand() % 89; // Generate a random number of transactions between 10 and 100 
    for (int i = 0; i < n; i++) {
        Person customer = store.get_customer(rand() % store.num_customers());
        product item = store.get_product(rand() % store.num_products());
        int qty = 1 + rand() % 10; // Generate a random quantity between 1 and 10
        
        if (store.make_purchase(customer, item, qty)) {
            cout << "Successful transaction!\nTransaction Details:\n" 
            << store.get_transaction(store.num_transactions() - 1).transaction_info();
        }
        else {
            cout << "Unsuccessful transaction!\nTransaction Details:\n";
            cout << "Person:\n" << customer.person_info();
            cout << "Product:\n" << item.product_info();   
            cout << "Purchase Quantity: " << qty << endl;
        }
    }
	//print store info at the end
	cout << store.store_info() << endl;
}
