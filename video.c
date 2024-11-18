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
    long long framesMovie = (long long)durationMovie * fps;
    long long framesCredits = (long long)durationCredits * fps;
    long long totalBitsMovie = framesMovie * (long long)w * h * 24;
    long long totalBitsCredits = framesCredits * (long long)w * h * 8;
    long long totalBits = totalBitsMovie + totalBitsCredits;

    if (strcmp(unit, "bt") == 0) {
        return (float)totalBits;
    } else if (strcmp(unit, "ko") == 0) {
        return totalBits / (8.0 * 1000);
    } else if (strcmp(unit, "mo") == 0) {
        return totalBits / (8.0 * 1000 * 1000);
    } else if (strcmp(unit, "go") == 0) {
        return totalBits / (8.0 * 1000 * 1000 * 1000);
    }

    return 0.0;
}
