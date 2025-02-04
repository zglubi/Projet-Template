#include "RandomNumber.h"
#include <cstdlib>
#include <ctime>
using namespace std;
// D?finition de la fonction getRandomNumber
int randomNumber(int min, int max) {
    // Initialisation du g?n?rateur de nombres al?atoires
    static bool initialized = false;
    if (!initialized) {
        srand(time(0)); // Utilise le temps actuel pour initialiser le g?n?rateur
        rand();
        rand();
        rand();
        rand();
        initialized = true;
    }

    // G?n?ration d'un nombre al?atoire dans l'intervalle [min, max]
    return min + rand() % ((max - min) + 1);
}