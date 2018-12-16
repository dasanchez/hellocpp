/*
 * Fig 10.3: Attempting to access a const object with non-const
 * member functions. 
*/
#include "Time.h"
using namespace std;

int main()
{
    Time wakeup(6, 45, 0);     // non-constant object
    const Time noon(12, 0, 0); // constant object

                        // OBJECT       MEMBER FUNCTION
    wakeup.setHour(18); // non-const    non-const
    noon.setHour(12);   // const        non-const
    wakeup.getHour();   // non-const    const
    noon.getMinute();   // const        const
    noon.printUniversal(); // const     const
    noon.printStandard(); // const      non-const
} // end main
