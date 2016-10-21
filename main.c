#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define XM 24
#define YM 18
#define J1 0
#define J2 1
#define IAVSJ 2

void printMap(int map[XM][YM][3], int joueur){
    int i, j;
    printf("######################\n");
    printf("#  Carte du joueur %d #\n", joueur+1);
    printf("######################\n");
    for(i=0; i<XM; i++)
    {
        for(j=0; j<YM; j++)
        {
            printf("%2d", map[i][j][joueur]);
        }
        printf("\n");
    }
}
void initMap(int map[XM][YM][3]){
    int i, j;
    printf("Initialisation des cartes des 2 joueurs.\n");
    for(i=0; i<XM; i++)
    {
        for(j=0; j<YM; j++)
        {
            map[i][j][J1]=0;
            map[i][j][J2]=0;
            map[i][j][IAVSJ]=0;
        }
    }
}
void waitFor (unsigned int secs) {
        unsigned int retTime = time(0) + secs;   // Get finishing time.
        while (time(0) < retTime);               // Loop until it arrives.
    }
int doRand(int startVal, int endVal){

        waitFor(0.05);
        srand(time(NULL)*rand());
        if(startVal == 0 && endVal == 1){
            return rand() % 2;
        }else{
            return (rand() % ((endVal + startVal -1)) + startVal);
        }
    }
