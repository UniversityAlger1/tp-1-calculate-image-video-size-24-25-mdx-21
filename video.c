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
    const int bit_per_pixel_color = 24;
    const int bit_per_pixel_bw = 8;
    
    long long totalFramesMovie = durationMovie * fps;
    long long totalFramesCredits = durationCredits * fps;
    
    long long sizeMovieBits = w * h * bit_per_pixel_color * totalFramesMovie;
    long long sizeCreditsBits = w * h * bit_per_pixel_bw * totalFramesCredits;
    
    long long totalSizeBits = sizeMovieBits + sizeCreditsBits;
    
    float sizeInUnit = 0.0;
    
    if (strcmp(unit, "bt") == 0) {
        sizeInUnit = totalSizeBits / 8.0;
    } else if (strcmp(unit, "ko") == 0) {
        sizeInUnit = totalSizeBits / 8.0 / 1024.0;
    } else if (strcmp(unit, "mo") == 0) {
        sizeInUnit = totalSizeBits / 8.0 / 1024.0 / 1024.0;
    } else if (strcmp(unit, "go") == 0) {
        sizeInUnit = totalSizeBits / 8.0 / 1024.0 / 1024.0 / 1024.0;
    }
    
    return sizeInUnit;
}
