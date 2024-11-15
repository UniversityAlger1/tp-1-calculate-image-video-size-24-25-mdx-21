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
    float colorSectionSize = w * h * 3 * fps * durationMovie; // 3 bytes per pixel for RGB color
    float bwSectionSize = w * h * 1 * fps * durationCredits; // 1 byte per pixel for grayscale

    float totalSizeBytes = colorSectionSize + bwSectionSize;

    if (strcmp(unit, "bt") == 0) {
        return totalSizeBytes;
    } else if (strcmp(unit, "ko") == 0) {
        return totalSizeBytes * 8 / 1024;
    } else if (strcmp(unit, "mo") == 0) {
        return totalSizeBytes * 8 / (1024 * 1024);
    } else if (strcmp(unit, "go") == 0) {
        return totalSizeBytes * 8 / (1024 * 1024 * 1024);
    } else {
        return 0;
    }
}
