#include <iostream>
#include "starburst.h"

/*
 * Given a zero-relative ray index and a zero-relative light index
 * on that ray, return a (LEDaddr) structure that contains the
 * corresponding zero-relative LED chain and LED light on that chain.
 * If problematic arguments, return chain or light of -1
 * (If you want to use exceptions, happy to do so.)
 */
Starburst::LEDaddr Starburst::getLEDaddr(int rayIndex, int lightIndex) {
    LEDaddr i; // the returned struct

	// Verify that rayIndex does not exceed the number of rays
	if (rayIndex >= (sizeof(mRays)/sizeof(mRay))) {
        i.chain = -1; // Bad rayIndex
        i.light = 0;
        return i;
    }

	mRay r = mRays[rayIndex];
    i.chain = r.chain;
	// Verify that lightIndex does not exceed the number of lights in this ray
    if (lightIndex >= r.numLights) {
        i.light = -1; // Bad lightIndex
        return i;
    }

    i.light = lightIndex + r.startLight;
    return i;
};
