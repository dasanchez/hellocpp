/*
 * Fig 9.7: Utility function demonstration.
 * Compile this program with SalesPerson.cpp
*/

#include  "SalesPerson.h"

int main()
{
    SalesPerson s; // create SalesPerson object s
    s.getSalesFromUser(); // note simple sequential code; there are
    s.printAnnualSales(); // no control statements in main
} // end main
