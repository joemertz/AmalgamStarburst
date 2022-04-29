#ifndef AMALGAMSTARBURST_STARBURST_H
#define AMALGAMSTARBURST_STARBURST_H

/*
 * The starburst is made up of 15 rays, starting with index 0 (i.e. 0-14).
 * Each ray is implemented by a chain of LEDs.
 * The same chain of LEDs may be split into multiple rays.
 * LEDs in a chain are addressable as an index, starting at 0.
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
        int startLight; // startLight index, relative to 0
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
            {0, 0,  60},		// ray 0, chain 0, LEDs 0 to 59 (60 total)
            {0, 60, 53}, 		// ray 1, chain 0, LEDs 60 to 112 (53 total)
            {0, 113, 48},		// ray 2
            {0, 161, 42},		// ray 3
            {1, 0, 49},			// ray 4, chain 1, LEDs 0 to 48 (49 total)
            {1, 49, 54},		// ray 5
            {1, 103, 60},		// ray 6
            {1, 163, 63},		// ray 7
            {2, 0, 62},			// ray 8
            {2, 62, 58},		// ray 9
            {2, 120, 50},		// ray 10
            {2, 170, 47},		// ray 11
            {3, 0, 43},			// ray 12
            {3, 43, 40},		// ray 13
            {3, 83, 40}			// ray 14
    };

};

#endif //AmalgamStarburst_STARBURST_H
