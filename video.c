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
float tailleSectionCouleur = w * h * 3 * 8 * fps * durationMovie;
    
    float tailleSectionNB = w * h * 8 * fps * durationCredits;
    
    float taille_en_bits = tailleSectionCouleur + tailleSectionNB;

    if (strcmp(unit, "bt") == 0) {
        return taille_en_bits / 8;
    } 
    else if (strcmp(unit, "ko") == 0) {
        return taille_en_bits / 1024;
    } 
    else if (strcmp(unit, "mo") == 0) {
        return taille_en_bits / 1024 / 1024;
    } 
    else if (strcmp(unit, "go") == 0) {
        return taille_en_bits / 1024 / 1024 / 1024;
    } 
    else {
        return taille_en_bits;
    }
}
