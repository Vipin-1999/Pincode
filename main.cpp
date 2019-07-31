#include "pincode.h"

using namespace std;

int main()      {
    Pincode p;
    p.Ccode(); //to add codes from code.txt to vector
    // cout << p.Random(0, "560") << endl;
    cout << p.Validate("560078") << endl;
    return 0;
}