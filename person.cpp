//code for person class here
#include <string>
#include <iostream>
#include "person.h"
#include "address.h"
#include "credit_card.h"

using std::string;

void Person::name(string name) {
    name_ = name;
}

string Person::name() {
    return name_;
}

void Person::phone(string phone) {
    phone_ = phone;
}

string Person::phone() {
    return phone_;
}

void Person::person_address(address addr) {
    person_address_ = addr;
}

address Person::person_address() {
    return person_address_;
}

void Person::person_credit_card(credit_card cc) {
    person_credit_card_ = cc;
}

credit_card Person::person_credit_card() {
    return person_credit_card_;
}

Person::Person(string name, string phone, address addr, credit_card cc) {
    name_ = name;
    phone_ = phone;
    person_address_ = addr;
    person_credit_card_ = cc;
}

Person::Person() {
    name_ = "Crumb Bum";
    phone_ = "800-588-2300";
    person_address_.state = "Wyoming";
    person_address_.city = "Cheyenne";
    person_address_.zip = "82001";
    person_address_.address_line1 = "1234 Idk St.";
    person_address_.address_line2 = "N/A";
    
    person_credit_card_.cc_number = 678008135;
    person_credit_card_.limit = 1000.00;
    person_credit_card_.current_balance = 257.85;
}

string Person::person_info() {
    return "Name: " + name_ + "\nPhone: " + phone_ + "\nAddress:\n" + person_address_.address_info() + "Credit Card:\n" + person_credit_card_.credit_card_info();
} 