void bateau1(int map[XM][YM][3],int joueur){
    int x, y;
    do{
        do
        {
            x=doRand(0,(XM-1));
            y=doRand(0,(YM-1));
        }
        while(map[x][y][joueur]!=0);
        do{
            if (map[x][y][joueur]==0)
            {
                map[x][y][joueur]=1;
            }
            else{}
        }
        while(map[x][y][joueur]!=0 && map[x][y][joueur]!=1);
    }
    while(map[x][y][joueur]!=0 && map[x][y][joueur]!=1);
}
void bateau2(int map[XM][YM][3],int joueur){
    int x, y, rdmPos;

    do
    {
        do
        {
            x=doRand(0,XM-1);

            y=doRand(0,YM-1);
        }
        while(map[x][y][joueur]!=0);

        do
        {
            rdmPos=doRand(1,4);

            if(rdmPos==1 && x+1<=XM-1 && map[x][y][joueur]==0 && map[x+1][y][joueur]==0)
            {
                map[x][y][joueur]=2;
                map[x+1][y][joueur]=2;
            }
            else if(rdmPos==2 && y+1<=(YM-1) && map[x][y][joueur]==0 && map[x][y+1][joueur]==0)
            {
                map[x][y][joueur]=2;
                map[x][y+1][joueur]=2;
            }
            else if(rdmPos==3 && x-2>=0 && map[x][y][joueur]==0 && map[x-1][y][joueur]==0)
            {
                map[x][y][joueur]=2;
                map[x-1][y][joueur]=2;
            }
            else if(rdmPos==4 && y-2>=0 && map[x][y][joueur]==0 && map[x][y-1][joueur]==0)
            {
                map[x][y][joueur]=2;
                map[x][y-1][joueur]=2;
            }
            else{}
        }
        while(map[x][y][joueur]==0 && map[x][y][joueur]!=2);
    }
    while(map[x][y][joueur]!=2);
}
void bateau3(int map[XM][YM][3],int joueur){
    int x,y, rdmPos;

    do
    {
        do
        {
            x=doRand(0,XM-1);
            y=doRand(0,YM-1);
        }
        while(map[x][y][joueur]!=0);

        do
        {
            rdmPos=doRand(1,4);

            if(rdmPos==1 && x+2<=(XM-1) && map[x][y][joueur]==0 && map[x+1][y][joueur]==0 && map[x+2][y][joueur]==0)
            {
                map[x][y][joueur]=3;
                map[x+1][y][joueur]=3;
                map[x+2][y][joueur]=3;
            }
            else if(rdmPos==2 && y+2<=(YM-1) && map[x][y][joueur]==0 && map[x][y+1][joueur]==0 && map[x][y+2][joueur]==0)
            {
                map[x][y][joueur]=3;
                map[x][y+1][joueur]=3;
                map[x][y+2][joueur]=3;
            }
            else if(rdmPos==3 && x-2>=0 && map[x][y][joueur]==0 && map[x-1][y][joueur]==0 && map[x-2][y][joueur]==0)
            {
                map[x][y][joueur]=3;
                map[x-1][y][joueur]=3;
                map[x-2][y][joueur]=3;
            }
            else if(rdmPos==4 && y-2>=0 && map[x][y][joueur]==0 && map[x][y-1][joueur]==0 && map[x][y-2][joueur]==0)
            {
                map[x][y][joueur]=3;
                map[x][y-1][joueur]=3;
                map[x][y-2][joueur]=3;
            }
            else{}
        }
        while( map[x][y][joueur]==0 && map[x][y][joueur]!=3);
    }
    while(map[x][y][joueur]==0 && map[x][y][joueur]!=3);
}
void bateau4(int map[XM][YM][3],int joueur){

    int x,y,rdmPos;

    do
    {
        do
        {
            x=doRand(0,XM-1);

            y=doRand(0,YM-1);
        }
        while(map[x][y][joueur]!=0);

        do
        {
            rdmPos=doRand(1,4);

            if(rdmPos==1 && x+3<=(XM-1) && map[x][y][joueur]==0 && map[x+1][y][joueur]==0 && map[x+2][y][joueur]==0 && map[x+3][y][joueur]==0)
            {
                map[x][y][joueur]=4;
                map[x+1][y][joueur]=4;
                map[x+2][y][joueur]=4;
                map[x+3][y][joueur]=4;
            }
            else if(rdmPos==2 && y+3<=(YM-1) && map[x][y][joueur]==0 && map[x][y+1][joueur]==0 && map[x][y+2][joueur]==0 && map[x][y+3][joueur]==0)
            {
                map[x][y][joueur]=4;
                map[x][y+1][joueur]=4;
                map[x][y+2][joueur]=4;
                map[x][y+3][joueur]=4;
            }
            else if(rdmPos==3 && x-3>=0 && map[x][y][joueur]==0 && map[x-1][y][joueur]==0 && map[x-2][y][joueur]==0 && map[x-3][y][joueur]==0)
            {
                map[x][y][joueur]=4;
                map[x-1][y][joueur]=4;
                map[x-2][y][joueur]=4;
                map[x-3][y][joueur]=4;
            }
            else if(rdmPos==4 && y-3<=0 && map[x][y][joueur]==0 && map[x][y-1][joueur]==0 && map[x][y-2][joueur]==0 && map[x][y-3][joueur]==0)
            {
                map[x][y][joueur]=4;
                map[x][y-1][joueur]=4;
                map[x][y-2][joueur]=4;
                map[x][y-3][joueur]=4;
            }
            else{}
        }
        while(map[x][y][joueur]==0 && map[x][y][joueur]!=4);
    }
    while(map[x][y][joueur]==0 && map[x][y][joueur]!=4);
}
void bateau1Real(int map[XM][YM][3],int joueur){
    int x, y;

    do
    {
        printf("\nChoisisez la position x de votre bateau 1 la position doit etre comprise entre 0 et %d :", XM-1);

        scanf("%d", &x);

        printf("\nChoisisez la position y de votre bateau 1 la position doit etre comprise entre 0 et %d :", YM-1);
        scanf("%d", &y);

    }
    while(map[x][y][joueur]!=0);

    map[x][y][joueur]=1;
}
void bateau2Real(int map[XM][YM][3],int joueur){
    int x, y, rdmPos;

    do
    {
        do
        {
            printf("\nChoisisez la position x de votre bateau 2 la position doit etre comprise entre 0 et %d :", XM-1);
            scanf("%d", &x);
            printf("\nChoisisez la position y de votre bateau 2 la position doit etre comprise entre 0 et %d :", YM-1);
            scanf("%d", &y);
        }
        while(map[x][y][joueur]!=0);
        do
        {
            printf("Choisisez l'orientation de votre bateau : 1 pour vers la droite, 2 pour vers le bas, 3 pour vers la gauche ou 4 pour vers le haut:\n", YM-1);
            scanf("%d", &rdmPos);

            if(rdmPos==1 && x+1<=XM-1 && map[x][y][joueur]==0 && map[x+1][y][joueur]==0)
            {
                map[x][y][joueur]=2;
                map[x+1][y][joueur]=2;
            }
            else if(rdmPos==2 && y+1<=(YM-1) && map[x][y][joueur]==0 && map[x][y+1][joueur]==0)
            {
                map[x][y][joueur]=2;
                map[x][y+1][joueur]=2;
            }
            else if(rdmPos==3 && x-2>=0 && map[x][y][joueur]==0 && map[x-1][y][joueur]==0)
            {
                map[x][y][joueur]=2;
                map[x-1][y][joueur]=2;
            }
            else if(rdmPos==4 && y-2>=0 && map[x][y][joueur]==0 && map[x][y-1][joueur]==0)
            {
                map[x][y][joueur]=2;
                map[x][y-1][joueur]=2;
            }
            else
            {
                printf("1 pour vers la droite, 2 pour vers le bas, 3 pour vers la gauche ou 4 pour vers le haut! peut être qu'un bateau des deja positionne sur cette position, merci de recommencer\n");
            }
        }
        while(map[x][y][joueur]==0 && map[x][y][joueur]!=2);
    }
    while(map[x][y][joueur]==0 && map[x][y][joueur]!=2);

    if (rdmPos==1)
    {
        printf("votre bateau 2 a ete placer en position x:%d y:%d et x:%d y:%d", x, y, x+1, y);
    }
    else if (rdmPos==2)
    {
        printf("votre bateau 2 a ete placer en position x:%d y:%d et x:%d y:%d", x, y, x, y+1);
    }
    else if (rdmPos==3)
    {
        printf("votre bateau 2 a ete placer en position x:%d y:%d et x:%d y:%d", x, y, x-1, y);
    }
    else if (rdmPos==4)
    {
        printf("votre bateau 2 a ete placer en position x:%d y:%d et x:%d y:%d", x, y, x, y-1);
    }
}
void bateau3Real(int map[XM][YM][3],int joueur){
    int x, y, rdmPos;
    do
    {
        do
        {
            printf("\nChoisisez la position x de votre bateau 3 la position doit etre comprise entre 0 et %d :", XM-1);
            scanf("%d", &x);
            printf("\nChoisisez la position y de votre bateau 3 la position doit etre comprise entre 0 et %d :", YM-1);
            scanf("%d", &y);
        }
        while(map[x][y][joueur]!=0);

        do
        {
            printf("\nChoisisez l'orientation de votre bateau : 1 pour vers la droite, 2 pour vers le bas, 3 pour vers la gauche ou 4 pour vers le haut:", YM-1);
            scanf("%d", &rdmPos);

            if(rdmPos==1 && x+2<=(XM-1) && map[x][y][joueur]==0 && map[x+1][y][joueur]==0 && map[x+2][y][joueur]==0)
            {
                map[x][y][joueur]=3;
                map[x+1][y][joueur]=3;
                map[x+2][y][joueur]=3;
            }
            else if(rdmPos==2 && y+2<=(YM-1) && map[x][y][joueur]==0 && map[x][y+1][joueur]==0 && map[x][y+2][joueur]==0)
            {
                map[x][y][joueur]=3;
                map[x][y+1][joueur]=3;
                map[x][y+2][joueur]=3;
            }
            else if(rdmPos==3 && x-2>=0 && map[x][y][joueur]==0 && map[x-1][y][joueur]==0 && map[x-2][y][joueur]==0)
            {
                map[x][y][joueur]=3;
                map[x-1][y][joueur]=3;
                map[x-2][y][joueur]=3;
            }
            else if(rdmPos==4 && y-2>=0 && map[x][y][joueur]==0 && map[x][y-1][joueur]==0 && map[x][y-2][joueur]==0)
            {
                map[x][y][joueur]=3;
                map[x][y-1][joueur]=3;
                map[x][y-2][joueur]=3;
            }
            else
            {
                printf("\n1 pour vers la droite, 2 pour vers le bas, 3 pour vers la gauche ou 4 pour vers le haut! peut être qu'un bateau des deja positionne sur cette position, merci de recommencer");
            }
        }
        while(map[x][y][joueur]==0 && map[x][y][joueur]!=3);
    }
    while(map[x][y][joueur]==0 && map[x][y][joueur]!=3);

    if (rdmPos==1)
    {
        printf("\nvotre bateau 3 a ete placer en position x:%d y:%d, x:%d y:%d et x:%d y:%d", x, y, x+1, y, x+2, y);
    }
    else if (rdmPos==2)
    {
        printf("\nvotre bateau 3 a ete placer en position x:%d y:%d, x:%d y:%d et x:%d y:%d", x, y, x, y+1, x, y+2);
    }
    else if (rdmPos==3)
    {
        printf("\nvotre bateau 3 a ete placer en position x:%d y:%d et x:%d y:%d et x:%d y:%d", x, y, x-1, y, x-2, y);
    }
    else if (rdmPos==4)
    {
        printf("\nvotre bateau 3 a ete placer en position x:%d y:%d et x:%d y:%d et x:%d y:%d", x, y, x, y-1, x, y-2);
    }
}
void bateau4Real(int map[XM][YM][3],int joueur){
    int x, y, rdmPos;
    do
    {
        do
        {
        printf("\nChoisisez la position x de votre bateau 4 la position doit etre comprise entre 0 et %d :", XM-1);
        scanf("%d", &x);
        printf("\nChoisisez la position y de votre bateau 4 la position doit etre comprise entre 0 et %d :", YM-1);
        scanf("%d", &y);
        }
        while(map[x][y][joueur]!=0);

         do
        {
            printf("\nChoisisez l'orientation de votre bateau : 1 pour vers la droite, 2 pour vers le bas, 3 pour vers la gauche ou 4 pour vers le haut:", YM-1);
            scanf("%d", &rdmPos);

            if(rdmPos==1 && x+3<=(XM-1) && map[x][y][joueur]==0 && map[x+1][y][joueur]==0 && map[x+2][y][joueur]==0 && map[x+3][y][joueur]==0)
            {
                map[x][y][joueur]=4;
                map[x+1][y][joueur]=4;
                map[x+2][y][joueur]=4;
                map[x+3][y][joueur]=4;
            }
            else if(rdmPos==2 && y+3<=(YM-1) && map[x][y][joueur]==0 && map[x][y+1][joueur]==0 && map[x][y+2][joueur]==0 && map[x][y+3][joueur]==0)
            {
                map[x][y][joueur]=4;
                map[x][y+1][joueur]=4;
                map[x][y+2][joueur]=4;
                map[x][y+3][joueur]=4;
            }
            else if(rdmPos==3 && x-3>=0 && map[x][y][joueur]==0 && map[x-1][y][joueur]==0 && map[x-2][y][joueur]==0 && map[x-3][y][joueur]==0)
            {
                map[x][y][joueur]=4;
                map[x-1][y][joueur]=4;
                map[x-2][y][joueur]=4;
                map[x-3][y][joueur]=4;
            }
            else if(rdmPos==4 && y-3<=0 && map[x][y][joueur]==0 && map[x][y-1][joueur]==0 && map[x][y-2][joueur]==0 && map[x][y-3][joueur]==0)
            {
                map[x][y][joueur]=4;
                map[x][y-1][joueur]=4;
                map[x][y-2][joueur]=4;
                map[x][y-3][joueur]=4;
            }
            else
            {
                printf("\n1 pour vers la droite, 2 pour vers le bas, 3 pour vers la gauche ou 4 pour vers le haut! peut être qu'un bateau des deja positionne sur cette position, merci de recommencer");
            }
        }
        while(map[x][y][joueur]==0 && map[x][y][joueur]!=4);
    }
    while(map[x][y][joueur]==0 && map[x][y][joueur]!=4);

    if (rdmPos==1)
    {
        printf("\nvotre bateau 4 a ete placer en position x:%d y:%d, x:%d y:%d, x:%d y%d et x:%d y:%d", x, y, x+1, y, x+2, y, x+3, y);
    }
    else if (rdmPos==2)
    {
        printf("\nvotre bateau 4 a ete placer en position x:%d y:%d, x:%d y:%d, x:%d y:%d et x:%d y:%d", x, y, x, y+1, x, y+2, x, y+3);
    }
    else if (rdmPos==3)
    {
        printf("\nvotre bateau 4 a ete placer en position x:%d y:%d et x:%d y:%d, x:%d y:%d et x:%d y:%d", x, y, x-1, y, x-2, y, x-3, y);
    }
    else if (rdmPos==4)
    {
        printf("\nvotre bateau 4 a ete placer en position x:%d y:%d et x:%d y:%d, x:%d y:%d et x:%d y:%d", x, y, x, y-1, x, y-2, x, y-3);
    }
}

