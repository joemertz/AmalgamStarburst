#ifndef AMALGAMSTARBURST_STARBURST_H
#define AMALGAMSTARBURST_STARBURST_H

/*
 * The starburst is made up of 15 rays, starting with index 1.
 * Each ray is implemented by a chain of LEDs.
 * The same chain of LEDs may be split into multiple rays.
 * LEDs in a chain are addressable as an index, starting at 1.
 * Therefore, to address a single LED in a given ray, you need to know the chain
 * it is on and the index of the LED within that chain.
 */
class Starburst {
public:
	  // Returned by getLEDaddr, this gives the LED chain and LED light on it
    struct LEDaddr {
        int chain;
        int light;
    };

    LEDaddr getLEDaddr(int, int);

private:
    struct mRay {
        int chain; // The LED chain implementing this ray
        int startLight; // startLight is an index, relative to 1 (not 0)
        int numLights; // The number of lights on this ray
    };

    /*
		 * This is the main data structure representing how the chains of LEDs
		 * were used to display the rays.  These values of should match what is
		 * actually in the display.
		 *
		 * Sanity check: within the same chain, startLight of the nth ray should
		 * equal the startLight + numLights of the (n-1)th ray
		 */

		 // This is currently bogus data for testing
    mRay mRays[15] = {
            {1, 1,  60},		// ray 1, chain 1, LEDs 1 to 60 (60 total)
            {1, 61, 53}, 		// ray 2, chain 1, LEDs 61 to 113 (53 total)
            {1, 114, 48},		// ray 3
            {1, 162, 42},		// ray 4
            {2, 1, 49},			// ray 5
            {2, 50, 54},		// ray 6
            {2, 104, 60},		// ray 7
            {2, 164, 63},		// ray 8
            {3, 1, 62},			// ray 9
            {3, 63, 58},		// ray 10
            {3, 121, 50},		// ray 11
            {3, 171, 47},		// ray 12
            {4, 1, 43},			// ray 13
            {4, 44, 40},		// ray 14
            {4, 84, 40}			// ray 15
    };

};

#endif //AmalgamStarburst_STARBURST_H
