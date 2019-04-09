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
#include <cstdlib>
#include <ctime>

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
    //my test
    PhysicalNumber kg(1, Unit::KG);
    PhysicalNumber ton(3, Unit::TON);
    PhysicalNumber random_(rand()%100, Unit::G);
    srand(time(0));

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
    //ARITHMETICS
    .CHECK_OUTPUT(random_-random_,"0[g]")
    .CHECK_THROWS(kg+c)
    .CHECK_OUTPUT(kg+ton, "3001[kg]")
    .CHECK_OUTPUT(ton+kg,"1.001[ton]")
    .CHECK_OUTPUT(-kg, "-1[kg]")
    .CHECK_OUTPUT(-ton,"-3[ton]")
    .CHECK_OUTPUT(-a, "-2[km]")
    .CHECK_OUTPUT(kg+kg+ton+ton-ton,"3002[kg]")
    .CHECK_OUTPUT(++kg ,"2[kg]")
    .CHECK_OUTPUT(--kg , "1[kg]")
    //BOOLS
    .CHECK_EQUAL(kg == ton, false)
    .CHECK_EQUAL(kg == kg, true)
    .CHECK_EQUAL(kg != ton, true)
    .CHECK_EQUAL(kg != kg, false)
    .CHECK_EQUAL(kg < ton, true)
    .CHECK_EQUAL(kg <= ton, true)
    .CHECK_EQUAL(kg > ton, false)
    .CHECK_EQUAL(kg > ton, false)
    .CHECK_EQUAL(kg > ton && kg <= ton, false)
    .CHECK_EQUAL(kg > ton || kg <= ton, true)

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
