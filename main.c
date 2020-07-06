#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listeDisques.h"
#include "afficherSecteur.h"

int main()  {

    if (Liste_Disques() !=0) printf("Erreur: impossible d'afficher la liste des disques.");

    if (AfficherSecteur("sda", 1) != 0) printf("Impossible d'afficher le secteur");

    return 0;
}
