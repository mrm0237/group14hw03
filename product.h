// Riggs
#include <string>

#ifndef PRODUCT_H
#define PRODUCT_H

//a struct that can be used to capture
//product information
struct product
{
	//data members
	std::string name;
	std::string description;
	double price;

	//prints information about one transaction
	std::string product_info();

	// makes make_product for product.cpp
	product make_product(std::string p_name, std::string p_desc, double p_price); 
};
#endif

