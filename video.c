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
    long coloredSizeBits = (long)coloredFrames * w * h * 24; // 24 bits per pixel for color

    // Calculate the size of the black and white section (in bits)
    int creditFrames = durationCredits * fps;
    long creditSizeBits = (long)creditFrames * w * h * 8; // 8 bits per pixel for grayscale

    // Total size in bits
    long totalSizeBits = coloredSizeBits + creditSizeBits;

    // Convert total size to bytes
    float totalSizeBytes = totalSizeBits / 8.0;

    // Convert to the requested unit
    if (strcmp(unit, "bt") == 0) {
        return totalSizeBytes; // Bytes
    } else if (strcmp(unit, "ko") == 0) {
        return totalSizeBytes / 1024.0; // Kilobytes
    } else if (strcmp(unit, "mo") == 0) {
        return totalSizeBytes / (1024.0 * 1024.0); // Megabytes
    } else if (strcmp(unit, "go") == 0) {
        return totalSizeBytes / (1024.0 * 1024.0 * 1024.0); // Gigabytes
    } else {
        return 0; // Return 0 for unsupported units
    }
}
