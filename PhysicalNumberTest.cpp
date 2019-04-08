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

     .setname("Compatible dimensions")
     .CHECK_OUTPUT(-aa, "-12[km]")
     .CHECK_OUTPUT(-bb, "-6000[cm]")
     .CHECK_OUTPUT(-cc, "-10[m]")
     .CHECK_OUTPUT(-dd, "-40[kg]")
     .CHECK_OUTPUT(-ee, "-200[g]")
     .CHECK_OUTPUT(-ff, "-20[ton]")
     .CHECK_OUTPUT(-gg, "-5[hour]")
     .CHECK_OUTPUT(-hh, "-300[sec]")
     .CHECK_OUTPUT(-ii, "-60[min]")
      
  // opratot (+) && operator (-)
     
     .setname("Compatible dimensions")
     .CHECK_OUTPUT(aa++, "13[km]")
     .CHECK_OUTPUT(aa--, "12[km]")
     .CHECK_OUTPUT(bb++, "6001[cm]")
     .CHECK_OUTPUT(bb--, "6000[cm]")
     .CHECK_OUTPUT(cc++, "11[m]")
     .CHECK_OUTPUT(cc--, "10[m]")
     .CHECK_OUTPUT(dd++, "41[kg]")
     .CHECK_OUTPUT(dd--, "40[kg]")
     .CHECK_OUTPUT(ee++, "201[g]")
     .CHECK_OUTPUT(ee--, "200[g]")
     .CHECK_OUTPUT(ff++, "21[ton]")
     .CHECK_OUTPUT(ff--, "20[ton]")
     .CHECK_OUTPUT(gg++, "6[hour]")
     .CHECK_OUTPUT(gg--, "5[hour]")
     .CHECK_OUTPUT(hh++, "301[sec]")
     .CHECK_OUTPUT(hh--, "300[sec]")
     .CHECK_OUTPUT(ii++, "61[min]")
     .CHECK_OUTPUT(ii--, "60[min]")

      
  // opratot (+)    
      
     .setname("Compatible dimensions")
     .CHECK_OUTPUT(aa+bb, "12.06[km]")
     .CHECK_OUTPUT(aa+cc, "12.01[km]")
     .CHECK_OUTPUT(bb+aa, "1206000[cm]")
     .CHECK_OUTPUT(bb+cc, "7000[cm]")
     .CHECK_OUTPUT(cc+aa, "12010[m]")
     .CHECK_OUTPUT(cc+bb, "70[m]")
      
     .CHECK_OUTPUT(dd+ee, "40.2[kg]")
     .CHECK_OUTPUT(dd+ff, "20040[kg]")
     .CHECK_OUTPUT(ee+dd, "40200[g]")
     .CHECK_OUTPUT(ee+ff, "20000200[g]")
     .CHECK_OUTPUT(ff+dd, "20.04[ton]")
     .CHECK_OUTPUT(ff+ee, "20.0002[ton]")
      
     .CHECK_OUTPUT(gg+hh, "5.0833333[hour]")
     .CHECK_OUTPUT(gg+ii, "6[hour]")
     .CHECK_OUTPUT(hh+gg, "18300[sec]")
     .CHECK_OUTPUT(hh+ii, "3900[sec]")
     .CHECK_OUTPUT(ii+gg, "360[min]")
     .CHECK_OUTPUT(ii+hh, "65[min]")
      
      
    // opratot (-)
      
    .setname("Compatible dimensions")
    .CHECK_OUTPUT(aa-bb, "11.94[km]")
    .CHECK_OUTPUT(aa-cc, "11.99[km]")
    .CHECK_OUTPUT(bb-aa, "1194000[cm]") 
    .CHECK_OUTPUT(bb-cc, "5000[cm]")
    .CHECK_OUTPUT((aa-=aa),"0[km]")
    .CHECK_OUTPUT(aa,"0[km]")
    
    .CHECK_OUTPUT(dd-ee, "39.8[kg]")
    .CHECK_OUTPUT(ff-dd, "19.96[ton]")
    .CHECK_OUTPUT(ff-ee, "19.9998[ton]")
    .CHECK_OUTPUT((ee-=ee),"0[g]")
    .CHECK_OUTPUT(ee,"0[g]")
      
    .CHECK_OUTPUT(gg-hh, "4.9166667[hour]") 
    .CHECK_OUTPUT(gg-ii, "4[hour]")
    .CHECK_OUTPUT(ii-hh, "55[min]")
    .CHECK_OUTPUT((hh-=hh),"0[sec]")
    .CHECK_OUTPUT(hh,"0[sec]")  
      
   // error output 
      
     .setname("Incompatible dimensions")
     .CHECK_THROWS(cc-aa) 
     .CHECK_THROWS(cc-bb)
    
     .CHECK_THROWS(dd-ff)
     .CHECK_THROWS(ee-dd)
     .CHECK_THROWS(ee-ff)
      
     .CHECK_THROWS(hh-gg)
     .CHECK_THROWS(hh-ii)
     .CHECK_THROWS(ii-gg)
      
   // opratot (+=) && opratot (-=)
      
     .setname("Compatible dimensions") 
     .CHECK_OUTPUT(aa+=bb, "12.06[km]") 
     .CHECK_OUTPUT(aa, "12.06[km]")
     .CHECK_OUTPUT(dd+=ee, "40.2[kg]")
     .CHECK_OUTPUT(dd, "40.2[kg]")
     .CHECK_OUTPUT(gg+=ii, "6[hour]")
     .CHECK_OUTPUT(gg, "6[hour]")
      
     .CHECK_OUTPUT(bb-=cc, "5000[cm]")
     .CHECK_OUTPUT(bb, "5000[cm]") 
     .CHECK_OUTPUT(ff-=dd, "19.96[ton]") 
     .CHECK_OUTPUT(ff, "19.96[ton]") 
     .CHECK_OUTPUT(gg-=ii, "4[hour]")
     .CHECK_OUTPUT(gg, "4[hour]")  
      
      
   // opratot (<) && opratot (>)  
      
     .setname("Compatible dimensions") 
     .CHECK_OK(aa>bb)
     .CHECK_OK(aa>cc)
     .CHECK_OK(bb<aa)
     .CHECK_OK(bb>cc)
     .CHECK_OK(cc<aa)
     .CHECK_OK(cc<bb)
      
     .CHECK_OK(dd>ee)
     .CHECK_OK(dd<ff)  
     .CHECK_OK(ee<dd) 
     .CHECK_OK(ee<ff) 
     .CHECK_OK(ff>dd)      
     .CHECK_OK(ff>ee)
      
     .CHECK_OK(gg>hh) 
     .CHECK_OK(gg>ii) 
     .CHECK_OK(hh<gg)
     .CHECK_OK(ii<gg)
     .CHECK_OK(hh<ii)
     .CHECK_OK(ii>hh)
     
     .CHECK_EQUAL(bb>aa,false)
     .CHECK_EQUAL(cc>aa,false)
     .CHECK_EQUAL(ff>dd,true)
     .CHECK_EQUAL(ii<gg,true)
     .CHECK_EQUAL(hh>ii,false)
     .CHECK_EQUAL(ff<dd,false)
     .CHECK_EQUAL(ee<ff,true)
     .CHECK_EQUAL(cc<bb,true)
     .CHECK_EQUAL(hh<=ii,true) 
     .CHECK_EQUAL(ii>=hh,true) 
    
      
      
    // error output 
      
     .setname("Incompatible dimensions")
     .CHECK_THROWS(aa+dd)
     .CHECK_THROWS(bb+ee) 
     .CHECK_THROWS(cc+ff) 
     .CHECK_THROWS(dd+gg) 
     .CHECK_THROWS(ee+hh)  
     .CHECK_THROWS(ff+ii) 
      
     .CHECK_THROWS(cc-ii)
     .CHECK_THROWS(bb-hh) 
     .CHECK_THROWS(cc-gg) 
     .CHECK_THROWS(dd-ii) 
     .CHECK_THROWS(ee-gg) 
     .CHECK_THROWS(ff-aa) 
      
 
      
      
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
