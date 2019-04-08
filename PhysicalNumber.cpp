#include "PhysicalNumber.h"
#include <iostream>
#include<exception>
#include <math.h> 
using namespace std;
using namespace ariel;


    PhysicalNumber::PhysicalNumber(double number,Unit _x){
         this->number=number;
         this->_x=_x;
     }
    PhysicalNumber::PhysicalNumber(const PhysicalNumber& pn){
        this->number=pn.number;
        this->_x=pn._x;
    }

    const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& p1){
         double value=number;
         return PhysicalNumber(value,_x);
    }
    
	const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& p1){
	      double value=number;
         return PhysicalNumber(value,_x);
	}
	PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& p1){
	    return *this;
	}
	PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& p1){
	    return *this;
	}
    PhysicalNumber PhysicalNumber::operator+(){
        return *this;
    } // Unari
	PhysicalNumber PhysicalNumber::operator-(){
        return *this;
    } // Unari

    bool PhysicalNumber::operator> (const PhysicalNumber& other){
        return false;
    }
    bool PhysicalNumber::operator< (const PhysicalNumber& other){
        return false;
    }
    bool PhysicalNumber::operator>= (const PhysicalNumber& other){
        return false;
    }
    bool PhysicalNumber::operator<= (const PhysicalNumber& other){
        return false;
    }
    bool PhysicalNumber::operator== (const PhysicalNumber& other){
        return false;
    }
    bool PhysicalNumber::operator!= (const PhysicalNumber& other){
        return false;
    }
    
    PhysicalNumber PhysicalNumber::operator++(){//++i first add and then print
        //++*this.num; //better
        //return PhysicalNumber(*this.num,*this.u);
	return *this;
    }
    PhysicalNumber PhysicalNumber::operator++(int){//i++
        PhysicalNumber pn(*this);
        //++*this.num;
        //return PhysicalNumber(pn.num,pn.u);//first print and then add
    	 return *this;
    }
    PhysicalNumber PhysicalNumber::operator--(){//--i
     //return PhysicalNumber(*this.num-1,*this.u);
    return *this;
    }
    PhysicalNumber PhysicalNumber::operator--(int){//i--
     return *this;
    }
    
   ostream &ariel::operator<< (ostream& os, const PhysicalNumber& c){//output
    
    return os ;

    }
  istream &ariel::operator>> (istream& is, PhysicalNumber& c){
	return is;
}

