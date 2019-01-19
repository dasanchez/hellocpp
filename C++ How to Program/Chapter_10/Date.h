// Fig 10.8: Date.h

#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

// class Date definition
class Date
{
public:
  static const int monthsPerYear = 12; // number of months in a year
  static string spelledMonths[12];
  Date(int, int, int);             // default constructor
  Date(int, int);                  // constructor for day-year
  Date(string, int, int);          // constructor for MONTH DD, YYYY
  Date();                          // constructor that uses ctime
  void print() const;              // print date in YYYY/MM/DD format
  void printDayYear() const;       // print date in DDD/YYYY format
  void printAmerican() const;      // print date in MM/DD/YY format
  void printVerbose() const;       // print date in [Month] DD, YYYY
  int daysInMonth(int, int) const; // returns days in month and year
  int monthFromWord(string) const; // returns month number
  ~Date();

private:
  int month; // 1-12 (January-December)
  int day;   // 1-31 based on month
  int year;  // any year

  // utility function to check if day is proper for month and year
  int checkDay(int) const;
}; // end class Date

#endif