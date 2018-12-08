// Ex 9.9: DateAndTime.h

#ifndef DATEANDTIME_H
#define DATEANDTIME_H

// class DateAndTime definition
class DateAndTime
{
  public:
    DateAndTime(int = 2000, int = 1, int = 1,
                int = 0, int = 0, int = 0); // default constructor: y,m,d,hh,mm,ss

    void nextDay();
    bool isLeapYear(const int);
    int daysInMonth(const int month, const int year);

    // set functions
    void setTime(int, int, int); // set hour, minute, and second
    void setHour(int);           // set hour (after validation)
    void setMinute(int);         // set minute (after validation)
    void setSecond(int);         // set second (after validation)

    void tick(); // increment second by one

    // get functions
    int getHour();   // return hour
    int getMinute(); // return minute
    int getSecond(); // return second

    void printUniversal(); // print date and time in universal-time format
    void printStandard();  // print date and  time in standard-time format
    
  private:
    int month; // 1 - 12
    int day;   // 1 - xx
    int year;  // 1 - undefined
     int hour;   // 0 - 23 (24-hr clock format)
    int minute; // 0 - 59
    int second; // 0 - 59


}; // end class DateAndTime

#endif