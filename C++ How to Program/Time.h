/*
 * Fig 9.1: Time.h
 * Time class definition
 * Member functions are defined in Time.cpp
*/

// prevent multiple inclusions of header
#ifndef TIME_H
#define TIME_H

// Time class definition
class Time
{
    public:
    Time(); // constructor
    void setTime(int, int, int); // set hour, minute, and second
    void printUniversal(); // print time in universal-time format
    void printStandard(); // print time in standard-time format
    private:
    int hour; // 0 - 23 (24-hr clock format)
    int minute; // 0 - 59
    int second; // 0 - 59
}; // end class Time

#endif
