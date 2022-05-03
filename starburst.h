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
    mRay mRays[24] = {
            {0, 0, 30},		// ray 0, chain 0, LEDs 0 to 29 (30 total)
            {0, 30, 39}, 	// ray 1, chain 0, LEDs 30 to 68 (39 total)
            {0, 69, 33},	// ray 2
            {0, 102, 39},	// ray 3
            {0, 141, 24},	// ray 4
            {0, 165, 30},	// ray 5
            {1, 0, 48},		// ray 6
            {1, 48, 33},	// ray 7
            {1, 81, 45},	// ray 8
            {1, 126, 39},	// ray 9
            {1, 165, 27},	// ray 10
            {1, 192, 36},	// ray 11
            {2, 0, 36},		// ray 12
            {2, 36, 24},	// ray 13
            {2, 60, 38},	// ray 14
            {2, 98, 42},	// ray 15
            {2, 140, 36},	// ray 16
            {2, 176, 36},	// ray 17
            {3, 0, 48},		// ray 18
            {3, 48, 33},	// ray 19
            {3, 81, 54},	// ray 20
            {3, 135, 27},	// ray 21
            {3, 162, 24},	// ray 22
            {3, 186, 27}	// ray 23
    };

};

#endif //AmalgamStarburst_STARBURST_H
