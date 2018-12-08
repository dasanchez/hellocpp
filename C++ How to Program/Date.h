// Fig 9.17: Date.h

#ifndef DATE_H
#define DATE_H

// class Date definition
class Date
{
  public:
    Date(int = 2000, int = 1, int = 1); // default constructor

    void print();
    void nextDay();
    bool isLeapYear(const int);
    int daysInMonth(const int month, const int year);

  private:
    int month;
    int day;
    int year;

}; // end class Date

#endif