void write(int map[XM][YM][3]){
    FILE* ftp = fopen("./test2.txt","w+");
    int i, j;
    printf("######################\n");
    printf("#  Carte du joueur %d #\n", J1+1);
    printf("######################\n");
    for(i=0; i<XM; i++)
    {
        for(j=0; j<YM; j++)
        {
            printf("%2d", map[i][j][J1]);
        }
        printf("\n");
    }
    printf("######################\n");
    printf("#  Carte du joueur %d #\n", J2+1);
    printf("######################\n");
    for(i=0; i<XM; i++)
    {
        for(j=0; j<YM; j++)
        {
            printf("%2d", map[i][j][J2]);
        }
        printf("\n");
    }
    fclose(ftp);
}
void filerRead(){
    FILE* fptr = fopen("./test1.txt","r");
    char c;
    while(1)
    {
        c = fgetc(fptr);
        if ( feof(fptr) )
        {
            break;
        }
        printf ("%c", c);
    }
    fclose(fptr);
}
int main(int argc, char *argv)
{
    int attaquexJ1=0;
    int attaqueyJ1=0;
    int attaquexJ2=0;
    int attaqueyJ2=0;

    int bateauJ1=0; //Vie joueur 1
    int bateauJ2=0; //Vie joueur 2

    int map[XM][YM][3]={0};

    int mode=0;

    printf("#############################################\n");
    printf("#                                           #\n");
    printf("#    Pour le mode IA contre IA   tapper 1   #\n");
    printf("#                                           #\n");
    printf("#                                           #\n");
    printf("#   Pour le mode joueur contre IA tapper 2  #\n");
    printf("#                                           #\n");
    printf("#                                           #\n");
    printf("#        Charger une partie tapper 3        #\n");
    printf("#                                           #\n");
    printf("#############################################\n");
    printf("\n");
    printf("             Choisir le mode:");
    scanf("%d", &mode);

    switch(mode)
    {
        case 1:

    //Initialisation des cartes

    initMap(map);
    printMap(map,J1);
    printMap(map,J2);

    //positionement des bateaux

        //pour joueur 1

    printf("En cour de placement pour le joueur 1\n");

    bateau1(map,J1);
    bateauJ1=bateauJ1+1;

    bateau2(map,J1);
    bateauJ1=bateauJ1+2;

    bateau3(map,J1);
    bateauJ1=bateauJ1+3;
    bateau3(map,J1);
    bateauJ1=bateauJ1+3;

    bateau4(map,J1);
    bateauJ1=bateauJ1+4;
    bateau4(map,J1);
    bateauJ1=bateauJ1+4;

        //pour joueur 2

    printf("En cour de placement pour le joueur 2\n");

    bateau1(map,J2);
    bateauJ2=bateauJ2+1;

    bateau2(map,J2);
    bateauJ2=bateauJ2+2;

    bateau3(map,J2);
    bateauJ2=bateauJ2+3;
    bateau3(map,J2);
    bateauJ2=bateauJ2+3;

    bateau4(map,J2);
    bateauJ2=bateauJ2+4;
    bateau4(map,J2);
    bateauJ2=bateauJ2+4;

                //Carte joueur 1 avec bateaux
    printMap(map,J1);
                 //Carte joueur 2 avec bateaux
    printMap(map,J2);

       // IA Attaque
        while(bateauJ1!=0 && bateauJ2!=0)  //Boucle jusqu'à ce que l'un des 2 joueur n'as plus de bateau en vie
            //Je ne comprend pas pourquoi il faut un "ET" ici... et non un "OU"...
        {
            //Attaque du joueur 2 sur la carte du joueur 1 (c'est la carte map[i][j][1])
            do
            {
                attaquexJ2 = doRand(0,XM+1);
                attaqueyJ2 = doRand(0,YM+1);
            }
            while(map[attaquexJ2][attaqueyJ2][J1]==6 || map[attaquexJ2][attaqueyJ2][J1]==9);  // Boucle pour éviter de tirer plusieur fois au même endroit.

            if(map[attaquexJ2][attaqueyJ2][J1]==1 || map[attaquexJ2][attaqueyJ2][J1]==2 || map[attaquexJ2][attaqueyJ2][J1]==3 || map[attaquexJ2][attaqueyJ2][J1]==4)
            {
                map[attaquexJ2][attaqueyJ2][J1]=9;
                printf("\n");
                printf("attaque du joueur 2 reussi en x:%d y:%d\n", attaquexJ2, attaqueyJ2);
                bateauJ1=bateauJ1-1;
                printf("Nombre de morceau(x) du joueur 1 intact %d\n", bateauJ1);
                printf("Nombre de morceaux(x) du joueur 2 intact %d\n", bateauJ2);

            }
            else if (map[attaquexJ2][attaqueyJ2][J1]==0)
            {
                map[attaquexJ2][attaqueyJ2][J1]=6;
            }
                //Attaque du joueur 1 sur la carte du joueur 2 (c'est la carte map[a][a][0])
            do
            {
                attaquexJ1 = doRand(0,XM+1);
                attaqueyJ1 = doRand(0,YM+1);
            }
            while(map[attaquexJ1][attaqueyJ1][J2]==6 || map[attaquexJ1][attaqueyJ1][J2]==9); // Boucle pour éviter de tirer plusieur fois au même endroit.

            if(map[attaquexJ1][attaqueyJ1][J2]==1 || map[attaquexJ1][attaqueyJ1][J2]==2 || map[attaquexJ1][attaqueyJ1][J2]==3 || map[attaquexJ1][attaqueyJ1][J2]==4)
            {
                map[attaquexJ1][attaqueyJ1][J2]=9;
                printf("\n");
                printf("attaque du joueur 1 reussi en x:%d y:%d\n", attaquexJ1, attaqueyJ1);
                bateauJ2=bateauJ2-1;
                printf("Nombre de morceau(x) du joueur 1 intact %d\n", bateauJ1);
                printf("Nombre de morceaux(x) du joueur 2 intact %d\n", bateauJ2);
            }
            else if (map[attaquexJ1][attaqueyJ1][J2]==0)
            {
                map[attaquexJ1][attaqueyJ1][J2]=6;
            }
        }
        write(map);
        printMap(map,J1);
        printMap(map,J2);

        printf("###############################################\n");
        printf("#                                             #\n");
        printf("# Nombre de morceau(x) du joueur 1 intact %d   #\n", bateauJ1);
        printf("# Nombre de morceaux(x) du joueur 2 intact %d  #\n", bateauJ2);
        printf("#                                             #\n");
        printf("###############################################\n");

        if(bateauJ1==0)
        {
            printf("###############################################\n");
            printf("#                                             #\n");
            printf("#            Le joueur 2 a gagner!!           #\n");
            printf("#                                             #\n");
            printf("###############################################\n");
        }
        else if(bateauJ2==0)
        {
            printf("###############################################\n");
            printf("#                                             #\n");
            printf("#            Le joueur 1 a gagner!!           #\n");
            printf("#                                             #\n");
            printf("###############################################\n");
        }
        break;

        case 2:
            printf("Bienvenue dans le mode Joueur contre IA\n");

            initMap(map);

    //positionement des bateaux

        //pour joueur 1
    printMap(map,J1);
    printMap(map,J2);

    bateau1Real(map, J1);
    bateauJ1=bateauJ1+1;

    bateau2Real(map, J1);
    bateauJ1=bateauJ1+2;

    bateau3Real(map, J1);
    bateauJ1=bateauJ1+3;
    bateau3Real(map, J1);
    bateauJ1=bateauJ1+3;

    bateau4Real(map, J1);
    bateauJ1=bateauJ1+4;
    bateau4Real(map, J1);
    bateauJ1=bateauJ1+4;

        //pour joueur 2 IA
    bateau1(map,J2);
    bateauJ2=bateauJ2+1;

    bateau2(map,J2);
    bateauJ2=bateauJ2+2;

    bateau3(map,J2);
    bateauJ2=bateauJ2+3;
    bateau3(map,J2);
    bateauJ2=bateauJ2+3;

    bateau4(map,J2);
    bateauJ2=bateauJ2+4;
    bateau4(map,J2);
    bateauJ2=bateauJ2+4;

                //Carte joueur 1 avec bateaux
    printMap(map,J1);

                 //Carte joueur 2 avec bateaux
    printMap(map,J2);

       // IA Attaque
        while(bateauJ1!=0 && bateauJ2!=0)  //Boucle jusqu'à ce que l'un des 2 joueur n'as plus de bateau en vie
        {   //filerWrite();

            //Attaque du joueur 2 (L'IA) sur la carte du joueur 1 (c'est la carte map[i][j][1])
            do
            {
                attaquexJ2 = doRand(0,XM+1);
                attaqueyJ2 = doRand(0,YM+1);
            }
            while(map[attaquexJ2][attaqueyJ2][J1]==6 || map[attaquexJ2][attaqueyJ2][J1]==9);  // Boucle pour éviter de tirer plusieur fois au même endroit.

            if(map[attaquexJ2][attaqueyJ2][J1]==1 || map[attaquexJ2][attaqueyJ2][J1]==2 || map[attaquexJ2][attaqueyJ2][J1]==3 || map[attaquexJ2][attaqueyJ2][J1]==4)
            {
                map[attaquexJ2][attaqueyJ2][J1]=9;
                printf("\n");
                printf("attaque du joueur 2 reussi en x:%d y:%d\n", attaquexJ2, attaqueyJ2);
                bateauJ1=bateauJ1-1;
                printf("Nombre de morceau(x) du joueur 1 intact %d\n", bateauJ1);
                printf("Nombre de morceaux(x) du joueur 2 intact %d\n", bateauJ2);
            }
            else if (map[attaquexJ2][attaqueyJ2][J1]==0)
            {
                map[attaquexJ2][attaqueyJ2][J1]=6;
            }
                //Attaque du joueur 1 sur la carte du joueur 2 (L'IA)(c'est la carte map[a][a][0])
            do
            {
                printf("Carte de votre ennemi:\n");
                printMap(map,IAVSJ);

                printf("Choisisez la position x de votre attaque la position doit etre comprise entre 0 et %d :\n", XM-1);
                scanf("%d", &attaquexJ1);
                printf("Choisisez la position y de votre attaque la position doit etre comprise entre 0 et %d :\n", YM-1);
                scanf("%d", &attaqueyJ1);

                if(map[attaquexJ1][attaqueyJ1][IAVSJ]==6)
                {
                    printf("Vous avez deja attaque ici! Vous aviez touche, vous pouvez recommencer votre attaque");
                }
                else if(map[attaquexJ1][attaqueyJ1][IAVSJ]==9)
                {
                    printf("Vous avez deja attaque ici! Vous aviez loupe, vous pouvez recommencer votre attaque");
                }
            }
            while(map[attaquexJ1][attaqueyJ1][IAVSJ]==6 || map[attaquexJ1][attaqueyJ1][IAVSJ]==9); // Boucle pour éviter de tirer plusieur fois au même endroit.

            if(map[attaquexJ1][attaqueyJ1][J2]==1 || map[attaquexJ1][attaqueyJ1][J2]==2 || map[attaquexJ1][attaqueyJ1][J2]==3 || map[attaquexJ1][attaqueyJ1][J2]==4)
            {
                map[attaquexJ1][attaqueyJ1][IAVSJ]=9;
                printf("\n");
                printf("attaque du joueur 1 reussi en x:%d y:%d\n", attaquexJ1, attaqueyJ1);
                bateauJ2=bateauJ2-1;
                printf("Nombre de morceau(x) du joueur 1 intact %d\n", bateauJ1);
                printf("Nombre de morceaux(x) du joueur 2 intact %d\n", bateauJ2);
            }
            else if (map[attaquexJ1][attaqueyJ1][J2]==0)
            {
                map[attaquexJ1][attaqueyJ1][IAVSJ]=6;
            }
        }

        printMap(map,J1);
        printMap(map,IAVSJ);

        printf("###############################################\n");
        printf("#                                             #\n");
        printf("# Nombre de morceau(x) du joueur 1 intact %d   #\n", bateauJ1);
        printf("# Nombre de morceaux(x) du joueur 2 intact %d  #\n", bateauJ2);
        printf("#                                             #\n");
        printf("###############################################\n");
        if(bateauJ1==0)
        {
            printf("###############################################\n");
            printf("#                                             #\n");
            printf("#            Le joueur 2 a gagner!!           #\n");
            printf("#                                             #\n");
            printf("###############################################\n");
        }
        else if(bateauJ2==0)
        {
            printf("###############################################\n");
            printf("#                                             #\n");
            printf("#            Le joueur 1 a gagner!!           #\n");
            printf("#                                             #\n");
            printf("###############################################\n");
        }
        break;
    }
    return 0;
}
