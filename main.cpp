#include <iostream>
#include "starburst.h"

using namespace std;
/*
 * A tester for the starburst class.
 *
 * Given a ray and a light on that ray, give the chain and LED within that chain
 */

int main() {
    Starburst s;
    int r, l;
    while (true) {
        cout << " Ray? ";
        cin >> r;
        cout << " Light? ";
        cin >> l;
        Starburst::LEDaddr i = s.getLEDaddr(r, l);
        if (i.chain == -1) {
            std::cout << "Invalid ray" << std::endl;
        } else if (i.light == -1) {
            std::cout << "Invalid light" << std::endl;
        } else {
            std::cout << "chain: " << i.chain << " , light: " << i.light << std::endl;
        }
    }
    return 0;
}
