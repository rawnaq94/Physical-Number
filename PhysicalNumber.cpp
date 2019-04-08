// Partial realization --- Part 1

#include <iostream>
#include "PhysicalNumber.h"
#include<exception>
#include <math.h> 
using namespace std;

using namespace ariel;


          // copy constructor

    PhysicalNumber::PhysicalNumber(double num,Unit u)
    {
         this->num=num;
         this->u=u;
     }

    PhysicalNumber::PhysicalNumber(const PhysicalNumber& pn)
    {
        this->num=pn.num;
        this->u=pn.u;
    }

          // onry operator

     PhysicalNumber PhysicalNumber::operator+(){ return *this; } 
     PhysicalNumber PhysicalNumber::operator-(){ return *this; } 


          // operator (+) && operator (-)

    const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& p1)
    {
         double value=num;
         return PhysicalNumber(value,u);
    }
    
    const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& p1)
    {
	 double value=num;
         return PhysicalNumber(value,u);
     }

    PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& p1){ return *this; }
    PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& p1){ return *this; }
   

          // check equal by boolean operator 

    bool PhysicalNumber::operator== (const PhysicalNumber& other){ return false; }
    bool PhysicalNumber::operator!= (const PhysicalNumber& other){ return false; }
    bool PhysicalNumber::operator> (const PhysicalNumber& other){ return false; }
    bool PhysicalNumber::operator< (const PhysicalNumber& other){ return false; }
    bool PhysicalNumber::operator>= (const PhysicalNumber& other){ return false; }
    bool PhysicalNumber::operator<= (const PhysicalNumber& other){ return false; }
    

          // promotion and subtraction operator
    
    PhysicalNumber PhysicalNumber::operator++(){ return *this; }
    PhysicalNumber PhysicalNumber::operator--(){ return *this; }
    PhysicalNumber PhysicalNumber::operator--(int){ return *this; }
    PhysicalNumber PhysicalNumber::operator++(int)
    {
        PhysicalNumber pn(*this);
    	 return *this;
    }
    

    ostream &ariel::operator<< (ostream& os, const PhysicalNumber& c){ return os; }
    istream &ariel::operator>> (istream& is, PhysicalNumber& c){ return is; }

