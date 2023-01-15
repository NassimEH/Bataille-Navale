/* Da Veiga Sanches Carvalho Flavio */
/* El Haddad Nassim */

/*Code partie 2*/
/*--------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ajoutNavireAleatoireDeux(char tab[][10], char b, int t) {
  int ligne;
  int colonne;
  int direction;
  int test = 1;
  int cpt = 0;
  int i;
  /*Récupère un entier entre 0 et 1*/
  direction = rand() % 2;

  /*si horizontale: On tire au sort la ligne et la colonne et on vérifie si les
   * cases où on veut placer le navire sont déjà occupées. on sort de la boucle
   * si les conditions sont vérifiés,sinon on répète jusqu'à ce que les cases où
   * on veut placer le navire soient vides */
  if (direction == 0) {
    while (test != 0) {
      ligne = rand() % 10;
      colonne = rand() % 10;
      /*Boucle permettant de savoir si toutes le cases où on veut placer le
       * navire n'ont pas un autre navire*/
      for (i = colonne; i < t; i++) {
        if (tab[ligne][i] != 'A' && tab[ligne][i] != 'C' &&
            tab[ligne][i] != 'S' && tab[ligne][i] != 'M' &&
            tab[ligne][i] != 'T') {
          test = 0;
        } else {
          test = 1;
        }
      }
    }
  }

  /*Si vertical: On tire au sort la ligne et la colonne et on vérifie si les
   * cases où on veut placer le navire sont déjà occupées. on sort de la boucle
   * si les conditions sont vérifiés,sinon on répète jusqu'à ce que les cases où
   * on veut placer le navire soient vides */
  if (direction == 1) {
    while (test != 0) {
      ligne = rand() % 10;
      colonne = rand() % 10;
      /*Boucle permettant de savoir si toutes le cases où on veut placer le
       * navire n'ont pas un autre navire*/
      for (i = ligne; i < t; i++) {
        if (tab[i][colonne] != 'A' && tab[i][colonne] != 'C' &&
            tab[i][colonne] != 'S' && tab[i][colonne] != 'M' &&
            tab[i][colonne] != 'T') {
          test = 0;
        } else {
          test = 1;
        }
      }
    }
  }

  /*On place le navire horizontalement*/
  if (direction == 0) {
    while (cpt < t) {
      tab[ligne][colonne] = b;
      colonne++;
      cpt++;
    }
    /*On place le navire verticalement*/
  } else if (direction == 1) {
    while (cpt < t) {
      tab[ligne][colonne] = b;
      ligne++;
      cpt++;
    }
  }
}

int verifDeux(char tab[][10]) {

  int i;
  int j;
  int nbValeurs = 0;
  /*On fait le parcours de la boucle et on vérifie s'il y a bien 17 valeurs qui
   * sont différentes d'un espace */
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      if (tab[i][j] != ' ') {
        nbValeurs++;
      }
    }
  }
  if (nbValeurs == 17) {
    return 1;
  } else {
    return 0;
  }
}

void afficheDeux(char t[][10]) {
  int ligneP1 = 0;
  int colonneP1;
  char lettre = 'A';
  int remplissage = 0;
  /*remplissage représente le nombre de fois que la boucle va se répéter*/
  while (remplissage < 10) {
    /*on affiche la ligne des coordonnées*/
    if (remplissage == 0) {
      printf("_|0|1|2|3|4|5|6|7|8|9|\n");
    }
    /*à chaque fois que la boucle se répéte on affiche une lettre des
     * coordonnées*/
    if (remplissage < 10) {
      printf("%c|", lettre);
    }
    /*S'il n'y existe pas un caractère représentant un navire dans la case on
     * met un espace sinon on affiche le caractère qui est dans la case*/
    for (colonneP1 = 0; colonneP1 < 10; ++colonneP1) {
      if ((t[ligneP1][colonneP1] == '\0' || t[ligneP1][colonneP1] != 'A') &&
          t[ligneP1][colonneP1] != 'C' && t[ligneP1][colonneP1] != 'S' &&
          t[ligneP1][colonneP1] != 'M' && t[ligneP1][colonneP1] != 'T') {
        /*si la condition est vérifié on met un espace dans la case*/
        t[ligneP1][colonneP1] = ' ';
        printf("%c|", t[ligneP1][colonneP1]);
      } else {
        printf("%c|", t[ligneP1][colonneP1]);
      }
    }
    /*on incréménte les variables et on fait un saut de line*/
    ligneP1++;
    remplissage++;
    lettre++;
    printf("\n");
  }
  printf("\n");
}

