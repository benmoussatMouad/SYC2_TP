//
// Created by Mouad on 7/5/20.
//
#include <stdio.h>
#define TAILLE_SECTEUR 512

#ifndef SYC2_TP_LIRESECTEUR_H
#define SYC2_TP_LIRESECTEUR_H

unsigned char * LireSecteur(char * disquePhysique, int numSect) {
    unsigned char *buffer = malloc(sizeof(unsigned char) * TAILLE_SECTEUR);

    FILE *disk = NULL;
    char path[200] = "/dev/";
    strcat(path, disquePhysique); //concatenation des chaines de caractere pour avoir le chemin absolus

    disk = fopen(path, "rb");

    if (disk == NULL) {
        printf("Erreur lecture fichier");
        return NULL;
    } else {

        //decalage au debut du secteur cible
        fseek(disk, TAILLE_SECTEUR * numSect, SEEK_SET);

        //lecture des octets dans le tableau buffer
        fread(buffer, TAILLE_SECTEUR, 1, disk);
        return buffer;
    }
}

#endif //SYC2_TP_LIRESECTEUR_H
