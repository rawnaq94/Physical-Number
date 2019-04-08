#include <iostream>
#ifndef PHYSICALNUMBER_H
#define PHYSICALNUMBER_H
#include "Unit.h"
using namespace std;


namespace ariel
{

    class PhysicalNumber
    {
     
        public:
        PhysicalNumber(double number,Unit _x);
        PhysicalNumber(const PhysicalNumber& f1);

        const PhysicalNumber operator+(const PhysicalNumber&); 
	const PhysicalNumber operator-(const PhysicalNumber&);
	PhysicalNumber& operator+=(const PhysicalNumber&);
	PhysicalNumber& operator-=(const PhysicalNumber&);
	PhysicalNumber operator+(); // Unari
	PhysicalNumber operator-(); // Unari

        bool operator> (const PhysicalNumber&) ;
        bool operator< (const PhysicalNumber&) ;
        bool operator>= (const PhysicalNumber&) ;
        bool operator<= (const PhysicalNumber&) ;
        bool operator== (const PhysicalNumber&) ;
        bool operator!= (const PhysicalNumber&) ;
    
        PhysicalNumber operator++();//++i
        PhysicalNumber operator++(int);//i++
        PhysicalNumber operator--();//--i
        PhysicalNumber operator--(int);//i--
    
    
    friend ostream& operator<< (ostream& os, const PhysicalNumber& c);//פלט
    friend istream& operator>> (istream& is, PhysicalNumber& c);//קלט
    
         private:
                   double number;
	            Unit _x;
     };
	
}
#endif
