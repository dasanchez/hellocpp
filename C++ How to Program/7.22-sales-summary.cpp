/*
 * Sales Summary
 * A comopany has four salespeople ( 1 to 4 ) who sell different products (1 to 5).
 * Once a day, each salesperson passes in a slip for each different
 * type of product sold. Each slip contains:
 * a. the salesperson number
 * b. the product number
 * c. the total dollar value of that product sold that day.
 * Each person passes in between 0 and 5 slips that day.
 * Read all this information for last month's sales (one salesperson's data
 * at a time) and summarize total sales by salesperson by product.
 * All totals should be stored in a two-dimensional array sales.
 * Print the results in tab format with columns representing salesperson
 * and rows product. Cross total columns to get total sales by salesperson.
 */

#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
    int salesPerson;
    int productType;
    int productTotal;
    const int productLine = 5;
    const int salesPeople = 4;
    int sales[ productLine ][ salesPeople ] = {};

    cout << "Enter salesperson number (1-4, enter 0 when done): ";
    cin >> salesPerson;
    // start taking passengers
    while ( salesPerson > 0 )
    {
        cout << "Enter product number (1-5): ";
        cin >> productType;
        cout << "Enter total sold for product " << productType << ": ";
        cin >> productTotal;

        if ( salesPerson <= salesPeople && productType <= productLine )
            sales [ productType-1 ][ salesPerson-1 ] = productTotal;
        
        cout << "Enter salesperson number (1-4, enter 0 when done): ";
        cin >> salesPerson;
    }

    // print grid headers
    cout << "          SP1   SP2   SP3   SP4   Total" << endl;

    // print array in tabular format
    for ( int row = 0; row < productLine; ++row)
    {
        int rowTotal = 0;
        cout << "PT" << row+1 << "    ";
        for ( int col = 0; col < salesPeople; ++col)
        {
            cout << setw(6) << sales[ row ][ col ];
            rowTotal += sales[ row ][ col ];
        }
        cout << setw( 8 ) << rowTotal << endl;
    }

    // print column totals
    cout << "Total  ";
    for ( int col = 0; col < salesPeople; ++col )
    {
        int colTotal = 0;
        for ( int row = 0; row < productLine; ++row )
        {
            colTotal += sales[ row ][ col ];
        }
        cout << setw( 6 ) << colTotal;
    }
    
    cout << endl;

    return 0;
} // end main
