#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) {
   // YOUR CODE HERE - BEGIN
   float taille_en_bits = w * h * 3 * 8;

   if (strcmp(unit, "bt") == 0) {
       return taille_en_bits;
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
