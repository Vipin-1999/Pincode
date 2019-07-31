#include "pincode.h"

using namespace std;

int main()      {
    Pincode p;
    p.Ccode(); //to add codes from te.txt to vector
    cout << p.Random(0, "560") << endl;
    return 0;
}