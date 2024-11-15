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
    const int bitTo_octet = 8;
    const int bitTo_kilobits = 1024;
    const int bitTo_megabytes = 1024 * 1024;
    const int bitTo_gigabytes = 1024 * 1024 * 1024;

    long long tailleSectionCouleur = (long long)w * h * 24 * fps * durationMovie;
    long long tailleSectionNB = (long long)w * h * 8 * fps * durationCredits;
    long long taille_en_bits = tailleSectionCouleur + tailleSectionNB;
    float tailleEnOctets = taille_en_bits / (float)bitTo_octet;

    if (strcmp(unit, "bt") == 0) {
        return taille_en_bits;
    } else if (strcmp(unit, "ko") == 0) {
        return taille_en_bits / bitTo_kilobits;
    } else if (strcmp(unit, "mo") == 0) {
        return tailleEnOctets / (1024 * 1024);
    } else if (strcmp(unit, "go") == 0) {
        return tailleEnOctets / (1024 * 1024 * 1024);
    } else {
        return 0;
    }
}
