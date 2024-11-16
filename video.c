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
   // YOUR CODE HERE - BEGIN
  int colorPixelSize = 24;   // 3 bytes per pixel for RGB (colored)
    int bwPixelSize = 1 ;  // 1 bit per pixel for Black/White image (1 bit = 1/8 byte)

    // Calculate total number of frames for the movie and credits
    float  totalFramesMovie = durationMovie * fps;
    float totalFramesCredits = durationCredits * fps;

    // Calculate the total size in bit
    float  totalSizeBit = 0;

    // Size of the movie frames (colored)
    totalSizeBit += totalFramesMovie * w * h * colorPixelSize;

    // Size of the credits frames (Black/White) - 1 bit per pixel
    totalSizeBit += totalFramesCredits * w * h * bwPixelSize;

    // Convert based on the unit specified
    if (strcmp(unit, "bt") == 0) {
        return totalSizeBit / 8; // Convert to bytes
    }
    else if (strcmp(unit, "ko") == 0) {
        return totalSizeBit / 1000.0; // Convert to kilobits
    }
    else if (strcmp(unit, "mo") == 0) {
        return totalSizeBit / (1000.0*1000.0); // Convert to megabits
    }
    else if (strcmp(unit, "go") == 0) {
        return totalSizeBit / (1000.0*1000.0*1000.0); // Convert to gigabits
    }
   // YOUR CODE HERE - END
   return 0;
}