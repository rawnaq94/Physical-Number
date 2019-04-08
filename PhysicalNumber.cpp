// Partial realization --- Part 1

#include <iostream>
#include "PhysicalNumber.h"
#include <exception>
#include <math.h>
using namespace std;
using namespace ariel;

// copy constructor

PhysicalNumber::PhysicalNumber(double number, Unit _x)
{
     this->number = number;
     this->_x = _x;
}


PhysicalNumber::PhysicalNumber(const PhysicalNumber& value)
{
     this->number = value.number;
     this->_x = value._x;
}

// onry operator
 
PhysicalNumber PhysicalNumber::operator+(){ return *this; }
PhysicalNumber PhysicalNumber::operator-(){ return *this; }


// operator (+) && operator (-)

const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& a)
{
      double num = number;
      return PhysicalNumber(num,_x);
}


const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& a)
{
      double num = number;
      return PhysicalNumber(num,_x);
}


PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& a){ return *this; }
PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& a){ return *this; }
 
 
 // check equal by boolean operator 
       
bool PhysicalNumber::operator== (const PhysicalNumber& b){ return false; }
bool PhysicalNumber::operator!= (const PhysicalNumber& b){ return false; }
bool PhysicalNumber::operator>= (const PhysicalNumber& b){ return false; }
bool PhysicalNumber::operator<= (const PhysicalNumber& b){ return false; }
bool PhysicalNumber::operator> (const PhysicalNumber& b){ return false; }
bool PhysicalNumber::operator< (const PhysicalNumber& b){ return false; }


// promotion and subtraction operator

PhysicalNumber PhysicalNumber::operator++(){ return *this; }
PhysicalNumber PhysicalNumber::operator--(){ return *this; }
PhysicalNumber PhysicalNumber::operator--(int){ return *this; }
PhysicalNumber PhysicalNumber::operator++(int)
{
     PhysicalNumber value(*this);
     return *this;
}


 // input && output
 
istream &ariel::operator>> (istream& is, PhysicalNumber& c){ return is; }
ostream &ariel::operator<< (ostream& os, const PhysicalNumber& c){ return os; }
