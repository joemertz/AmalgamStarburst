#include <iostream>
#include "starburst.h"

/*
 * Given a ray index and a light index on that ray, return a
 * a (LEDaddr) structure that contains the corresponding LED
 * chain and LED on that chain.
 * If problematic arguments, return chain and light of -1
 * (If you want to use exceptions, happy to do so.)
 * Arguments are 1-relative indices, so the both start at 1 (not 0).
 */
Starburst::LEDaddr Starburst::getLEDaddr(int rayIndex, int lightIndex) {
    LEDaddr i; // the returned struct

	// Verify that rayIndex does not exceed the number of rays
	if (rayIndex > std::size(mRays)) {
        i.chain = -1; // Bad rayIndex
        i.light = 0;
        return i;
    }

    // mRays array is zero indexed, but the rayIndex argument is 1-relative
	mRay r = mRays[rayIndex - 1];

    i.chain = r.chain;
	// Verify that lightIndex does not exceed the number of lights in this ray
    if (lightIndex > r.numLights) {
        i.light = -1; // Bad lightIndex
        return i;
    }

    i.light = lightIndex + r.startLight - 1;
    return i;
};
