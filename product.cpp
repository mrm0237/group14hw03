// Riggs- code for product struct here
#include "product.h"
#include <sstream>
#include <iomanip>

std::string product::product_info() {
  std::ostringstream out;
  out << "Name: " << name << "\n";
  out << "Description: " << description << endl;
  out << "Price: $" << std::fixed << std::setprecision(2) << price << endl;
  return out.str();
}
// Makes a product for the main method and test cases, P_NAME and others will be made in other methods
product make_product(std::string p_name, std::string p_desc, double p_price)
{
    product my_product;
    my_product.name = p_name;
    my_product.description = p_desc;
    my_product.price = p_price;
    return my_product;
}
