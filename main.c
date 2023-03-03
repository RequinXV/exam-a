#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ecrire la fonction generer(), elle prend en paramètre la grille et renvoie le nombre d'éléments non nuls

#define L 9 
#define HORIZ 0
#define VERT 1

void generer(int magrille[L][L]){
    int i,j;
    int countnul;

    // for ( grilledid=magrille ; grilledid<magrille+L ; grilledid ++) *grilledid = 9 ;

    for(i=0;i<9;++i){
        for(j=0;j<9;++j){
            if (magrille[i][j]!=0){ 
                countnul++;  
            }
        }
    }
    
    for (i = 0; i<9; ++i){
        for (j = 0; j<0; ++j) printf("%d ", magrille[i][j]); printf("\n");
    }
}   


// Ce lien vous sera utile : https://www.geeksforgeeks.org/pass-2d-array-parameter-c/

/*Écrire une fonction saisir() qui demande à l’utilisateur de saisir au clavier les indices i et j et la valeur v à placer à l’emplacement (i,j).
La fonction doit vérifier la validité des indices et de la valeur.
Si la case n’est pas occupée, la valeur doit être placée dans la grille. remplissage est alors incrémentée*/
int i,j,v;
void saisir(int magrille[L][L]){
    printf("veulliez rentrer l'abscisse de la case souaihté'");
    scanf("%d", &i );
    printf("veulliez rentrer l'ordonnée de la case souaihté'");
    scanf("%d", &j );
    printf("veulliez entré la valeur souahité'");
    scanf("%d", &v );
    printf("Vous allez rentrez la valeur %d, aux coordonnées %d, %d.", v,i,j);

    if (magrille[i][j]==0){
        magrille[i][j]==v;
    }
}

/*
Écrire la fonction verifierLigneColonne() qui prend en paramètre un numéro et un sens (HORIZ ou VERT)
qui vérifie que la ligne ou la colonne (suivant les cas) numéro est bien remplie.
On pourra utiliser un tableau intermédiaire pour vérifier cela. La fonction retournera 1 si tout s’est bien passé, 0 sinon.
 Les constantes HORIZ de valeur 0 et VERT de valeur 1 sont à définir.
*/


int verifierLigneColonne(int magrille[L][L],int num){
    int x0, y0;
    for (x0=0; x0 <9; ++x0){
        if (magrille[VERT][x0] == num){
            return 0;
        }   
        else {
            return 1;
        }         
    }
    for (y0=0; y0 <9; ++y0){
        if (magrille[y0][HORIZ] == num){
            return 0;
        }
        else {
            return 1;
        } 
    }
}



/*
Écrire la fonction verifierRegion() qui prend en paramètre deux indices k et l qui correspondent à la région (k,l)
et qui renvoie 1 si la région est correctement remplie, 0 sinon.
*/

int verifierRegion(int magrille[L][L], int x, int y){
    int x0, y0, i; j;
    x0 = (x/3) * 3;
    y0 = (y/3) * 3;
    
    for (i=0; i<3; ++i){
        for (j=0; j<3; ++j){
            if (magrille[y0+i][x0+j] == i || j){
                return 0;
            }
        }
    }
    return 1;
}


//Écrire la fonction verifierGrille() qui renvoie 1 si la grille est correctement remplie et 0 sinon
int verifierGrille(int magrille[L][L]){
    int region = 0;
    int l = 0;
    int c = 0;
    for (int i=0; i<3; ++i){
        for (j=0; j<3; ++j){
            if (verifierRegion(magrille, i,j)){
                region = 1;
            }
        }
    }
    for(int i = 0; i < 9; ++i) {
        if(verifierLigneColonne(magrille, i) == 0) {
            l = 1;
        }
        if(verifierLigneColonne(magrille, i) == 0) {
            c = 1;
        }
    }
    if (region && l && c == 1) {
        return 1;
    } 
    else {
        return 0;
    }

}


//Écrire le programme principal, en supposant que la seule condition d’arrêt est la réussite du sudoku (ce test ne devra être fait que si nécessaire)


int main(){
    // Ne pas toucher le code entre les commentaires
    srand( time( NULL ) );


    int i, j, k;
    int solution[9][9];
    printf("SOLUTION");  
    printf("\n");  
    printf("---------------------------------");  
    printf("\n");  
    for(j=0;j<9; ++j) 
    {
        for(i=0; i<9; ++i)
            solution[j][i] = (i + j*3 +j /3) %9 +1 ; 
    }
    
        for(i=0;i<9; ++i) 
    {
    for(j=0; j<9; ++j)
        printf("%d ", solution[i][j]);
    printf("\n");
    }

    generer(solution);

    printf("---------------------------------");  
    printf("\n");  
    //toucher le code entre les commentaires 
    
    printf("%d",rand() % 2);
    
    int valid = 1;
        while(valid == 1) {
            saisir(solution);
            generer(solution);
            valid = verifierGrille(solution);
        }

    printf("GG\n");



    //Ne pas toucher au code ci dessous
    system("pause");
    return 0;
}





/*
Pour l'exercice vous aurez besoin de generer des entiers aléatoire : rand() renvoit un entier aléatoire.
il s'utilise : rand() % NOMBREMAX + 1 
Pour un entier aléatoire entre 0 et 1 il faut donc faire rand() %2
voir dans la methode main.
*/
