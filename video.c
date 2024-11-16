#include <string.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    int colorBitsPerPixel = 24;
    int bwBitsPerPixel = 8;

    long long totalColorBits = w * h * colorBitsPerPixel * fps * durationMovie;
    long long totalBWBits = w * h * bwBitsPerPixel * fps * durationCredits;
    long long totalBits = totalColorBits + totalBWBits;

    if (strcmp(unit, "bt") == 0) {
        return (float)totalBits / 8;
    } else if (strcmp(unit, "ko") == 0) {
        return (float)totalBits / 8 / 1024;
    } else if (strcmp(unit, "mo") == 0) {
        return (float)totalBits / 8 / 1024 / 1024;
    } else if (strcmp(unit, "go") == 0) {
        return (float)totalBits / 8 / 1024 / 1024 / 1024;
    } else {
        return -1;
    }
}
