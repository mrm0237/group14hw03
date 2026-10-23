//implementation code for address struct here
#include "address.h"
#include <sstream>
#include <iostream>

using namespace std;

string address::address_info() {
  // The private instance variables are already in the address.h, so we don't need to make them
  std::ostringstream oss;
  /* Example: 
  Shelby Center for Engineering Technology
  357-359 W Magnolia Ave
  Auburn, AL, 36830
  */
  oss << address_line1 << endl;
  if (!address_line2.empty()) {
    oss << address_line2 << endl;
  }
  oss << city << "\n" << state << "\n" << zip << endl;
  return oss.str();
}
