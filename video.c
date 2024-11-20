#include <string.h>
#include "config/video.h"

// Parameters:
// w: width of the image
// h: height of the image
// durationMovie: duration in second of movie (colored image)
// durationCredits: duration in second of credit (image Black/White)
// fps: Frames Per Second of the video
// unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
// colored video size (based on the unit passed parameter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Calculate the size of the colored section (in bits)
    int coloredFrames = durationMovie * fps;
    int coloredSizeBits = coloredFrames * w * h * 24; // 24 bits per pixel for color

    // Calculate the size of the black and white section (in bits)
    int creditFrames = durationCredits * fps;
    int creditSizeBits = creditFrames * w * h * 8; // 8 bits per pixel for grayscale

    // Total size in bits
    long totalSizeBits = coloredSizeBits + creditSizeBits;

    // Convert to the requested unit
    if (strcmp(unit, "bt") == 0) {
        return totalSizeBits / 8.0; // Convert bits to bytes
    } else if (strcmp(unit, "ko") == 0) {
        return totalSizeBits / 1024.0; // Convert bits to kilobits
    } else if (strcmp(unit, "mo") == 0) {
        return totalSizeBits / (1024.0 * 1024.0); // Convert bits to megabits
    } else if (strcmp(unit, "go") == 0) {
        return totalSizeBits / (1024.0 * 1024.0 * 1024.0); // Convert bits to gigabits
    } else {
        return 0; // Return 0 for unsupported units
    }
}
