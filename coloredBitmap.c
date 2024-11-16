#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) {
    int bitsPerPixel = 24;
    long long totalBits = w * h * bitsPerPixel;

    if (strcmp(unit, "bt") == 0) {
        return (float)totalBits;
    } else if (strcmp(unit, "ko") == 0) {
        return (float)totalBits / 1024;
    } else if (strcmp(unit, "mo") == 0) {
        return (float)totalBits / 1024 / 1024;
    } else if (strcmp(unit, "go") == 0) {
        return (float)totalBits / 1024 / 1024 / 1024;
    } else {
        return -1;
    }
}
