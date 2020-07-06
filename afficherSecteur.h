//
// Created by Mouad on 7/5/20.
//

#include <stdio.h>
#include <stdlib.h>
#include "lireSecteur.h"

#define TAILLE_SECTEUR 512

#ifndef SYC2_TP_AFFICHERSECTEUR_H

#define SYC2_TP_AFFICHERSECTEUR_H

int AfficherSecteur(char* disquePhysique, int numSect) {

    unsigned char *buffer = malloc(sizeof(unsigned char) * TAILLE_SECTEUR);
    buffer = LireSecteur(disquePhysique, numSect);
    if (buffer == NULL) {
        printf("Erreur lecture secteur\n");
        return -1;

    } else {

        //affichage
        printf("ADRESSE \tContenu(octet de 1 a 16)\n");

        unsigned int adresse = TAILLE_SECTEUR * numSect;
        printf("%04d \t", adresse);
        adresse += 16;

        for (int l = 0; l < TAILLE_SECTEUR; ++l) {

            printf("%02x ", buffer[l]);
            //saut de ligne pour chaque 16 octets
            if ((l + 1) % 16 == 0) {
                printf("\n");
                printf("%06d \t", adresse);
                adresse += 16;
            }
        }
        return 0;
    }
}

#endif //SYC2_TP_AFFICHERSECTEUR_H