void afficheDuoDeux(char t[][10], char p[][10]) {
  int ligneP1 = 0;
  int ligneP2 = 0;
  int colonneP1;
  int colonneP2;
  char lettre = 'A';
  int remplissage = 0;
  /*remplissage représente le nombre de fois que la boucle va se répéter*/
  while (remplissage < 10) {
    /*on affiche la ligne des coordonnées pour les deux plateaux*/
    if (remplissage == 0) {
      printf("_|0|1|2|3|4|5|6|7|8|9|   ");
      printf("_|0|1|2|3|4|5|6|7|8|9|\n");
    }
    /*à chaque fois que la boucle se répéte on affiche une lettre des
     * coordonnées pour les deux*/
    if (remplissage < 10) {
      printf("%c|", lettre);
    }
    /*on fait le parcours du plateau on mets un espace dans la case si  la
     * condition est vérifié*/
    for (colonneP1 = 0; colonneP1 < 10; ++colonneP1) {
      if (t[ligneP1][colonneP1] != 'A' && t[ligneP1][colonneP1] != '.' &&
          t[ligneP1][colonneP1] != 'x' && t[ligneP1][colonneP1] != 'C' &&
          t[ligneP1][colonneP1] != 'S' && t[ligneP1][colonneP1] != 'M' &&
          t[ligneP1][colonneP1] != 'A') {
        /*si la condition est vérifié on met un espace dans la case*/
        t[ligneP1][colonneP1] = ' ';
        printf("%c|", t[ligneP1][colonneP1]);
        /*S'il y a un point dans la case on l'affiche*/
      } else if (t[ligneP1][colonneP1] == '.') {
        printf("%c|", t[ligneP1][colonneP1]);
        /*S'il y a un x dans la case on l'affiche*/
      } else if (t[ligneP1][colonneP1] == 'x') {
        printf("%c|", t[ligneP1][colonneP1]);
        /*sinon on affiche juste un espace*/
      } else {
        printf(" |");
      }
    }
    ligneP1++;
    printf("   ");

    /*On fait la même chose pour le deuxième plateau*/

    if (remplissage < 10) {
      printf("%c|", lettre);
    }
    for (colonneP2 = 0; colonneP2 < 10; ++colonneP2) {
      if ((p[ligneP2][colonneP2] != 'A' && p[ligneP2][colonneP2] != '.' &&
           p[ligneP2][colonneP2] != 'x' && p[ligneP2][colonneP2] != 'C' &&
           p[ligneP2][colonneP2] != 'S' && p[ligneP2][colonneP2] != 'M' &&
           p[ligneP2][colonneP2] != 'A')) {
        p[ligneP2][colonneP2] = ' ';
        printf("%c|", p[ligneP2][colonneP2]);

      } else if (p[ligneP2][colonneP2] == 'x') {
        printf("%c|", p[ligneP2][colonneP2]);
      } else if (p[ligneP2][colonneP2] == '.') {
        printf("%c|", p[ligneP2][colonneP2]);
      } else {
        printf(" |");
      }
    }
    /*On incrémente les variables et on fait un saut de ligne*/
    ligneP2++;
    printf("\n");
    remplissage++;
    lettre++;
  }
  printf("\n");
}

