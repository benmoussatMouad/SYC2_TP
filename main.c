#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()  {

    /*
     * Affichage des disques physiques
     * */
    DIR *d;  //flux de repertoire
    struct dirent *dir; //structure des fichiers et repertoire

    d = opendir("/dev");  //ouverture du repertoire /dev

    if (d) {

        printf("Liste des disques physiques : \n");

        while ((dir = readdir(d)) != NULL) {  //lecture fichier par fichier dans le repertoire /dev
            //Affichage des fichier contenant "hd" ou "sd"
            if (strstr(dir->d_name, "hd") != NULL) {
                printf("/dev/%s \n", dir->d_name);
            }
            if (strstr(dir->d_name, "sd") != NULL) {
                printf("/dev/%s \n", dir->d_name);
            }
        }
        closedir(d);
    }



    return 0;
}
