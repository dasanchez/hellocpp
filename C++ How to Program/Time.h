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

  // set functions (the Time & return types enable cascading)
  Time &setTime(int, int, int); // set hour, minute, and second
  Time &setHour(int);           // set hour (after validation)
  Time &setMinute(int);         // set minute (after validation)
  Time &setSecond(int);         // set second (after validation)

  // get functions (normally declared const)
  int getHour() const;   // return hour
  int getMinute() const; // return minute
  int getSecond() const; // return second

  void tick(); // increment second by one

  // get functions
  // int getHour();   // return hour
  // int getMinute(); // return minute
  // int getSecond(); // return second

  // print functions (normally declared const)
  void printUniversal() const; // print universal time
  void printStandard() const; // print time in standard-time format

private:
  int hour;   // 0 - 23 (24-hr clock format)
  int minute; // 0 - 59
  int second; // 0 - 59
};            // end class Time

#endif
