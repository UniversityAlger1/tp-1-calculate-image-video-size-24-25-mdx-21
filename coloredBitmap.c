#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) {
   // YOUR CODE HERE - BEGIN
 // 24 bits per pixel for a colored image
    int bitsPerPixel = 24;
    
    // Calculate total bits
    float totalBits = w * h * bitsPerPixel;

    // Convert based on the unit specified
    if (strcmp(unit, "bt") == 0) {
        return totalBits; // Return in bits
    }
    else if (strcmp(unit, "ko") == 0) {
        return totalBits / 1000.0; // Convert to kilobits (1 kilobit = 1000 bits)
    }
    else if (strcmp(unit, "mo") == 0) {
        return totalBits / (1000.0 * 1000.0); // Convert to megabits (1 megabit = 1000 kilobits)
    }
    else if (strcmp(unit, "go") == 0) {
        return totalBits / (1000.0 * 1000.0 * 1000.0); // Convert to gigabits (1 gigabit = 1000 megabits)
    } 
   // YOUR CODE HERE - END
   return 0;
}