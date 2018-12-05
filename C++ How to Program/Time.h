/*
 * Fig 9.8: Time.h
 * Time class containing a constructor with default arguments.
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

    // set functions
    void setTime(int, int, int); // set hour, minute, and second
    void setHour(int);           // set hour (after validation)
    void setMinute(int);         // set minute (after validation)
    void setSecond(int);         // set second (after validation)

    int &badSetHour(int); // DANGEROUS reference return

    // get functions
    int getHour();   // return hour
    int getMinute(); // return minute
    int getSecond(); // return second

    void printUniversal(); // print time in universal-time format
    void printStandard();  // print time in standard-time format

  private:
    int hour;   // 0 - 23 (24-hr clock format)
    int minute; // 0 - 59
    int second; // 0 - 59
};              // end class Time

#endif
