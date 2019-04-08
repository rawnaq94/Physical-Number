/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);
    
     // NEW BASIC TESTS 
    PhysicalNumber aa(12, Unit::KM);
    PhysicalNumber bb(6000, Unit::CM);
    PhysicalNumber cc(10, Unit::M);
    PhysicalNumber dd(40, Unit::KG);
    PhysicalNumber ee(200, Unit::G);
    PhysicalNumber ff(2, Unit::TON);
    PhysicalNumber gg(5, Unit::HOUR);
    PhysicalNumber hh(30, Unit::SEC);
    PhysicalNumber ii(60, Unit::MIN); 
    

    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT

     .setname("Basic output") 
     .CHECK_OUTPUT(aa, "12[km]")
     .CHECK_OUTPUT(bb, "6000[cm]")
     .CHECK_OUTPUT(cc, "10[m]")
     .CHECK_OUTPUT(dd, "40[kg]")
     .CHECK_OUTPUT(ee, "200[g]")
     .CHECK_OUTPUT(ff, "2[ton]")
     .CHECK_OUTPUT(gg, "5[hour]")
     .CHECK_OUTPUT(hh, "30[sec]")
     .CHECK_OUTPUT(ii, "60[min]") 
      
      
      
     // opratot (+=) && opratot (-=)
     // operator (++) && opertor (--)
      
     .setname("Compatible dimensions")
     .CHECK_OUTPUT(bb+bb, "12000[cm]")
     .CHECK_OUTPUT(ff-=dd, "19.96[ton]") 
     .CHECK_OUTPUT(ff, "19.96[ton]") 
     .CHECK_OUTPUT(hh++, "31[sec]")
     .CHECK_OUTPUT(++ee, "201[g]")
     .CHECK_OUTPUT(--ee, "200[g]")
     .CHECK_OUTPUT(dd-=ee, "39.8[kg]")
      
     
     .setname("Incompatible dimensions")
     .CHECK_THROWS(bb+hh)
     .CHECK_THROWS(bb+ff)
     .CHECK_THROWS(dd-hh)
     .CHECK_THROWS(ff-=hh)
     .CHECK_THROWS(ee-bb)
     .CHECK_THROWS(ee>hh)
     .CHECK_THROWS(ff==bb)
     .CHECK_THROWS(bb<=hh)
      
      
       
     .setname("Check OK")
     .CHECK_OK(istringstream("200[g]")>>ee)
     .CHECK_OK(istringstream("12000[cm]")>>bb)
     .CHECK_OK(istringstream("31[sec]")>>hh)
     .CHECK_OK(istringstream("39.8[kg]")>>dd)
      
      
    // opratot (<) && opratot (>)  
   // opratot (==) && opratot (!=) 
     
     .setname("Compatible dimensions") 
     .CHECK_EQUAL(hh>d,false)
     .CHECK_EQUAL(dd==ff,false)
     .CHECK_OK(istringstream("1000[kg]")>>dd)
     .CHECK_OUTPUT(dd, "10000[kg]")
     .CHECK_EQUAL(ee!=dd,true)
     .CHECK_EQUAL(ff>ee,true)
     .CHECK_EQUAL(ee>dd,false)
     .CHECK_EQUAL(bb==a,false)
     .CHECK_EQUAL(c<d,true)
    
      
    
      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
