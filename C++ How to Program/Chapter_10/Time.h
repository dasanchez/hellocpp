/*
 * Fig 10.15: Time.h
 * Cascading member function calls.
 * Member functions are defined in Time.cpp
*/

// prevent multiple inclusions of header
#ifndef TIME_H
#define TIME_H

// Time abstract data type definition
class Time
{
public:
  Time(int = 0, int = 0, int = 0); // default constructor

  // get functions (normally declared const)
  int getHour() const;   // return hour
  int getMinute() const; // return minute
  int getSecond() const; // return second

  void tick(); // increment second by one

  // print functions (normally declared const)
  void printUniversal() const; // print universal time
  void printStandard() const;  // print time in standard-time format

private:
  int secondsSinceMidnight; // 0 - 86399
};                          // end class Time

#endif
