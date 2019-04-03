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
    PhysicalNumber ff(20, Unit::TON);
    PhysicalNumber gg(5, Unit::HOUR);
    PhysicalNumber hh(300, Unit::SEC);
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
  // New  Testcase:
      
     .setname("Basic output") 
     .CHECK_OUTPUT(aa, "12[km]")
     .CHECK_OUTPUT(bb, "6000[cm]")
     .CHECK_OUTPUT(cc, "10[m]")
     .CHECK_OUTPUT(dd, "40[kg]")
     .CHECK_OUTPUT(ee, "200[g]")
     .CHECK_OUTPUT(ff, "20[ton]")
     .CHECK_OUTPUT(gg, "5[hour]")
     .CHECK_OUTPUT(hh, "300[sec]")
     .CHECK_OUTPUT(ii, "60[min]")
      
   // opratot (+) 
      
     .setname("Compatible dimensions")
     .CHECK_OUTPUT(+aa, "12[km]")
     .CHECK_OUTPUT(+bb, "6000[cm]")
     .CHECK_OUTPUT(+cc, "10[m]")
     .CHECK_OUTPUT(+dd, "40[kg]")
     .CHECK_OUTPUT(+ee, "200[g]")
     .CHECK_OUTPUT(+ff, "20[ton]")
     .CHECK_OUTPUT(+gg, "5[hour]")
     .CHECK_OUTPUT(+hh, "300[sec]")
     .CHECK_OUTPUT(+ii, "60[min]")
    
   // oprator (-)
      
     .CHECK_OUTPUT(-aa, "-12[km]")
     .CHECK_OUTPUT(-bb, "-6000[cm]")
     .CHECK_OUTPUT(-cc, "-10[m]")
     .CHECK_OUTPUT(-dd, "-40[kg]")
     .CHECK_OUTPUT(-ee, "-200[g]")
     .CHECK_OUTPUT(-ff, "-20[ton]")
     .CHECK_OUTPUT(-gg, "-5[hour]")
     .CHECK_OUTPUT(-hh, "-300[sec]")
     .CHECK_OUTPUT(-ii, "-60[min]")
      
  // opratot (+) 
      
     .CHECK_OUTPUT(aa++, "13[km]")
     .CHECK_OUTPUT(bb++, "6001[cm]")
     .CHECK_OUTPUT(cc++, "11[m]")
     .CHECK_OUTPUT(dd++, "41[kg]")
     .CHECK_OUTPUT(ee++, "201[g]")
     .CHECK_OUTPUT(ff++, "21[ton]")
     .CHECK_OUTPUT(gg++, "6[hour]")
     .CHECK_OUTPUT(hh++, "301[sec]")
     .CHECK_OUTPUT(ii++, "61[min]")

  // oprator (-)   
      
     .CHECK_OUTPUT(aa--, "11[km]")
     .CHECK_OUTPUT(bb--, "5999[cm]")
     .CHECK_OUTPUT(cc--, "9[m]")
     .CHECK_OUTPUT(dd--, "39[kg]")
     .CHECK_OUTPUT(ee--, "199[g]")
     .CHECK_OUTPUT(ff--, "19[ton]")
     .CHECK_OUTPUT(gg--, "4[hour]")
     .CHECK_OUTPUT(hh--, "299[sec]")
     .CHECK_OUTPUT(ii--, "59[min]")
      
  // opratot (+)    
      
     .CHECK_OUTPUT(aa+bb, "12.06[km]")
     .CHECK_OUTPUT(aa+cc, "12.01[km]")
     .CHECK_OUTPUT(bb+aa, "12[km]")
     .CHECK_OUTPUT(bb+cc, "12[km]")
     .CHECK_OUTPUT(cc+aa, "12[km]")
     .CHECK_OUTPUT(cc+bb, "12[km]")
      
     .CHECK_OUTPUT(dd+ee, "12[km]")
     .CHECK_OUTPUT(dd+ff, "12[km]")
     .CHECK_OUTPUT(ee+dd, "12[km]")
     .CHECK_OUTPUT(ee+ff, "12[km]")
     .CHECK_OUTPUT(ff+dd, "12[km]")
     .CHECK_OUTPUT(ff+ee, "12[km]")
      
     .CHECK_OUTPUT(gg+hh, "12[km]")
     .CHECK_OUTPUT(gg+ii, "12[km]")
     .CHECK_OUTPUT(hh+gg, "12[km]")
     .CHECK_OUTPUT(hh+ii, "12[km]")
     .CHECK_OUTPUT(ii+gg, "12[km]")
     .CHECK_OUTPUT(ii+hh, "12[km]")
      
      
  
      
      
      
      
      
      .setname("...")

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
