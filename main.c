#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define YM 18
#define XM 24
#define J1 0
#define J2 1
#define IAVSJ 2

void purge(void){
        int c;
        while( ((c = getchar()) != '\n') && c != EOF)
        {
        }
    }
void printMap(char map[YM][XM][3], int joueur, int mod){
        int i, j;

        if(mod==1)
        {
            if(joueur==0)
            {
                printf("\n######################\n");
                printf("#  Carte du l IA  1  #\n");
                printf("######################\n");
            }
            else if(joueur==1)
            {
                printf("\n######################\n");
                printf("#  Carte du l IA  2  #\n");
                printf("######################\n");
            }
        }
        else
        {
            if(joueur==0)
            {
                printf("\n######################\n");
                printf("#     Votre carte    #\n");
                printf("######################\n");
            }
            else if(joueur==2)
            {
                printf("\n######################\n");
                printf("#   Carte du l IA    #\n");
                printf("######################\n");
            }
        }

        for(i=0; i<YM; i++)
        {
            for(j=0; j<XM; j++)
            {
                printf("%2c", map[i][j][joueur]);
            }
            printf("\n");
        }
    }
void initMap(char map[YM][XM][3]){
        int i, j, k, l;
        int m=48;
        int n=48;

        printf("Initialisation des cartes des 2 joueurs.\n");
        for(i=0; i<YM; i++)
        {
            for(j=0; j<XM; j++)
            {
                for(k=1; k<XM; k++)
                {

                    if(i==0 && j==k)
                    {
                        m++;
                        if(m>57)
                        {
                            m=48;
                        }
                        map[i][j][J1]=m;
                        map[i][j][J2]=m;
                        map[i][j][IAVSJ]=m;
                    }
                }
                for(l=1; l<YM; l++)
                {
                    if(i==l && j==0)
                    {
                        n++;
                        if(n>57)
                        {
                            n=48;
                        }
                        map[i][j][J1]=n;
                        map[i][j][J2]=n;
                        map[i][j][IAVSJ]=n;
                    }
                }
                if(i==0 && j==0)
                {
                    map[i][j][J1]='0';
                    map[i][j][J2]='0';
                    map[i][j][IAVSJ]='0';
                }
                if(i != 0 && j != 0)
                {
                    map[i][j][J1]='o';
                    map[i][j][J2]='o';
                    map[i][j][IAVSJ]='?';
                }
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
void bateauA(char map[YM][XM][3], int joueur, int vie[2][4]){
        int y, x;
        do{
            do
            {
                y=doRand(2,(YM-1));
                x=doRand(2,(XM-1));
            }
            while(map[y][x][joueur]!='o');
            do{
                if (map[y][x][joueur]=='o')
                {
                    map[y][x][joueur]='A';
                }
                else{}
            }
            while(map[y][x][joueur]!='o' && map[y][x][joueur]!='A');
        }
        while(map[y][x][joueur]!='o' && map[y][x][joueur]!='A');
        vie[joueur][0] = vie[joueur][0]+1;
    }
void bateauB(char map[YM][XM][3], int joueur, int vie[2][4]){
        int y, x, rdmPos;

        do
        {
            do
            {
                y=doRand(1,YM-1);
                x=doRand(1,XM-1);
            }
            while(map[y][x][joueur]!='o');

            do
            {
                rdmPos=doRand(1,4);

                if(rdmPos==1 && y+1<=YM-1 && map[y][x][joueur]=='o' && map[y+1][x][joueur]=='o')
                {
                    map[y][x][joueur]='B';
                    map[y+1][x][joueur]='B';
                }
                else if(rdmPos==2 && x+1<=(XM-1) && map[y][x][joueur]=='o' && map[y][x+1][joueur]=='o')
                {
                    map[y][x][joueur]='B';
                    map[y][x+1][joueur]='B';
                }
                else if(rdmPos==3 && y-2>=1 && map[y][x][joueur]=='o' && map[y-1][x][joueur]=='o')
                {
                    map[y][x][joueur]='B';
                    map[y-1][x][joueur]='B';
                }
                else if(rdmPos==4 && x-2>=1 && map[y][x][joueur]=='o' && map[y][x-1][joueur]=='o')
                {
                    map[y][x][joueur]='B';
                    map[y][x-1][joueur]='B';
                }
                else{}
            }
            while(map[y][x][joueur]=='o' && map[y][x][joueur]!='B');
        }
        while(map[y][x][joueur]!='B');
        vie[joueur][1] = vie[joueur][1]+2;
    }
void bateauC(char map[YM][XM][3], int joueur, int vie[2][4]){
        int y,x, rdmPos;

        do
        {
            do
            {
                y=doRand(1,YM-1);
                x=doRand(1,XM-1);
            }
            while(map[y][x][joueur]!='o');

            do
            {
                rdmPos=doRand(1,4);

                if(rdmPos==1 && y+2<=(YM-1) && map[y][x][joueur]=='o' && map[y+1][x][joueur]=='o' && map[y+2][x][joueur]=='o')
                {
                    map[y][x][joueur]='C';
                    map[y+1][x][joueur]='C';
                    map[y+2][x][joueur]='C';
                }
                else if(rdmPos==2 && x+2<=(XM-1) && map[y][x][joueur]=='o' && map[y][x+1][joueur]=='o' && map[y][x+2][joueur]=='o')
                {
                    map[y][x][joueur]='C';
                    map[y][x+1][joueur]='C';
                    map[y][x+2][joueur]='C';
                }
                else if(rdmPos==3 && y-2>=1 && map[y][x][joueur]=='o' && map[y-1][x][joueur]=='o' && map[y-2][x][joueur]=='o')
                {
                    map[y][x][joueur]='C';
                    map[y-1][x][joueur]='C';
                    map[y-2][x][joueur]='C';
                }
                else if(rdmPos==4 && x-2>=1 && map[y][x][joueur]=='o' && map[y][x-1][joueur]=='o' && map[y][x-2][joueur]=='o')
                {
                    map[y][x][joueur]='C';
                    map[y][x-1][joueur]='C';
                    map[y][x-2][joueur]='C';
                }
                else{}
            }
            while( map[y][x][joueur]=='o' && map[y][x][joueur]!='C');
        }
        while(map[y][x][joueur]=='o' && map[y][x][joueur]!='C');
        vie[joueur][2] = vie[joueur][2]+3;
    }
void bateauD(char map[YM][XM][3], int joueur, int vie[2][4]){
        int y,x,rdmPos;

        do
        {
            do
            {
                y=doRand(1,YM-1);
                x=doRand(1,XM-1);
            }
            while(map[y][x][joueur]!='o');

            do
            {
                rdmPos=doRand(1,4);

                if(rdmPos==1 && y+3<=(YM-1) && map[y][x][joueur]=='o' && map[y+1][x][joueur]=='o' && map[y+2][x][joueur]=='o' && map[y+3][x][joueur]=='o')
                {
                    map[y][x][joueur]='D';
                    map[y+1][x][joueur]='D';
                    map[y+2][x][joueur]='D';
                    map[y+3][x][joueur]='D';
                }
                else if(rdmPos==2 && x+3<=(XM-1) && map[y][x][joueur]=='o' && map[y][x+1][joueur]=='o' && map[y][x+2][joueur]=='o' && map[y][x+3][joueur]=='o')
                {
                    map[y][x][joueur]='D';
                    map[y][x+1][joueur]='D';
                    map[y][x+2][joueur]='D';
                    map[y][x+3][joueur]='D';
                }
                else if(rdmPos==3 && y-3>=1 && map[y][x][joueur]=='o' && map[y-1][x][joueur]=='o' && map[y-2][x][joueur]=='o' && map[y-3][x][joueur]=='o')
                {
                    map[y][x][joueur]='D';
                    map[y-1][x][joueur]='D';
                    map[y-2][x][joueur]='D';
                    map[y-3][x][joueur]='D';
                }
                else if(rdmPos==4 && x-3<=1 && map[y][x][joueur]=='o' && map[y][x-1][joueur]=='o' && map[y][x-2][joueur]=='o' && map[y][x-3][joueur]=='o')
                {
                    map[y][x][joueur]='D';
                    map[y][x-1][joueur]='D';
                    map[y][x-2][joueur]='D';
                    map[y][x-3][joueur]='D';
                }
                else{}
            }
            while(map[y][x][joueur]=='o' && map[y][x][joueur]!='D');
        }
        while(map[y][x][joueur]=='o' && map[y][x][joueur]!='D');
        vie[joueur][3] = vie[joueur][3]+4;
    }
void bateauAReal(char map[YM][XM][3],int joueur, int vie[2][4]){
        int y, x, testScanf;

        do
        {
            do
            {
                printf("\n Choisisez la position vertical(y) de votre bateau 1 la position doit etre un chiffre allant de 1 a %d :", YM-1);
                fflush(stdout);
                testScanf = scanf("%d", &y);
                if(testScanf != 1 || y<1 || y>YM-1)
                {
                    printf("\n Il faut un chiffre allant de 1 a %d \n", YM-1);
                }
                purge();
            }
            while(testScanf != 1 || y<1 || y>YM-1);

            do
            {
                printf("\n Choisisez la position horizontal(x) de votre bateau 1 la position doit etre un chiffre allant de 1 a %d :", XM-1);
                fflush(stdout);
                testScanf = scanf("%d", &x);
                if(testScanf != 1 || x<1 || x>XM-1)
                {
                    printf("\n Il faut un chiffre allant de 1 a %d \n", XM-1);
                }
                purge();
            }
            while(testScanf != 1 || x<1 || x>XM-1);
        }
        while(map[y][x][joueur]!='o');

        map[y][x][joueur]='A';
        vie[joueur][0] = vie[joueur][0]+1;
    }
void bateauBReal(char map[YM][XM][3],int joueur, int vie[2][4]){
        int y, x, orientation, testScanf;

        do
        {
            do
            {
                do
                {
                    printf("\n Choisisez la position vertical(y) de votre bateau 2 la position doit etre un chiffre allant de 1 a %d :", YM-1);
                    fflush(stdout);
                    testScanf = scanf("%d", &y);
                    if(testScanf != 1 || y<1 || y>YM-1)
                    {
                        printf("\n Il faut un chiffre allant de 1 a %d \n", YM-1);
                    }
                    purge();
                }
                while(testScanf != 1 || y<1 || y>YM-1);
                do
                {
                    printf("\n Choisisez la position horizontal(x) de votre bateau 2 la position doit etre un chiffre allant de 1 a %d :", XM-1);
                    fflush(stdout);
                    testScanf = scanf("%d", &x);
                    if(testScanf != 1 || x<1 || x>XM-1)
                    {
                        printf("\n Il faut un chiffre allant de 1 a %d \n", XM-1);
                    }
                    purge();
                }
                while(testScanf != 1 || x<1 || x>XM-1);
                if(map[y][x][joueur]!='o')
                {
                    printf("\n Il y a deja un bateau ici, merci de recommencer le placement de ce bateau \n");
                }
                else if(map[y+1][x][joueur]!='o' && map[y-1][x][joueur]!='o' && map[y][x+1][joueur]!='o' && map[y][x-1][joueur]!='o')
                {
                    printf("\n Vous ne pourrez pas placer les autre morceaux de votre bateau, merci de choisir un autre point de depart \n");
                }
            }while(map[y][x][joueur]!='o' || (map[y+1][x][joueur]!='o' && map[y-1][x][joueur]!='o' && map[y][x+1][joueur]!='o' && map[y][x-1][joueur]!='o'));


            do
            {
                do
                {
                    printf("\n Choisisez l'orientation de votre bateau \n");
                    printf("1 pour vers le bas, 2 pour vers la droite, 3 pour vers le haut ou 4 pour vers la gauche : ", XM-1);
                    fflush(stdout);
                    scanf("%d", &orientation);
                    if(testScanf != 1  || orientation<1 || orientation>4)
                    {
                        printf("\n Il faut un chiffre allant de 1 a 4 \n");
                    }
                    purge();
                }
                while(testScanf != 1 || orientation<1 || orientation>4);

                if(orientation==1 && y+1<=YM-1 && map[y][x][joueur]=='o' && map[y+1][x][joueur]=='o')
                {
                    map[y][x][joueur]='B';
                    map[y+1][x][joueur]='B';
                    printf("\n votre bateau 2 a ete placer en position y:%d x:%d et y:%d x:%d \n", y, x, y+1, x);
                }
                else if(orientation==2 && x+1<=(XM-1) && map[y][x][joueur]=='o' && map[y][x+1][joueur]=='o')
                {
                    map[y][x][joueur]='B';
                    map[y][x+1][joueur]='B';
                    printf("\n votre bateau 2 a ete placer en position y:%d x:%d et y:%d x:%d \n", y, x, y, x+1);
                }
                else if(orientation==3 && y-1>=1 && map[y][x][joueur]=='o' && map[y-1][x][joueur]=='o')
                {
                    map[y][x][joueur]='B';
                    map[y-1][x][joueur]='B';
                    printf("\n votre bateau 2 a ete placer en position y:%d x:%d et y:%d x:%d \n", y, x, y-1, x);
                }
                else if(orientation==4 && x-1>=1 && map[y][x][joueur]=='o' && map[y][x-1][joueur]=='o')
                {
                    map[y][x][joueur]='B';
                    map[y][x-1][joueur]='B';
                    printf("\n votre bateau 2 a ete placer en position y:%d x:%d et y:%d x:%d \n", y, x, y, x-1);
                }
                else
                {
                    printf("\n Erreur! \n");
                    printf("Bateau sortie de la carte ou impossibilite de superposer les bateau \n");
                    printf("merci de recommencer \n");
                }
            }
            while(map[y][x][joueur]=='o' || map[y][x][joueur]!='B');
        }
        while(map[y][x][joueur]=='o' || map[y][x][joueur]!='B');

        vie[joueur][1] = vie[joueur][1]+2;
    }
void bateauCReal(char map[YM][XM][3],int joueur, int vie[2][4]){
        int y, x, orientation, testScanf;
        do
        {
            do
            {
                do
                {
                    printf("\n Choisisez la position vertical(y) de votre bateau 3 la position doit etre un chiffre allant de 1 a %d :", YM-1);
                    fflush(stdout);
                    testScanf = scanf("%d", &y);
                    if(testScanf != 1 || y<1 || y>YM-1)
                    {
                        printf("\n Il faut un chiffre allant de 1 a %d \n", YM-1);
                    }
                    purge();
                }
                while(testScanf != 1 || y<1 || y>YM-1);
                do
                {
                    printf("\n Choisisez la position horizontal(x) de votre bateau 3 la position doit etre un chiffre allant de 1 a %d :", XM-1);
                    fflush(stdout);
                    testScanf = scanf("%d", &x);
                    if(testScanf != 1 || x<1 || x>XM-1)
                    {
                        printf("\n Il faut un chiffre allant de 1 a %d \n", XM-1);
                    }
                    purge();
                }
                while(testScanf != 1 || x<1 || x>XM-1);
                if(map[y][x][joueur]!='o')
                {
                    printf("\n Il y a deja un bateau ici, merci de recommencer le placement de ce bateau \n");
                }
                else if((map[y+1][x][joueur]!='o' || map[y+2][x][joueur]!='o')
                         && (map[y-1][x][joueur]!='o' || map[y-2][x][joueur]!='o')
                         && (map[y][x+1][joueur]!='o' || map[y][x+2][joueur]!='o')
                         && (map[y][x-1][joueur]!='o' || map[y][x-2][joueur]!='o'))
                {
                    printf("\n Vous ne pourrez pas placer les autre morceaux de votre bateau, merci de choisir un autre point de depart \n");
                }
            }while(map[y][x][joueur]!='o' || ((map[y+1][x][joueur]!='o' || map[y+2][x][joueur]!='o')
                                               && (map[y-1][x][joueur]!='o' || map[y-2][x][joueur]!='o')
                                               && (map[y][x+1][joueur]!='o' || map[y][x+2][joueur]!='o')
                                               && (map[y][x-1][joueur]!='o' || map[y][x-2][joueur]!='o')));


            do
            {
                do
                {
                    printf("\n Choisisez l'orientation de votre bateau \n ");
                    printf("1 pour vers le bas, 2 pour vers la droite, 3 pour vers le haut ou 4 pour vers la gauche : ", XM-1);
                    fflush(stdout);
                    testScanf = scanf("%d", &orientation);
                    if(testScanf != 1 || orientation<1 || orientation>4)
                    {
                        printf("\n Il faut un chiffre allant de 1 a 4 \n", XM-1);
                    }
                    purge();
                }
                while(testScanf != 1 || orientation<1 || orientation>4);

                if(orientation==1 && y+2<=(YM-1) && map[y][x][joueur]=='o' && map[y+1][x][joueur]=='o' && map[y+2][x][joueur]=='o')
                {
                    map[y][x][joueur]='C';
                    map[y+1][x][joueur]='C';
                    map[y+2][x][joueur]='C';
                    printf("\n votre bateau 3 a ete placer en position y:%d x:%d, y:%d x:%d et y:%d x:%d \n", y, x, y+1, x, y+2, x);
                }
                else if(orientation==2 && x+2<=(XM-1) && map[y][x][joueur]=='o' && map[y][x+1][joueur]=='o' && map[y][x+2][joueur]=='o')
                {
                    map[y][x][joueur]='C';
                    map[y][x+1][joueur]='C';
                    map[y][x+2][joueur]='C';
                    printf("\n votre bateau 3 a ete placer en position y:%d x:%d, y:%d x:%d et y:%d x:%d \n", y, x, y, x+1, y, x+2);
                }
                else if(orientation==3 && y-2>=1 && map[y][x][joueur]=='o' && map[y-1][x][joueur]=='o' && map[y-2][x][joueur]=='o')
                {
                    map[y][x][joueur]='C';
                    map[y-1][x][joueur]='C';
                    map[y-2][x][joueur]='C';
                    printf("\n votre bateau 3 a ete placer en position y:%d x:%d et y:%d x:%d et y:%d x:%d \n", y, x, y-1, x, y-2, x);
                }
                else if(orientation==4 && x-2>=1 && map[y][x][joueur]=='o' && map[y][x-1][joueur]=='o' && map[y][x-2][joueur]=='o')
                {
                    map[y][x][joueur]='C';
                    map[y][x-1][joueur]='C';
                    map[y][x-2][joueur]='C';
                    printf("\n votre bateau 3 a ete placer en position y:%d x:%d et y:%d x:%d et y:%d x:%d \n", y, x, y, x-1, y, x-2);
                }
                else
                {
                    printf("\n Erreur! \n");
                    printf("Bateau sortie de la carte ou impossibilite de superposer les bateau \n");
                    printf("merci de recommencer \n");
                }
            }
            while(map[y][x][joueur]=='o' && map[y][x][joueur]!='C');
        }
        while(map[y][x][joueur]=='o' && map[y][x][joueur]!='C');

        vie[joueur][2] = vie[joueur][2]+3;
    }
void bateauDReal(char map[YM][XM][3],int joueur, int vie[2][4]){
        int y, x, orientation, testScanf;
        do
        {
            do
            {
                do
                {
                    printf("\n Choisisez la position vertical(y) de votre bateau 4 la position doit etre un chiffre allant de 1 a %d :", YM-1);
                    fflush(stdout);
                    testScanf = scanf("%d", &y);
                    if(testScanf != 1 || y<1 || y>YM-1)
                    {
                        printf("\n Il faut un chiffre allant de 1 a %d \n", YM-1);
                    }
                    purge();
                }
                while(testScanf != 1 || y<1 || y>YM-1);
                do
                {
                    printf("\nChoisisez la position horizontal(x) de votre bateau 4 la position doit etre un chiffre allant de 1 a %d :", XM-1);
                    fflush(stdout);
                    testScanf = scanf("%d", &x);
                    if(testScanf != 1 || x<1 || x>XM-1)
                    {
                        printf("\n Il faut un chiffre allant de 1 a %d \n", XM-1);
                    }
                    purge();
                }
                while(testScanf != 1 || x<1 || x>XM-1);
                if(map[y][x][joueur]!='o')
                {
                    printf("\n Il y a deja un bateau ici, merci de recommencer le placement de ce bateau \n");
                }
                else if((map[y+1][x][joueur]!='o' || map[y+2][x][joueur]!='o' || map[y+3][x][joueur]!='o')
                        && (map[y-1][x][joueur]!='o' || map[y-2][x][joueur]!='o' || map[y-3][x][joueur]!='o')
                        && (map[y][x+1][joueur]!='o' || map[y][x+2][joueur]!='o' || map[y][x+3][joueur]!='o')
                        && (map[y][x-1][joueur]!='o' || map[y][x-2][joueur]!='o' || map[y][x-3][joueur]!='o'))
                {
                    printf("\n Vous ne pourrez pas placer les autre morceaux de votre bateau, merci de choisir un autre point de depart \n");
                }
            }while(map[y][x][joueur]!='o'  || ((map[y+1][x][joueur]!='o' || map[y+2][x][joueur]!='o' || map[y+3][x][joueur]!='o')
                                            && (map[y-1][x][joueur]!='o' || map[y-2][x][joueur]!='o' || map[y-3][x][joueur]!='o')
                                            && (map[y][x+1][joueur]!='o' || map[y][x+2][joueur]!='o' || map[y][x+3][joueur]!='o')
                                            && (map[y][x-1][joueur]!='o' || map[y][x-2][joueur]!='o' || map[y][x-3][joueur]!='o')));


            do
            {

                do
                {
                    printf("\n Choisisez l'orientation de votre bateau \n");
                    printf("1 pour vers le bas, 2 pour vers la droite, 3 pour vers le haut ou 4 pour vers la gauche :", XM-1);
                    fflush(stdout);
                    testScanf = scanf("%d", &orientation);
                    if(testScanf != 1 || orientation<1 || orientation>4)
                    {
                        printf("\n Il faut un chiffre allant de 1 a 4 \n", XM-1);
                    }
                    purge();
                }
                while(testScanf != 1 || orientation<1 || orientation>4);

                if(orientation==1 && y+3<=(YM-1) && map[y][x][joueur]=='o' && map[y+1][x][joueur]=='o' && map[y+2][x][joueur]=='o' && map[y+3][x][joueur]=='o')
                {
                    map[y][x][joueur]='D';
                    map[y+1][x][joueur]='D';
                    map[y+2][x][joueur]='D';
                    map[y+3][x][joueur]='D';
                    printf("\n votre bateau 4 a ete placer en position y:%d x:%d, y:%d x:%d, y:%d x%d et y:%d x:%d \n", y, x, y+1, x, y+2, x, y+3, x);
                }
                else if(orientation==2 && x+3<=(XM-1) && map[y][x][joueur]=='o' && map[y][x+1][joueur]=='o' && map[y][x+2][joueur]=='o' && map[y][x+3][joueur]=='o')
                {
                    map[y][x][joueur]='D';
                    map[y][x+1][joueur]='D';
                    map[y][x+2][joueur]='D';
                    map[y][x+3][joueur]='D';
                    printf("\n votre bateau 4 a ete placer en position y:%d x:%d, y:%d x:%d, y:%d x:%d et y:%d x:%d \n", y, x, y, x+1, y, x+2, y, x+3);
                }
                else if(orientation==3 && y-3>=1 && map[y][x][joueur]=='o' && map[y-1][x][joueur]=='o' && map[y-2][x][joueur]=='o' && map[y-3][x][joueur]=='o')
                {
                    map[y][x][joueur]='D';
                    map[y-1][x][joueur]='D';
                    map[y-2][x][joueur]='D';
                    map[y-3][x][joueur]='D';
                    printf("\n votre bateau 4 a ete placer en position y:%d x:%d et y:%d x:%d, y:%d x:%d et y:%d x:%d \n", y, x, y-1, x, y-2, x, y-3, x);
                }
                else if(orientation==4 && x-3<=1 && map[y][x][joueur]=='o' && map[y][x-1][joueur]=='o' && map[y][x-2][joueur]=='o' && map[y][x-3][joueur]=='o')
                {
                    map[y][x][joueur]='D';
                    map[y][x-1][joueur]='D';
                    map[y][x-2][joueur]='D';
                    map[y][x-3][joueur]='D';
                    printf("\n votre bateau 4 a ete placer en position y:%d x:%d et y:%d x:%d, y:%d x:%d et y:%d x:%d \n", y, x, y, x-1, y, x-2, y, x-3);
                }
                else
                {
                    printf("\n Erreur! \n");
                    printf("Bateau sortie de la carte ou impossibilite de superposer les bateau \n");
                    printf("merci de recommencer \n");
                }
            }
            while(map[y][x][joueur]=='o' && map[y][x][joueur]!='D');
        }
        while(map[y][x][joueur]=='o' && map[y][x][joueur]!='D');

        vie[joueur][3] = vie[joueur][3]+4;
    }
void pointVie(int vie[2][4], int mod){
        if(mod==1)
        {
            printf("############################################################\n");
            printf("#                                                          #\n");
            printf("#          Nombre de morceau(x) de l IA 1 intacte          #\n");
            printf("#  Du bateau A: %d                                          #\n", vie[J1][0]);
            printf("#  Du bateau B: %d                                          #\n", vie[J1][1]);
            printf("#  Des bateaux C: %d                                        #\n", vie[J1][2]);
            printf("#  Des bateaux D: %d                                        #\n", vie[J1][3]);
            printf("#                                                          #\n");
            printf("#          Nombre de morceau(x) de l IA 2 intacte          #\n");
            printf("#  Du bateau A: %d                                          #\n", vie[J2][0]);
            printf("#  Du bateau B: %d                                          #\n", vie[J2][1]);
            printf("#  Des bateaux C: %d                                        #\n", vie[J2][2]);
            printf("#  Des bateaux D: %d                                        #\n", vie[J2][3]);
            printf("#                                                          #\n");
            printf("############################################################\n");
        }
        else
        {
            printf("############################################################\n");
            printf("#                                                          #\n");
            printf("#      Nombre de morceau(x) intacte de votre flote         #\n");
            printf("#  Du bateau A: %d                                          #\n", vie[J1][0]);
            printf("#  Du bateau B: %d                                          #\n", vie[J1][1]);
            printf("#  Des bateaux C: %d                                        #\n", vie[J1][2]);
            printf("#  Des bateaux D: %d                                        #\n", vie[J1][3]);
            printf("#                                                          #\n");
            printf("#           Nombre de morceau(x) de l IA intacte           #\n");
            printf("#  Du bateau A: %d                                          #\n", vie[J2][0]);
            printf("#  Du bateau B: %d                                          #\n", vie[J2][1]);
            printf("#  Des bateaux C: %d                                        #\n", vie[J2][2]);
            printf("#  Des bateaux D: %d                                        #\n", vie[J2][3]);
            printf("#                                                          #\n");
            printf("############################################################\n");
        }

    }
void write(char map[YM][XM][3], int vie[2][4]){
        FILE* ftp = fopen("./save.txt","w+");
        int i, j;

        for(i=0; i<YM; i++)
        {
            for(j=0; j<XM; j++)
            {
                fprintf(ftp, "%c", map[i][j][J1]);
            }
        }

        for(i=0; i<YM; i++)
        {
            for(j=0; j<XM; j++)
            {
                fprintf(ftp, "%c", map[i][j][J2]);
            }
        }
        for(i=0; i<YM; i++)
        {
            for(j=0; j<XM; j++)
            {
                fprintf(ftp, "%c", map[i][j][IAVSJ]);
            }
        }
        for(i=0; i<4; i++)
        {
            fprintf(ftp, "%d ", vie[J1][i]);
        }
        for(i=0; i<4; i++)
        {
            fprintf(ftp, "%d ", vie[J2][i]);
        }
        fclose(ftp);
    }
void filerRead(char map[YM][XM][3], int vie[2][4]){
        FILE* ftpr = fopen("./save.txt","r");
        int i, j;

        for(i=0; i<YM; i++)
        {
            for(j=0; j<XM; j++)
            {
                map[i][j][J1] = fgetc(ftpr);
            }
        }

        for(i=0; i<YM; i++)
        {
            for(j=0; j<XM; j++)
            {
                map[i][j][J2] = fgetc(ftpr);
            }
        }
        for(i=0; i<YM; i++)
        {
            for(j=0; j<XM; j++)
            {
                map[i][j][IAVSJ] = fgetc(ftpr);
            }
        }
        for(i=0; i<4; i++)
        {
             fscanf(ftpr, "%d", &vie[J1][i]);
        }
        for(i=0; i<4; i++)
        {
            fscanf(ftpr, "%d", &vie[J2][i]);
        }
        fclose(ftpr);
    }
void joueurVsIA(char map[YM][XM][3], int vie[2][4], int mod){
        int attaqueyJ1=NULL;
        int attaquexJ1=NULL;
        int attaqueyJ2=NULL;
        int attaquexJ2=NULL;
        int testScanf=NULL;

        printf("Bienvenue dans le mode Joueur contre IA \n");

    // IA Attaque  sur la carte du joueur 1 (c'est la carte map[i][j][1])
        while((vie[J1][0]>0 || vie[J1][1]>0 || vie[J1][2]>0 || vie[J1][3]>0) && (vie[J2][0]>0 || vie[J2][1]>0 || vie[J2][2]>0 || vie[J2][3]>0))  //Boucle jusqu'à ce que l'un des 2 joueur n'as plus de bateau en vie
        {
            do
            {
                attaqueyJ2 = doRand(1,YM+1);
                attaquexJ2 = doRand(1,XM+1);
            }
            while(map[attaqueyJ2][attaquexJ2][J1]=='.' || map[attaqueyJ2][attaquexJ2][J1]=='*');  // Boucle pour éviter de tirer plusieur fois au même endroit.

            if(map[attaqueyJ2][attaquexJ2][J1]=='A')
            {
                vie[J1][0]=vie[J1][0]-1;
                map[attaqueyJ2][attaquexJ2][J1]='*';
                printf("IA touche votre bateau A en y: %d x: %d \n", attaqueyJ2, attaquexJ2);
            }
            else if(map[attaqueyJ2][attaquexJ2][J1]=='B')
            {
                vie[J1][1]=vie[J1][1]-1;
                map[attaqueyJ2][attaquexJ2][J1]='*';
                printf("IA touche votre bateau B en y: %d x: %d \n", attaqueyJ2, attaquexJ2);
            }
            else if(map[attaqueyJ2][attaquexJ2][J1]=='C')
            {
                vie[J1][2]=vie[J1][2]-1;
                map[attaqueyJ2][attaquexJ2][J1]='*';
                printf("IA touche votre bateau C en y: %d x: %d \n", attaqueyJ2, attaquexJ2);
            }
            else if(map[attaqueyJ2][attaquexJ2][J1]=='D')
            {
                vie[J1][3]=vie[J1][3]-1;
                map[attaqueyJ2][attaquexJ2][J1]='*';
                printf("IA touche votre bateau D en y: %d x: %d \n", attaqueyJ2, attaquexJ2);
            }
            else if (map[attaqueyJ2][attaquexJ2][J1]=='o')
            {
                map[attaqueyJ2][attaquexJ2][J1]='.';
                printf("IA loupe en y: %d x: %d \n", attaqueyJ2, attaquexJ2);
            }

            printMap(map,J1, mod);
            printMap(map,IAVSJ, mod);
            //printMap(map,J2,mod); //Verification

            if(vie[J1][0]>0 || vie[J1][1]>0 || vie[J1][2]>0 || vie[J2][3]>0)
            {

//Attaque du joueur 1 sur la carte de L'IA (J2), La carte de l'IA map[][][J2] et affichage sur la map visible map[][][IAVSJ]
                do
                {
                    do
                    {
                        printf("Choisisez la position vertical(y) de votre attaque la position doit etre un chiffre allant de 1 a %d :\n", YM-1);
                        testScanf = scanf("%d", &attaqueyJ1);
                        if(attaqueyJ1>YM-1 || attaqueyJ1<1 || testScanf != 1)
                        {
                            printf("Il faut un nombre entre 0 et %d \n", YM-1);
                        }
                        purge();
                    }
                    while(testScanf != 1 || attaqueyJ1>YM-1 || attaqueyJ1<1);

                    do
                    {
                        printf("Choisisez la position horizontal(x) de votre attaque la position doit un chiffre allant de 1 a %d :\n", XM-1);
                        testScanf = scanf("%d", &attaquexJ1);
                        if(attaquexJ1>XM-1 || attaquexJ1<1 || testScanf != 1)
                        {
                            printf("Il faut un nombre entre 0 et %d \n", XM-1);
                        }
                        purge();
                    }
                    while(testScanf != 1 || attaquexJ1>XM-1 || attaquexJ1<1);

                    if(map[attaqueyJ1][attaquexJ1][J2]=='*')
                    {
                        printf("Votre attaque est en y: %d et x: %d \n", attaqueyJ1, attaquexJ1);
                        printf("Vous avez deja attaque ici! \n Vous aviez touche, vous pouvez recommencer votre attaque \n");
                    }
                    else if(map[attaqueyJ1][attaquexJ1][J2]=='.')
                    {
                        printf("Votre attaque est en y: %d et x: %d \n", attaqueyJ1, attaquexJ1);
                        printf("Vous avez deja attaque ici! \n Vous aviez loupe, vous pouvez recommencer votre attaque \n");
                    }
                }
                while(map[attaqueyJ1][attaquexJ1][J2]=='.' || map[attaqueyJ1][attaquexJ1][J2]=='*'); // Boucle pour éviter de tirer plusieur fois au même endroit.

                if(map[attaqueyJ1][attaquexJ1][J2]=='A')
                {
                    vie[J2][0]=vie[J2][0]-1;
                    map[attaqueyJ1][attaquexJ1][IAVSJ]='*';
                    map[attaqueyJ1][attaquexJ1][J2]='*';
                    printf("Votre attaque a reussi en y: %d x: %d \n", attaqueyJ2, attaquexJ2);
                    if(vie[J2][0]==0)
                    {
                        printf("Le bateau A coule \n");
                    }
                }
                else if(map[attaqueyJ1][attaquexJ1][J2]=='B')
                {
                    vie[J2][1]=vie[J2][1]-1;
                    map[attaqueyJ1][attaquexJ1][IAVSJ]='*';
                    map[attaqueyJ1][attaquexJ1][J2]='*';
                    printf("Votre attaque a reussi en y: %d x: %d \n", attaqueyJ2, attaquexJ2);
                    if(vie[J2][1]==0)
                    {
                        printf("Le bateau B coule \n");
                    }
                }
                else if(map[attaqueyJ1][attaquexJ1][J2]=='C')
                {
                    vie[J2][2]=vie[J2][2]-1;
                    map[attaqueyJ1][attaquexJ1][IAVSJ]='*';
                    map[attaqueyJ1][attaquexJ1][J2]='*';
                    printf("Votre attaque a reussi en y: %d x: %d \n", attaqueyJ2, attaquexJ2);
                    if(vie[J2][2]==0)
                    {
                        printf("Les bateaux C coule \n");
                    }
                }
                else if(map[attaqueyJ1][attaquexJ1][J2]=='D')
                {
                    vie[J2][3]=vie[J2][3]-1;
                    map[attaqueyJ1][attaquexJ1][IAVSJ]='*';
                    map[attaqueyJ1][attaquexJ1][J2]='*';
                    printf("Votre attaque a reussi en y: %d x: %d \n", attaqueyJ2, attaquexJ2);
                    if(vie[J2][3]==0)
                    {
                        printf("Les Bateaux D coule \n");
                    }
                }

                else if (map[attaqueyJ1][attaquexJ1][J2]=='o')
                {
                    map[attaqueyJ1][attaquexJ1][IAVSJ]='.';
                    map[attaqueyJ1][attaquexJ1][J2]='.';
                    printf("Votre attaque a loupe en y: %d x: %d \n", attaqueyJ1, attaquexJ1);
                }
            }
            else{}
            printf("\n ! Point de sauvegarde ! \n");
            write(map, vie);
        }

        pointVie(vie, mod);

        if(vie[J1][0]==0 && vie[J1][1]==0 && vie[J1][2]==0 && vie[J1][3]==0)
        {
            printf("###############################################\n");
            printf("#                                             #\n");
            printf("#               L IA a gagner!!               #\n");
            printf("#                                             #\n");
            printf("###############################################\n");
        }
        else if(vie[J2][0]==0 && vie[J2][1]==0 && vie[J2][2]==0 && vie[J2][3]==0)
        {
            printf("###############################################\n");
            printf("#                                             #\n");
            printf("#              Vous avez gagner!!             #\n");
            printf("#                                             #\n");
            printf("###############################################\n");
        }
    }
void poseBateauIAvsJ(char map[YM][XM][3], int vie[2][4], int mod){
        initMap(map);
        printMap(map,J1, mod);
//positionement des bateauy

//pour joueur 1

        bateauAReal(map,J1,vie);
        printMap(map,J1, mod);

        bateauBReal(map,J1,vie);
        printMap(map,J1, mod);

        bateauCReal(map,J1,vie);
        printMap(map,J1, mod);

        bateauCReal(map,J1,vie);
        printMap(map,J1, mod);

        bateauDReal(map,J1,vie);
        printMap(map,J1, mod);

        bateauDReal(map,J1,vie);

//pour joueur 2 IA
        bateauA(map,J2,vie);

        bateauB(map,J2,vie);

        bateauC(map,J2,vie);
        bateauC(map,J2,vie);

        bateauD(map,J2,vie);
        bateauD(map,J2,vie);

        printf("\n ! Point de sauvegarde ! \n");
        write(map, vie);
        printMap(map,J1, mod);
        printMap(map,IAVSJ, mod);
        //printMap(map,J2, mod); //Verification
    }
void iaVsIA(char map[YM][XM][3], int vie[2][4], int mod){
        int attaqueyJ1=NULL;
        int attaquexJ1=NULL;
        int attaqueyJ2=NULL;
        int attaquexJ2=NULL;

         //Initialisation des cartes

        initMap(map);

        //positionement des bateauy

            //pour joueur 1

        printf("En cour de placement pour le joueur 1\n");

        bateauA(map,J1,vie);

        bateauB(map,J1,vie);

        bateauC(map,J1,vie);
        bateauC(map,J1,vie);

        bateauD(map,J1,vie);
        bateauD(map,J1,vie);

            //pour joueur 2

        printf("En cour de placement pour le joueur 2\n");

        bateauA(map,J2,vie);

        bateauB(map,J2,vie);

        bateauC(map,J2,vie);
        bateauC(map,J2,vie);

        bateauD(map,J2,vie);
        bateauD(map,J2,vie);

                    //Carte joueur 1 avec bateauy
        printMap(map,J1, mod);
                     //Carte joueur 2 avec bateauy
        printMap(map,J2, mod);

           // IA Attaque
        while((vie[J1][0]>0 || vie[J1][1]>0 || vie[J1][2]>0 || vie[J1][3]>0) && (vie[J2][0]>0 || vie[J2][1]>0 || vie[J2][2]>0 || vie[J2][3]>0))  //Boucle jusqu'à ce que l'un des 2 joueur n'as plus de bateau en vie
                //Je ne comprend pas pourquoi il faut un "ET" ici... et non un "OU"...
        {
    //Attaque du joueur 2 sur la carte du joueur 1 (c'est la carte map[i][j][1])

            do
            {
                attaqueyJ2 = doRand(1,YM+1);
                attaquexJ2 = doRand(1,XM+1);
            }
            while(map[attaqueyJ2][attaquexJ2][J1]=='.' || map[attaqueyJ2][attaquexJ2][J1]=='*');  // Boucle pour éviter de tirer plusieur fois au même endroit.

            if(map[attaqueyJ2][attaquexJ2][J1]=='A')
            {
                vie[J1][0]=vie[J1][0]-1;
                map[attaqueyJ2][attaquexJ2][J1]='*';
                printf("attaque de l IA 2 reussi en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
            }
            else if(map[attaqueyJ2][attaquexJ2][J1]=='B')
            {
                vie[J1][1]=vie[J1][1]-1;
                map[attaqueyJ2][attaquexJ2][J1]='*';
                printf("attaque de l IA 2 reussi en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
            }
            else if(map[attaqueyJ2][attaquexJ2][J1]=='C')
            {
                vie[J1][2]=vie[J1][2]-1;
                map[attaqueyJ2][attaquexJ2][J1]='*';
                printf("attaque de l IA 2 reussi en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
            }
            else if(map[attaqueyJ2][attaquexJ2][J1]=='D')
            {
                vie[J1][3]=vie[J1][3]-1;
                map[attaqueyJ2][attaquexJ2][J1]='*';
                printf("attaque de l IA 2 reussi en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
            }
            else if (map[attaqueyJ2][attaquexJ2][J1]=='o')
            {
                map[attaqueyJ2][attaquexJ2][J1]='.';
            }

            if(vie[J1][0]>0 || vie[J1][1]>0 || vie[J1][2]>0 || vie[J1][3]>0)
            {
    //Attaque du joueur 1 sur la carte du joueur 2 (c'est la carte map[a][a][0])
                do
                {
                    attaqueyJ1 = doRand(1,YM+1);
                    attaquexJ1 = doRand(1,XM+1);
                }
                while(map[attaqueyJ1][attaquexJ1][J2]=='.' || map[attaqueyJ1][attaquexJ1][J2]=='*'); // Boucle pour éviter de tirer plusieur fois au même endroit.

                if(map[attaqueyJ1][attaquexJ1][J2]=='A')
                {
                    vie[J2][0]=vie[J2][0]-1;
                    map[attaqueyJ1][attaquexJ1][J2]='*';
                    printf("attaque de l IA 1 reussi en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
                }
                else if(map[attaqueyJ1][attaquexJ1][J2]=='B')
                {
                    vie[J2][1]=vie[J2][1]-1;
                    map[attaqueyJ1][attaquexJ1][J2]='*';
                    printf("attaque de l IA 1 reussi en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
                }
                else if(map[attaqueyJ1][attaquexJ1][J2]=='C')
                {
                    vie[J2][2]=vie[J2][2]-1;
                    map[attaqueyJ1][attaquexJ1][J2]='*';
                    printf("attaque de l IA 1 reussi en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
                }
                else if(map[attaqueyJ1][attaquexJ1][J2]=='D')
                {
                    vie[J2][3]=vie[J2][3]-1;
                    map[attaqueyJ1][attaquexJ1][J2]='*';
                    printf("attaque de l IA 1 reussi en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
                }

                else if (map[attaqueyJ1][attaquexJ1][J2]=='o')
                {
                    map[attaqueyJ1][attaquexJ1][J2]='.';
                }
            }
            else{}
        }

        printMap(map,J1, mod);
        printMap(map,J2, mod);
        pointVie(vie,mod);

        if(vie[J1][0]==0 && vie[J1][1]==0 && vie[J1][2]==0 && vie[J1][3]==0)
        {
            printf("###############################################\n");
            printf("#                                             #\n");
            printf("#              L IA 2 a gagner!!              #\n");
            printf("#                                             #\n");
            printf("###############################################\n");
        }
        else if(vie[J2][0]==0 && vie[J2][1]==0 && vie[J2][2]==0 && vie[J2][3]==0)
        {
            printf("###############################################\n");
            printf("#                                             #\n");
            printf("#              L IA 1 a gagner!!              #\n");
            printf("#                                             #\n");
            printf("###############################################\n");
        }
    }
int main(int argc, char *argv[])
{
    int testScanf=NULL;

    int vie[2][4]={NULL};
    char map[YM][XM][3]={NULL};

    int mode=0;

    do
    {
        printf("#############################################\n");
        printf("#                                           #\n");
        printf("#    Pour le mode IA contre IA   tapper 1   #\n");
        printf("#                                           #\n");
        printf("#   Pour le mode joueur contre IA tapper 2  #\n");
        printf("#                                           #\n");
        printf("#       Pour charger une partie tapper 3    #\n");
        printf("#                                           #\n");
        printf("#############################################\n");
        printf("\n");
        printf("             Choisir le mode:");
        fflush(stdout);
        testScanf = scanf("%d", &mode);
        if(testScanf != 1 || mode<1 || mode>3)
        {
            printf("Il faut un nombre allant de 1 a 3 \n");
        }
        purge();
    }
    while(testScanf != 1 || mode<1 || mode>3);

    switch(mode)
    {
        case 1: // IA vs IA

        iaVsIA(map, vie, mode);

        break;

        case 2: //joueur vs IA

        poseBateauIAvsJ(map, vie, mode); //avec sauvegarde des position de bateau
        joueurVsIA(map, vie, mode);

        break;

        case 3: //mode chargement de sauvegarde pour Joueur vs IA

        filerRead(map, vie);
        printMap(map,J1, mode);
        printMap(map,IAVSJ, mode);
        //printMap(map,J2); //Verification
        joueurVsIA(map, vie, mode);

        break;

    }
    return 0;
}
