// Fig 22.38: Standard Library algorithms min and max
#include <iostream>
#include <algorithm> // algorithm definitionsusing namespace std;

using std::cout;
using std::endl;
using std::max;
using std::min;

int main()
{
    cout << "The minimum of 12 and  7 is: " << min(12, 7);
    cout << "\nThe maximum of 12 and 7 is: " << max(12, 7);
    cout << "\nThe minimum of 'G' and 'Z' is: " << min('G', 'Z');
    cout << "\nThe maximum of 'G' and 'Z' is: " << max('G', 'Z');
    cout << endl;
} // end main