/*Fonction permettant de placer les navires à la main*/
void placerBateau(char tab[][10]) {
  char b;
  int t;
  int res;
  int taille = 0;
  int cpt;
  char switchTest;
  int naviresPlaces = 0;

  /*Tableau pour stocker les coordonnées saisis par le joueur*/
  char coord[10] = {'\0'};
  /*initialisation des varibles qui serviront à donner les coordonnées du
   * navire*/
  int indiceLigne = 0;
  int indiceColonne = 0;
  int indice1 = 0;
  int indice2 = 0;
  int i = 0;
  int j = 0;
  char tabLettres[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
  char tabNombres[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

  printf("Vous devez placer vos navires.\n Pour chaque navire, indiquez "
         "horizontal(h) ou vertical (v),"
         "suivi de la case la plus nord-ouest (ex : h,E4).\n\n");

  /*Boucle principale permettant de placer tous les navires */
  for (naviresPlaces = 0; naviresPlaces < 5; naviresPlaces++) {
    if (naviresPlaces == 0) {
      b = 'A';
      t = 5;
    } else if (naviresPlaces == 1) {
      b = 'C';
      t = 4;
    } else if (naviresPlaces == 2) {
      b = 'S';
      t = 3;
    } else if (naviresPlaces == 3) {
      b = 'M';
      t = 3;
    } else if (naviresPlaces == 4) {
      b = 'T';
      t = 2;
    }
    do {
      afficheDeux(tab);
      printf("\n");
      printf("Placez votre %c (longueur %d) :\n", b, t);
      scanf("%s", coord);

      /*Boucle utilisée pour trouver la ligne choisi par le joueur*/
      for (indice1 = 0; indice1 < 10; ++indice1) {
        if (coord[2] == tabLettres[indice1]) {
          indiceLigne = indice1;
          break;
          ;
        }
      }

      /*Boucle utilisée pour trouver la colonne choisi par le joueur*/
      for (indice2 = 0; indice2 < 10; ++indice2) {
        if (coord[3] == tabNombres[indice2]) {
          indiceColonne = indice2;
          break;
        }
      }

      i = indiceLigne;
      j = indiceColonne;
      res = 0;
      cpt = 0;

      switchTest = 0;
      /*condition permettant de savoir si le troisième caractère rentré par le
       * jouer est bien une des lettres des coordonnées*/
      if ((coord[2] == 'A' || coord[2] == 'B') ||
          (coord[2] == 'C' || coord[2] == 'D') ||
          (coord[2] == 'E' || coord[2] == 'F') ||
          (coord[2] == 'G' || coord[2] == 'H') ||
          (coord[2] == 'I' || coord[2] == 'J')) {
        switchTest = 1;
      }

      /*Boucle utilisée pour savoir si le navire a été bien placé*/
      while (cpt < t && res == 0) {
        if (coord[1] != ',') {
          res++;
          printf("Format des coordonnées non respecté\n");
          printf("\n");
        }
        if (res == 0) {

          if (tab[i][j] == 'A' || tab[i][j] == 'C' || tab[i][j] == 'S' ||
              tab[i][j] == 'M' || tab[i][j] == 'T') {
            printf("Le navire empiete sur un autre \n");
            printf("\n");
            res++;
            break;
          }
          if (i > 10 || j > 10) {
            printf("Navire sortant des limites\n");
            res++;
            break;
          } else if (coord[4] != '\0') {
            printf("Navire sortant des limites\n");
            res++;
            break;

          } else if ((coord[2] == 'A' || coord[2] == 'B') &&
                     (coord[2] == 'C' || coord[2] == 'D') &&
                     (coord[2] == 'E' || coord[2] == 'F') &&
                     (coord[2] == 'G' || coord[2] == 'H') &&
                     (coord[2] == 'I' || coord[2] == 'J')) {

            printf("Navire sortant des limites,saisissez d'abord la lettre "
                   "puis le numéro\n\n");
            res++;
            break;
          } else if (coord[0] != 'h' && coord[0] != 'v') {
            printf("le navire doit être soit à l'horizontal (h) soit à la "
                   "verticale (v) \n");
            res++;
            break;
          } else if (switchTest == 0) {
            printf("Navire sortant des limites,saisissez d'abord la lettre "
                   "puis le numéro\n\n");
            res++;
          }

          /*si horizontale on incrémente la varible j correspondant aux
           * colonnes variable cpt incrémenté */

          switch (coord[0]) {
          case 'h':
            j++;
            cpt++;
            break;
          /*si verticale on incrémente la varible i correspondant aux lignes*/
          case 'v':
            i++;
            cpt++;
            break;
          }
        }
      }

      /*S'il y a une condition ci-dessus qui est vérifié la variable "res"
      sera incrementé et on recommencera le programme car la condition
      principale .while n'est pas vérifié*/

    } while (res != 0);

    /*Boucle utilisé pour placer le navire soit horizontalement soit
     verticalement*/
    while (taille < t) {

      if (coord[0] == 'h') {
        tab[indiceLigne][indiceColonne] = b;
        indiceColonne++;
        taille++;
      } else if (coord[0] == 'v') {
        tab[indiceLigne][indiceColonne] = b;
        indiceLigne++;
        taille++;
      }
    }
    taille = 0;
    printf("\n");
    printf("\n");
  }
  afficheDeux(tab);
}

void initPlateauDeux(char plat[][10]) {
  srand(time(NULL));
  int test = 1;
  int var = 0;
  char choix[2];

  /*tant que le caractère est différent de 'A' et de 'M' on ne sort pas de la
   * boucle */
  do {
    printf("Souhaitez-vous placer les Navires à la main (M), ou aléatoirement "
           "(A) ?\n");
    scanf("%s", choix);
  } while (choix[0] != 'A' && choix[0] != 'M');

  do {
    if (choix[0] == 'M') {
      placerBateau(plat);

    } else if (choix[0] == 'A') {
      ajoutNavireAleatoireDeux(plat, 'A', 5);
      ajoutNavireAleatoireDeux(plat, 'C', 4);
      ajoutNavireAleatoireDeux(plat, 'S', 3);
      ajoutNavireAleatoireDeux(plat, 'M', 3);
      ajoutNavireAleatoireDeux(plat, 'T', 2);
    }
    /*Si il y a 17 cases avec des valeurs différentes d'un espace on sort de la
     * boucle principale*/
    if (choix[0] == 'A') {
      for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
          if (plat[i][j] != ' ') {
            var++;
          }
        }
      }
    }
    if (var == 17) {
      test = 0;
    } else {
      /*Sinon on remplace toutes les cases du plateau par des espaces et on
       * recommence*/
      for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
          plat[i][j] = ' ';
        }
        var = 0;
      }
    }
  } while (test == 1);
}

