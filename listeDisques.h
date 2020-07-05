//
// Created by Mouad on 7/5/20.
//


#include <dirent.h>
#include <stdio.h>

#ifndef SYC2_TP_LISTEDISQUES_H
#define SYC2_TP_LISTEDISQUES_H

int Liste_Disques() {
    /*
         * Affichage des disques physiques
         * */

    DIR *rep;  //flux de repertoire
    struct dirent *fich; //structure des fichiers et repertoire

    rep = opendir("/dev");  //ouverture du repertoire /dev

    if (rep) {

        printf("Liste des disques physiques : \n");

        while ((fich = readdir(rep)) != NULL) {  //lecture fichier par fichier dans le repertoire /dev

            //Affichage des fichier contenant "hd" ou "sd"
            if (strstr(fich->d_name, "hd") != NULL) {

                printf("/dev/%s \n", fich->d_name);
            }
            if (strstr(fich->d_name, "sd") != NULL) {
                printf("/dev/%s \n", fich->d_name);
            }
        }

        closedir(rep);
        return 0;
    } else {
        return -1;
    }

}


#endif //SYC2_TP_LISTEDISQUES_H
