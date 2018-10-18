// Fig 7.23: GradeBook.cpp
// Member-function definitions for class GradeBook that
// uses  a multi-dimensional array to store grades.
#include <iostream>
#include <iomanip>
#include "GradeBook.h"
using namespace std;

// two-argument constructor initializes courseName and grades array
GradeBook::GradeBook(string name, const int gradesArray[][tests])
{
    setCourseName(name); // initialize courseName

    // copy grades from gradesArray to grades data member
    for (int student = 0; student < students; ++student)
        for (int test = 0; test < tests; ++test)
            grades[student][test] = gradesArray[student][test];
} // end two-argument GradeBook constructor

// function to set the course name
void GradeBook::setCourseName(string name)
{
    courseName = name; // store the course name
} // end function setCourseName

// function to retrieve the course name
string GradeBook::getCourseName()
{
    return courseName;
} // end function getCourseName

// display a welcome message to the GradeBook user
void GradeBook::displayMessage()
{
    // this  statement calls getCourseName to get the
    // name of the course this GradeBook represents
    cout << "Welcome to the grade book for \n"
         << getCourseName() << "!" << endl;
} // end function displayMessage

// perform various operations on the data
void GradeBook::processGrades()
{
    outputGrades(); // output grades array

    // display average of all grades and minimum and maximum grades
    cout << "\nLowest grade in the gradebook is " << getMinimum() 
    << "\nHighest grade in the gradebook is " << getMaximum() << endl;

    outputBarChart(); // print grade distribution chart
} // end function processGrades

// find minimum grade in the entire gradebook
int GradeBook::getMinimum()
{
    int lowGrade = 100; // assume lowest grade is 100

    // loop through rows of grades array
    for (int student = 0; student < students; ++student)
    {
        // loop through columns of current row
        for (int test = 0; test < tests; ++test)
        {
            // if ccurrent grade lower than lowGrade, assign it to lowGrade
            if (grades[student][test] < lowGrade)
                lowGrade = grades[student][test]; // new lowestGrade
        }                                         // end inner for
    }                                             // end outer for
    return lowGrade;                              // return lowest grade
} // end function getMinimum

// find maximum grade in the entire gradebook
int GradeBook::getMaximum()
{
    int highGrade = 0; // assume highest grade is 0

    // loop through rows of grades array
    for (int student = 0; student < students; ++student)
    {
        // loop through columns of current row
        for (int test = 0; test < tests; ++test)
        {
            // if current grade higher than highGrade, assign it to highGrade
            if (grades[student][test] > highGrade)
                highGrade = grades[student][test]; // new lowestGrade
        }                                          // end inner for
    }                                              // end outer for
    return highGrade;                              // return lowest grade
} // end function getMaximum

// determine aver<ge grade for particular set of grades
double GradeBook::getAverage(const int setOfGrades[], const int grades)
{
    int total = 0; // initialize total

    // sum grades in array
    for (int grade = 0; grade < grades; ++grade)
        total += setOfGrades[grade];

    // return average of grades
    return static_cast<double>(total) / grades;
} // end function getAverage

// output bar chart displaying grade distribution
void GradeBook::outputBarChart()
{
    cout << "\nGrade distribution:" << endl;

    // stores frequency of grades in each range of 10 grades
    const int frequencySize = 11;
    int frequency[frequencySize] = {}; // initialize elments to 0

    // for each grade, increment the appropriate frequency
    for (int student = 0; student < students; ++student)
        for (int test = 0; test < tests; ++test)
            ++frequency[grades[student][test] / 10];

    // for each grade frequency, print bar in chart
    for (int count = 0; count < frequencySize; ++count)
    {
        // output bar labels ("0-9:", ..., "90-99", "100:" )
        if (count == 0)
            cout << "  0-9: ";
        else if (count == 10)
            cout << "  100: ";
        else
            cout << count * 10 << "-" << (count * 10) + 9 << ": ";

        // print bar of asterisks
        for (int stars = 0; stars < frequency[count]; ++stars)
            cout << '*';

        cout << endl; // start a new line of output
    }                 // end outer for
} // end function outputBarChart

// out put the contents of the grades array
void GradeBook::outputGrades()
{
    cout << "\nThe grades are:\n\n";
    cout << "            "; // align column heads

    // create a column heading for each of the tests
    for (int test = 0; test<tests; ++test)
        cout << "Test " << test + 1 << "  ";

    cout << "Average" << endl; // student average column heading

    // create rows/columns of text representing array grades
    for (int student = 0; student < students; ++student)
    {
        cout << "Student " << setw(2) << student + 1;

        // output student's grades
        for (int test = 0; test < tests; ++test)
            cout << setw(8) << grades[student][test];

        // call member function getAverage to calculate student's average;
        // pass row of grades and the value of tests as the arguments
        double average = getAverage(grades[student], tests);
        cout << setw(9) << setprecision(2) << fixed << average << endl;
    } // end outer for
} // end function outputGrades