int jouerJoueurDeux(char adv[][10]) {
  char t[5];
  char tabLettres[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
  char tabNombres[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  int indice1, indice2, indiceLigne, indiceColonne;
  printf("Rentrez des coordonnées : \n");
  scanf("%s", t);

  /*Boucle utilisées pour trouver la ligne choisi par le joueur*/
  for (indice1 = 0; indice1 < 10; ++indice1) {
    if (t[0] == tabLettres[indice1]) {
      indiceLigne = indice1;
      break;
      ;
    }
  }
  /*Boucle utilisées pour trouver la colonne choisi par le joueur*/
  for (indice2 = 0; indice2 < 10; ++indice2) {
    if (t[1] == tabNombres[indice2]) {
      indiceColonne = indice2;
      break;
    }
  }
  /*Conditions servant à placer 'x' si on trouve un des navires et  '.' si on
   * trouve une case avec un espace*/
  if (adv[indiceLigne][indiceColonne] == 'A') {
    adv[indiceLigne][indiceColonne] = 'x';
    return 0;
  }
  if (adv[indiceLigne][indiceColonne] == 'C') {
    adv[indiceLigne][indiceColonne] = 'x';
    return 1;
  }
  if (adv[indiceLigne][indiceColonne] == 'S') {
    adv[indiceLigne][indiceColonne] = 'x';
    return 2;
  }
  if (adv[indiceLigne][indiceColonne] == 'M') {
    adv[indiceLigne][indiceColonne] = 'x';
    return 3;
  }
  if (adv[indiceLigne][indiceColonne] == 'T') {
    adv[indiceLigne][indiceColonne] = 'x';
    return 4;
  }
  if (adv[indiceLigne][indiceColonne] == ' ') {
    adv[indiceLigne][indiceColonne] = '.';
    return -1;
  }
  if (!(t[0] == tabLettres[indice1])) {
    return -3;
  }
  return -3;
}

char *navireDeux(int i) {

  if (i == 0) {
    return "Porte-Avion\n";
  }
  if (i == 1) {
    return "Croiseur\n";
  }
  if (i == 2) {
    return "Sous-Marin\n";
  }
  if (i == 3) {
    return "Mous-Sarin \n";
  }
  if (i == 4) {
    return "Torpilleur \n";
  }
  return 0;
}

/*Fin du code de la partie 2*/
/*--------------------------------------------------------------------------------*/

/*Code partie 1*/
/*--------------------------------------------------------------------------------*/
int coupReussi1(int x) {
  if (x == 0 || x == 1 || x == 2 || x == 3 || x == 4) {
    return 1;
  } else {
    return 0;
  }
}

/* Fonction créée permettant de déterminer si le coup effectué par le joueur est
hors-plateau, ou bien alors si le caractère rentré est inconnu */

int mauvaisCoup(int x) {
  if (x == -2 || x == -3) {
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, char const *argv[]) {
  /* Initialisation des tableaux (plateaux des 2 joueurs) */

  char t1[10][10];
  char t2[10][10];

  /* Initialisation des variables représentant les 2 joueurs */

  int j1;
  int j2;

  /* Initialisation des compteurs comptant les navires détruits et coulés par
   * chaque joueur*/

  int cptNavDetruit_j1 = 0;
  int cptNavDetruit_j2 = 0;

  /* Initialisation des variables s'incrémentant dans le code à chaque fois que
  le navire portant le nom de la variable est touché par le Joueur 1 */

  int porte_avion = 0;
  int croiseur = 0;
  int sous_marin = 0;
  int mous_sarin = 0;
  int torpilleur = 0;

  /* Initialisation des variables s'incrémentant dans le code à chaque fois que
  le navire portant le nom de la variable est touché par le Joueur 2 */

  int porte_avionj2 = 0;
  int croiseurj2 = 0;
  int sous_marinj2 = 0;
  int mous_sarinj2 = 0;
  int torpilleurj2 = 0;

  /* Initialisation du plateau du Joueur 1 à l'aide de la fonction
   * initPlateauDeux */

  printf("Le joueur 1 joue\n");
  initPlateauDeux(t1);

  /* Initialisation du plateau du Joueur 2 à l'aide de la fonction
   * initPlateauDeux */

  printf("Le joueur 2 joue\n");
  initPlateauDeux(t2);

  /* Affichage des deux plateaux à l'aide de la fonction afficheDuoDeux */

  afficheDuoDeux(t1, t2);

  /* Boucle principale: Tant que l'un deux des deux compteurs n'atteint pas 5 on
   * continue (nombre de navires à détruire pour gagner) */

  while (cptNavDetruit_j1 != 5 && cptNavDetruit_j2 != 5) {

    /* TOUR DU JOUEUR 1 */

    /* Le joueur 1 joue sur le plateau du Joueur 2 */

    printf("Le joueur 1 joue.\n");
    j1 = jouerJoueurDeux(t2);

    /* Si le coup est à l'eau */

    if (j1 == -1) {
      printf("A l'eau\n");
      afficheDuoDeux(t1, t2);

      /* Sinon, si le coup est hors-plateau, ou se base sur un caractère inconnu
       */

    } else if (mauvaisCoup(j1)) {

      /* Tant que le Joueur 1 fait un mauvais coup, il rejoue */

      while (mauvaisCoup(j1)) {
        printf("Mauvais coup, rejouez\n");
        afficheDuoDeux(t1, t2);
        printf("Le joueur 1 joue.\n");
        j1 = jouerJoueurDeux(t2);
      }
    }

    /*Si le Joueur 1 fait un bon coup et touche un navire adverse */

    while (coupReussi1(j1) == 1) {
      printf("Touché\n");

      /* A partir d'ici : Si le joueur touche le navire on incrémente son
       compteur, sinon si on a déjà atteint la longueur du navire on en rajoute
       1 pour qu'il ne s'affiche plus */

      if (j1 == 0) {
        porte_avion++;
      } else if (porte_avion == 5) {
        porte_avion++;
      }

      if (j1 == 1) {
        croiseur++;
      } else if (croiseur == 4) {
        croiseur++;
      }

      if (j1 == 2) {
        sous_marin++;
      } else if (sous_marin == 3) {
        sous_marin++;
      }

      if (j1 == 3) {
        mous_sarin++;
      } else if (mous_sarin == 3) {
        mous_sarin++;
      }

      if (j1 == 4) {
        torpilleur++;
      } else if (torpilleur == 2) {
        torpilleur++;
      }

      /* A partir d'ici : Si le joueur a touché le nombre de cases
       correspondantes à la longueur du navire, on affiche le navire coulé et on
       incrémente le compteur de navires détruits par le joueur 1 */

      if (porte_avion == 5) {
        printf("Tu as coulé le %s\n", navireDeux(0));
        cptNavDetruit_j1++;
      }

      if (croiseur == 4) {
        printf("Tu as coulé %s\n", navireDeux(1));
        cptNavDetruit_j1++;
      }
      if (sous_marin == 3) {
        printf("Tu as coulé %s\n", navireDeux(2));
        cptNavDetruit_j1++;
      }
      if (mous_sarin == 3) {
        printf("Tu as coulé %s\n", navireDeux(3));
        cptNavDetruit_j1++;
      }
      if (torpilleur == 2) {
        printf("Tu as coulé %s\n", navireDeux(4));
        cptNavDetruit_j1++;
      }

      /* Affichage des 2 plateaux après les tests à l'aide de la fonction
       * afficheDuoDeux */

      afficheDuoDeux(t1, t2);

      /* Si le Joueur 1 a détruit tous les navires le jeu se termine, et le
       * Joueur 1 est le vainqueur */

      if (cptNavDetruit_j1 == 5) {
        printf("Le joueur 1 a gagné\n");
        return 0;
      }

      /* Si le Joueur 1 n'a pas gagné après avoir touché un navire, il rejoue */

      printf("Le joueur 1 joue\n");
      j1 = jouerJoueurDeux(t2);

      /* Si le coup est à l'eau le Joueur 1 ne joue plus, la condition ne sera
       * pas vérifiée et on passera ainsi le tour au joueur 2 */

      if (j1 == -1) {
        printf("A l'eau\n");
        afficheDuoDeux(t1, t2);
      }

      /* Boucle mauvaisCoup, dans la boucle coupReussi au cas où le joueur aprés
      avoir touché un navire il rentre un caractère inconnu ou un coup hors
      plateau */

      if (mauvaisCoup(j1) == 1) {
        while (mauvaisCoup(j1) == 1) {
          printf("Mauvais coup, rejouez\n");
          afficheDuoDeux(t1, t2);
          printf("Le jouer 1 joue.\n");
          j1 = jouerJoueurDeux(t2);
        }
      }
    }

    /* Fin de la boucle CoupReussi */

    /* TOUR DU JOUEUR 2 */

    printf("Le joueur 2 joue.\n");
    j2 = jouerJoueurDeux(t1);
    if (j2 == -1) {
      printf("A l'eau\n");
      afficheDuoDeux(t1, t2);
    } else if (mauvaisCoup(j2)) {
      while (mauvaisCoup(j2)) {
        printf("Mauvais coup, rejouez\n");
        afficheDuoDeux(t1, t2);
        printf("Le joueur 2 joue.\n");
        j2 = jouerJoueurDeux(t1);
      }
    }

    /*Si le Joueur 2 fait un bon coup et touche un navire adverse */

    while (coupReussi1(j2) == 1) {

      printf("Touché\n");

      /* A partir d'ici : Si le Joueur 2 touche le navire adverse on incrémente
son compteur, sinon si on a déjà atteint la longueur du navire on en rajoute 1
pour qu'il ne s'affiche plus */

      if (j2 == 0) {
        porte_avionj2++;
      } else if (porte_avionj2 == 5) {
        porte_avionj2++;
      }
      if (j2 == 1) {
        croiseurj2++;
      } else if (croiseurj2 == 4) {
        croiseurj2++;
      }
      if (j2 == 2) {
        sous_marinj2++;
      } else if (sous_marinj2 == 3) {
        sous_marinj2++;
      }
      if (j2 == 3) {
        mous_sarinj2++;
      } else if (mous_sarinj2 == 3) {
        mous_sarinj2++;
      }
      if (j2 == 4) {
        torpilleurj2++;
      } else if (torpilleurj2 == 2) {
        torpilleurj2++;
      }

      if (porte_avionj2 == 5) {
        printf("Tu as coulé %s\n", navireDeux(0));
        cptNavDetruit_j2++;
      }
      if (croiseurj2 == 4) {
        printf("Tu as coulé %s\n", navireDeux(1));
        cptNavDetruit_j2++;
      }
      if (sous_marinj2 == 3) {
        printf("Tu as coulé %s\n", navireDeux(2));
        cptNavDetruit_j2++;
      }
      if (mous_sarinj2 == 3) {
        printf("Tu as coulé %s\n", navireDeux(3));
        cptNavDetruit_j2++;
      }
      if (torpilleurj2 == 2) {
        printf("Tu as coulé %s\n", navireDeux(4));
        cptNavDetruit_j2++;
      }

      /* Affichage des 2 plateaux après les tests à l'aide de la fonction
       * afficheDuoDeux */

      afficheDuoDeux(t1, t2);

      /* Si le Joueur 2 a détruit tous les navires le jeu se termine, et le
       * Joueur 2 est le vainqueur */

      if (cptNavDetruit_j2 == 5) {
        printf("Le joueur 2 a gagné\n");
        return 0;
      }

      /* Si le Joueur 2 n'a pas gagné après avoir touché un navire, il rejoue */

      printf("Le joueur 2 joue\n");
      j2 = jouerJoueurDeux(t1);

      if (mauvaisCoup(j2) == 1) {

        /* Boucle mauvaisCoup, dans la boucle coupReussi au cas où le joueur
aprés avoir touché un navire il rentre un caractère inconnu ou un coup hors
plateau */

        while (mauvaisCoup(j2) == 1) {
          printf("Mauvais coup, rejouez\n");
          afficheDuoDeux(t1, t2);
          printf("Le joueur 2 joue.\n");
          j2 = jouerJoueurDeux(t1);
        }
      }

      /* Si le coup est à l'eau le Joueur 1 ne joue plus, la condition ne sera
       * pas vérifiée et on passera ainsi le tour au joueur 2 */

      if (j2 == -1) {
        printf("à l'eau\n");
        afficheDuoDeux(t1, t2);
      }
    }
  }

  return 0;
}
