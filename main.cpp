// Team 14: Riggs McLeod and Christian Nobles
// Import the necessary libraries and all the files
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
// store.h already imports the other files (address and cc in Person)
#include "store.h"

using namespace std; 

// helper functions since my program is making me want to
// reads one line and removes a trailing '\r' (Windows line ending)
static bool read_line(istream& in, string& line) {
    if (!getline(in, line)) return false;
    if (!line.empty() && line.back() == '\r') line.pop_back();
    return true;
}

static bool all_digits(const string& s) {
    if (s.empty()) return false;
    for (size_t i = 0; i < s.size(); i++)
        if (s[i] < '0' || s[i] > '9') return false;
    return true;
}

// If the first line is just a count, skip it. Otherwise rewind to the start.
static void skip_count_line(ifstream& in) {
    string first;
    read_line(in, first);
    if (!all_digits(first)) {
        in.clear();
        in.seekg(0);
    }
}

static double to_double(const string& s, const string& where) {
    try { return stod(s); }
    catch (...) {
        cerr << "ERROR: bad number in " << where << ": [" << s << "]" << endl;
        exit(1);
    }
}

static int to_int(const string& s, const string& where) {
    try { return stoi(s); }
    catch (...) {
        cerr << "ERROR: bad number in " << where << ": [" << s << "]" << endl;
        exit(1);
    }
}

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
	skip_count_line(pin);
	while (num_prods < 100 && read_line(pin, line) && !line.empty()) {
        products[num_prods].name = line;
        read_line(pin, products[num_prods].description); 	// read description
        read_line(pin, line);
        products[num_prods++].price = to_double(line, "products.txt price");		// converts string to double and increments num_prods
    }
	// credit_card.txt: name, number, limit, and balance
	string card_names[100];
	credit_card cards[100];
	int num_cards = 0;
	ifstream cin_file("credit_card.txt");	// Open credit_card.txt
	skip_count_line(cin_file);
	while (num_cards < 100 && read_line(cin_file, line) && !line.empty()) {
		card_names[num_cards] = line;		// read name of the cardholder
		read_line(cin_file, line);	// read credit card number
		cards[num_cards].cc_number = to_int(line, "credit_card.txt number");	// store in the struct
		read_line(cin_file, line);	// read credit limit
		cards[num_cards].limit = to_double(line, "credit_card.txt limit");		// store in the struct
		read_line(cin_file, line);	// read current balance
		cards[num_cards].current_balance = to_double(line, "credit_card.txt balance");	// store in the struct
		num_cards++;
	}

	// people.txt: name, phone, line1, (possibly) line2, city, state, zip
	Person people[100];
	int num_people = 0;
	ifstream fin("people.txt");
	skip_count_line(fin);
	while (num_people < 100 && getline(fin, line) && !line.empty()) {
		string name = line, phone;
		address addr;
		// gets lines from file: phone, address lines, city, state, and zip
		read_line(fin, phone);
		read_line(fin, addr.address_line1);
		read_line(fin, addr.address_line2);		// possibly blank
		read_line(fin, addr.city);
		read_line(fin, addr.state);
		read_line(fin, addr.zip);

		credit_card card;		// default, then match by name
		card.cc_number = 0;
		card.limit = 0;
		card.current_balance = 0;
		for (int i = 0; i < num_cards; i++) {
			if (card_names[i] == name) {
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
