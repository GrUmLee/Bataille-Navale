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
void printMap(char map[YM][XM][3], int joueur){
    int i, j;
    if(joueur==0 || joueur==1)
    {
        printf("\n######################\n");
        printf("#  Carte du joueur %d #\n", joueur+1);
        printf("######################\n");
    }
    else if(joueur==2)
    {
        printf("\n######################\n");
        printf("#   Carte du l IA    #\n");
        printf("######################\n");
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
    int i, j;
    printf("Initialisation des cartes des 2 joueurs.\n");
    for(i=0; i<YM; i++)
    {
        for(j=0; j<XM; j++)
        {
            map[i][j][J1]='0';
            map[i][j][J2]='0';
            map[i][j][IAVSJ]='?';
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
void bateau1(char map[YM][XM][3], int joueur, char vie[2][4]){
    int y, x;
    do{
        do
        {
            y=doRand(0,(YM-1));
            x=doRand(0,(XM-1));
        }
        while(map[y][x][joueur]!='0');
        do{
            if (map[y][x][joueur]=='0')
            {
                map[y][x][joueur]='1';
            }
            else{}
        }
        while(map[y][x][joueur]!='0' && map[y][x][joueur]!='1');
    }
    while(map[y][x][joueur]!='0' && map[y][x][joueur]!='1');
    vie[joueur][0] = vie[joueur][0]+1;
}
void bateau2(char map[YM][XM][3], int joueur, char vie[2][4]){
    int y, x, rdmPos;

    do
    {
        do
        {
            y=doRand(0,YM-1);

            x=doRand(0,XM-1);
        }
        while(map[y][x][joueur]!='0');

        do
        {
            rdmPos=doRand(1,4);

            if(rdmPos==1 && y+1<=YM-1 && map[y][x][joueur]=='0' && map[y+1][x][joueur]=='0')
            {
                map[y][x][joueur]='2';
                map[y+1][x][joueur]='2';
            }
            else if(rdmPos==2 && x+1<=(XM-1) && map[y][x][joueur]=='0' && map[y][x+1][joueur]=='0')
            {
                map[y][x][joueur]='2';
                map[y][x+1][joueur]='2';
            }
            else if(rdmPos==3 && y-2>=0 && map[y][x][joueur]=='0' && map[y-1][x][joueur]=='0')
            {
                map[y][x][joueur]='2';
                map[y-1][x][joueur]='2';
            }
            else if(rdmPos==4 && x-2>=0 && map[y][x][joueur]=='0' && map[y][x-1][joueur]=='0')
            {
                map[y][x][joueur]='2';
                map[y][x-1][joueur]='2';
            }
            else{}
        }
        while(map[y][x][joueur]=='0' && map[y][x][joueur]!='2');
    }
    while(map[y][x][joueur]!='2');
    vie[joueur][1] = vie[joueur][1]+2;
}
void bateau3(char map[YM][XM][3], int joueur, char vie[2][4]){
    int y,x, rdmPos;

    do
    {
        do
        {
            y=doRand(0,YM-1);
            x=doRand(0,XM-1);
        }
        while(map[y][x][joueur]!='0');

        do
        {
            rdmPos=doRand(1,4);

            if(rdmPos==1 && y+2<=(YM-1) && map[y][x][joueur]=='0' && map[y+1][x][joueur]=='0' && map[y+2][x][joueur]=='0')
            {
                map[y][x][joueur]='3';
                map[y+1][x][joueur]='3';
                map[y+2][x][joueur]='3';
            }
            else if(rdmPos==2 && x+2<=(XM-1) && map[y][x][joueur]=='0' && map[y][x+1][joueur]=='0' && map[y][x+2][joueur]=='0')
            {
                map[y][x][joueur]='3';
                map[y][x+1][joueur]='3';
                map[y][x+2][joueur]='3';
            }
            else if(rdmPos==3 && y-2>=0 && map[y][x][joueur]=='0' && map[y-1][x][joueur]=='0' && map[y-2][x][joueur]=='0')
            {
                map[y][x][joueur]='3';
                map[y-1][x][joueur]='3';
                map[y-2][x][joueur]='3';
            }
            else if(rdmPos==4 && x-2>=0 && map[y][x][joueur]=='0' && map[y][x-1][joueur]=='0' && map[y][x-2][joueur]=='0')
            {
                map[y][x][joueur]='3';
                map[y][x-1][joueur]='3';
                map[y][x-2][joueur]='3';
            }
            else{}
        }
        while( map[y][x][joueur]=='0' && map[y][x][joueur]!='3');
    }
    while(map[y][x][joueur]=='0' && map[y][x][joueur]!='3');
    vie[joueur][2] = vie[joueur][2]+3;
}
void bateau4(char map[YM][XM][3], int joueur, char vie[2][4]){

    int y,x,rdmPos;

    do
    {
        do
        {
            y=doRand(0,YM-1);

            x=doRand(0,XM-1);
        }
        while(map[y][x][joueur]!='0');

        do
        {
            rdmPos=doRand(1,4);

            if(rdmPos==1 && y+3<=(YM-1) && map[y][x][joueur]=='0' && map[y+1][x][joueur]=='0' && map[y+2][x][joueur]=='0' && map[y+3][x][joueur]=='0')
            {
                map[y][x][joueur]='4';
                map[y+1][x][joueur]='4';
                map[y+2][x][joueur]='4';
                map[y+3][x][joueur]='4';
            }
            else if(rdmPos==2 && x+3<=(XM-1) && map[y][x][joueur]=='0' && map[y][x+1][joueur]=='0' && map[y][x+2][joueur]=='0' && map[y][x+3][joueur]=='0')
            {
                map[y][x][joueur]='4';
                map[y][x+1][joueur]='4';
                map[y][x+2][joueur]='4';
                map[y][x+3][joueur]='4';
            }
            else if(rdmPos==3 && y-3>=0 && map[y][x][joueur]=='0' && map[y-1][x][joueur]=='0' && map[y-2][x][joueur]=='0' && map[y-3][x][joueur]=='0')
            {
                map[y][x][joueur]='4';
                map[y-1][x][joueur]='4';
                map[y-2][x][joueur]='4';
                map[y-3][x][joueur]='4';
            }
            else if(rdmPos==4 && x-3<=0 && map[y][x][joueur]=='0' && map[y][x-1][joueur]=='0' && map[y][x-2][joueur]=='0' && map[y][x-3][joueur]=='0')
            {
                map[y][x][joueur]='4';
                map[y][x-1][joueur]='4';
                map[y][x-2][joueur]='4';
                map[y][x-3][joueur]='4';
            }
            else{}
        }
        while(map[y][x][joueur]=='0' && map[y][x][joueur]!='4');
    }
    while(map[y][x][joueur]=='0' && map[y][x][joueur]!='4');
    vie[joueur][3] = vie[joueur][3]+4;
}
void bateau1Real(char map[YM][XM][3],int joueur, char vie[2][4]){
    int y, x, testScanf;

    do
    {
        do
        {
            printf("\nChoisisez la position y de votre bateau 1 la position doit etre un chiffre allant de 0 a %d :", YM-1);
            fflush(stdout);
            testScanf = scanf("%d", &y);
            if(testScanf != 1 || y<0 || y>YM-1)
            {
                printf("\n Il faut un chiffre allant de 0 a %d \n", YM-1);
            }
            purge();
        }
        while(testScanf != 1 || y<0 || y>YM-1);

        do
        {
            printf("\nChoisisez la position x de votre bateau 1 la position doit etre un chiffre allant de 0 a %d :", XM-1);
            fflush(stdout);
            testScanf = scanf("%d", &x);
            if(testScanf != 1 || x<0 || x>XM-1)
            {
                printf("\n Il faut un chiffre allant de 0 a %d \n", XM-1);
            }
            purge();
        }
        while(testScanf != 1 || x<0 || x>XM-1);
    }
    while(map[y][x][joueur]!='0');

    map[y][x][joueur]='1';
    vie[joueur][0] = vie[joueur][0]+1;
}
void bateau2Real(char map[YM][XM][3],int joueur, char vie[2][4]){
    int y, x, orientation, testScanf;

    do
    {
        do
        {
            printf("\nChoisisez la position y de votre bateau 2 la position doit etre un chiffre allant de 0 a %d :", YM-1);
            fflush(stdout);
            testScanf = scanf("%d", &y);
            if(testScanf != 1 || y<0 || y>YM-1)
            {
                printf("\n Il faut un chiffre allant de 0 a %d \n", YM-1);
            }
            purge();
        }
        while(testScanf != 1 || y<0 || y>YM-1);
        do
        {
            printf("\nChoisisez la position x de votre bateau 2 la position doit etre un chiffre allant de 0 a %d :", XM-1);
            fflush(stdout);
            testScanf = scanf("%d", &x);
            if(testScanf != 1 || x<0 || x>XM-1)
            {
                printf("\n Il faut un chiffre allant de 0 a %d \n", XM-1);
            }
            purge();
        }
        while(testScanf != 1 || x<0 || x>XM-1);

        do
        {
            do
            {
                printf("Choisisez l'orientation de votre bateau\n 1 pour vers le bas, 2 pour vers la droite, 3 pour vers le haut ou 4 pour vers la gauche : \n", XM-1);
                fflush(stdout);
                scanf("%d", &orientation);
                if(testScanf != 1  || orientation<1 || orientation>4)
                {
                    printf("\n Il faut un chiffre allant de 1 a 4 \n");
                }
                purge();
            }
            while(testScanf != 1 || orientation<1 || orientation>4);

            if(orientation==1 && y+1<=YM-1 && map[y][x][joueur]=='0' && map[y+1][x][joueur]=='0')
            {
                map[y][x][joueur]='2';
                map[y+1][x][joueur]='2';
                printf("votre bateau 2 a ete placer en position y:%d x:%d et y:%d x:%d \n", y, x, y+1, x);
            }
            else if(orientation==2 && x+1<=(XM-1) && map[y][x][joueur]=='0' && map[y][x+1][joueur]=='0')
            {
                map[y][x][joueur]='2';
                map[y][x+1][joueur]='2';
                printf("votre bateau 2 a ete placer en position y:%d x:%d et y:%d x:%d \n", y, x, y, x+1);
            }
            else if(orientation==3 && y-2>=0 && map[y][x][joueur]=='0' && map[y-1][x][joueur]=='0')
            {
                map[y][x][joueur]='2';
                map[y-1][x][joueur]='2';
                printf("votre bateau 2 a ete placer en position y:%d x:%d et y:%d x:%d \n", y, x, y-1, x);
            }
            else if(orientation==4 && x-2>=0 && map[y][x][joueur]=='0' && map[y][x-1][joueur]=='0')
            {
                map[y][x][joueur]='2';
                map[y][x-1][joueur]='2';
                printf("votre bateau 2 a ete placer en position y:%d x:%d et y:%d x:%d \n", y, x, y, x-1);
            }
            else
            {
                printf("Erreur, merci de recommencer \n");
            }
        }
        while(map[y][x][joueur]=='0' && map[y][x][joueur]!='2');
    }
    while(map[y][x][joueur]=='0' && map[y][x][joueur]!='2');

    vie[joueur][1] = vie[joueur][1]+2;
}
void bateau3Real(char map[YM][XM][3],int joueur, char vie[2][4]){
    int y, x, orientation, testScanf;
    do
    {
        do
        {
            printf("\nChoisisez la position y de votre bateau 3 la position doit etre un chiffre allant de 0 a %d :", YM-1);
            fflush(stdout);
            testScanf = scanf("%d", &y);
            if(testScanf != 1 || y<0 || y>YM-1)
            {
                printf("\n Il faut un chiffre allant de 0 a %d \n", YM-1);
            }
            purge();
        }
        while(testScanf != 1 || y<0 || y>YM-1);
        do
        {
            printf("\nChoisisez la position x de votre bateau 3 la position doit etre un chiffre allant de 0 a %d :", XM-1);
            fflush(stdout);
            testScanf = scanf("%d", &x);
            if(testScanf != 1 || x<0 || x>XM-1)
            {
                printf("\n Il faut un chiffre allant de 0 a %d \n", XM-1);
            }
            purge();
        }
        while(testScanf != 1 || x<0 || x>XM-1);

        do
        {

            do
            {
                printf("\n Choisisez l'orientation de votre bateau\n 1 pour vers le bas, 2 pour vers la droite, 3 pour vers le haut ou 4 pour vers la gauche :", XM-1);
                fflush(stdout);
                testScanf = scanf("%d", &orientation);
                if(testScanf != 1 || orientation<1 || orientation>4)
                {
                    printf("\n Il faut un chiffre allant de 1 a 4 \n", XM-1);
                }
                purge();
            }
            while(testScanf != 1 || orientation<1 || orientation>4);

            if(orientation==1 && y+2<=(YM-1) && map[y][x][joueur]=='0' && map[y+1][x][joueur]=='0' && map[y+2][x][joueur]=='0')
            {
                map[y][x][joueur]='3';
                map[y+1][x][joueur]='3';
                map[y+2][x][joueur]='3';
                printf("votre bateau 3 a ete placer en position y:%d x:%d, y:%d x:%d et y:%d x:%d \n", y, x, y+1, x, y+2, x);
            }
            else if(orientation==2 && x+2<=(XM-1) && map[y][x][joueur]=='0' && map[y][x+1][joueur]=='0' && map[y][x+2][joueur]=='0')
            {
                map[y][x][joueur]='3';
                map[y][x+1][joueur]='3';
                map[y][x+2][joueur]='3';
                printf("votre bateau 3 a ete placer en position y:%d x:%d, y:%d x:%d et y:%d x:%d \n", y, x, y, x+1, y, x+2);
            }
            else if(orientation==3 && y-2>=0 && map[y][x][joueur]=='0' && map[y-1][x][joueur]=='0' && map[y-2][x][joueur]=='0')
            {
                map[y][x][joueur]='3';
                map[y-1][x][joueur]='3';
                map[y-2][x][joueur]='3';
                printf("votre bateau 3 a ete placer en position y:%d x:%d et y:%d x:%d et y:%d x:%d \n", y, x, y-1, x, y-2, x);
            }
            else if(orientation==4 && x-2>=0 && map[y][x][joueur]=='0' && map[y][x-1][joueur]=='0' && map[y][x-2][joueur]=='0')
            {
                map[y][x][joueur]='3';
                map[y][x-1][joueur]='3';
                map[y][x-2][joueur]='3';
                printf("votre bateau 3 a ete placer en position y:%d x:%d et y:%d x:%d et y:%d x:%d \n", y, x, y, x-1, y, x-2);
            }
            else
            {
                printf("Erreur, merci de recommencer \n");
            }
        }
        while(map[y][x][joueur]=='0' && map[y][x][joueur]!='3');
    }
    while(map[y][x][joueur]=='0' && map[y][x][joueur]!='3');

    vie[joueur][2] = vie[joueur][2]+3;
}
void bateau4Real(char map[YM][XM][3],int joueur, char vie[2][4]){
    int y, x, orientation, testScanf;
    do
    {
        do
        {
            printf("\nChoisisez la position y de votre bateau 4 la position doit etre un chiffre allant de 0 a %d :", YM-1);
            fflush(stdout);
            testScanf = scanf("%d", &y);
            if(testScanf != 1 || y<0 || y>YM-1)
            {
                printf("\n Il faut un chiffre allant de 0 a %d \n", YM-1);
            }
            purge();
        }
        while(testScanf != 1 || y<0 || y>YM-1);
        do
        {
            printf("\nChoisisez la position x de votre bateau 4 la position doit etre un chiffre allant de 0 a %d :", XM-1);
            fflush(stdout);
            testScanf = scanf("%d", &x);
            if(testScanf != 1 || x<0 || x>XM-1)
            {
                printf("\n Il faut un chiffre allant de 0 a %d \n", XM-1);
            }
            purge();
        }
        while(testScanf != 1 || x<0 || x>XM-1);

        do
        {

            do
            {
                printf("\n Choisisez l'orientation de votre bateau\n 1 pour vers le bas, 2 pour vers la droite, 3 pour vers le haut ou 4 pour vers la gauche :", XM-1);
                fflush(stdout);
                testScanf = scanf("%d", &orientation);
                if(testScanf != 1 || orientation<1 || orientation>4)
                {
                    printf("\n Il faut un chiffre allant de 1 a 4 \n", XM-1);
                }
                purge();
            }
            while(testScanf != 1 || orientation<1 || orientation>4);

            if(orientation==1 && y+3<=(YM-1) && map[y][x][joueur]=='0' && map[y+1][x][joueur]=='0' && map[y+2][x][joueur]=='0' && map[y+3][x][joueur]=='0')
            {
                map[y][x][joueur]='4';
                map[y+1][x][joueur]='4';
                map[y+2][x][joueur]='4';
                map[y+3][x][joueur]='4';
                printf("votre bateau 4 a ete placer en position y:%d x:%d, y:%d x:%d, y:%d x%d et y:%d x:%d \n", y, x, y+1, x, y+2, x, y+3, x);
            }
            else if(orientation==2 && x+3<=(XM-1) && map[y][x][joueur]=='0' && map[y][x+1][joueur]=='0' && map[y][x+2][joueur]=='0' && map[y][x+3][joueur]=='0')
            {
                map[y][x][joueur]='4';
                map[y][x+1][joueur]='4';
                map[y][x+2][joueur]='4';
                map[y][x+3][joueur]='4';
                printf("votre bateau 4 a ete placer en position y:%d x:%d, y:%d x:%d, y:%d x:%d et y:%d x:%d \n", y, x, y, x+1, y, x+2, y, x+3);
            }
            else if(orientation==3 && y-3>=0 && map[y][x][joueur]=='0' && map[y-1][x][joueur]=='0' && map[y-2][x][joueur]=='0' && map[y-3][x][joueur]=='0')
            {
                map[y][x][joueur]='4';
                map[y-1][x][joueur]='4';
                map[y-2][x][joueur]='4';
                map[y-3][x][joueur]='4';
                printf("votre bateau 4 a ete placer en position y:%d x:%d et y:%d x:%d, y:%d x:%d et y:%d x:%d \n", y, x, y-1, x, y-2, x, y-3, x);
            }
            else if(orientation==4 && x-3<=0 && map[y][x][joueur]=='0' && map[y][x-1][joueur]=='0' && map[y][x-2][joueur]=='0' && map[y][x-3][joueur]=='0')
            {
                map[y][x][joueur]='4';
                map[y][x-1][joueur]='4';
                map[y][x-2][joueur]='4';
                map[y][x-3][joueur]='4';
                printf("votre bateau 4 a ete placer en position y:%d x:%d et y:%d x:%d, y:%d x:%d et y:%d x:%d \n", y, x, y, x-1, y, x-2, y, x-3);
            }
            else
            {
                printf("Erreur, merci de recommencer \n");
            }
        }
        while(map[y][x][joueur]=='0' && map[y][x][joueur]!='4');
    }
    while(map[y][x][joueur]=='0' && map[y][x][joueur]!='4');

    vie[joueur][3] = vie[joueur][3]+4;
}
void pointVie(char vie[2][4]){
        printf("############################################################\n");
        printf("#                                                          #\n");
        printf("#  Nombre de morceau(x) du joueur 1 du bateau 1 intact: %d  #\n", vie[J1][0]);
        printf("#  Du bateau 2 intact: %d                                   #\n", vie[J1][1]);
        printf("#  Du bateau 3 intact: %d                                   #\n", vie[J1][2]);
        printf("#  Du bateau 4 intact: %d                                   #\n", vie[J1][3]);
        printf("#                                                          #\n");
        printf("#  Nombre de morceau(x) du joueur 2 du bateau 1 intact: %d  #\n", vie[J2][0]);
        printf("#  Du bateau 2 intact: %d                                   #\n", vie[J2][1]);
        printf("#  Du bateau 3 intact: %d                                   #\n", vie[J2][2]);
        printf("#  Du bateau 4 intact: %d                                   #\n", vie[J2][3]);
        printf("#                                                          #\n");
        printf("############################################################\n");
}
void write(char map[YM][XM][3], char vie[2][4]){
    FILE* ftp = fopen("./save.txt","w+");
    int i, j;

    for(i=0; i<YM; i++)
    {
        for(j=0; j<XM; j++)
        {
            fprintf(ftp, "%c", map[i][j][J1]);
        }
        //fputc(ftp, "\n");
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
        fprintf(ftp, "%c", vie[J1][i]);
    }
    for(i=0; i<4; i++)
    {
        fprintf(ftp, "%c", vie[J2][i]);
    }

    fclose(ftp);
}
void filerRead(char map[YM][XM][3], char vie[2][4]){
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
        vie[J1][i] = fgetc(ftpr);
    }
    for(i=0; i<4; i++)
    {
        vie[J2][i] = fgetc(ftpr);
    }
    fclose(ftpr);
}
int main(int argc, int *argv)
{
    int attaqueyJ1=NULL;
    int attaquexJ1=NULL;
    int attaqueyJ2=NULL;
    int attaquexJ2=NULL;

    char map[YM][XM][3]={0};
    char vie[2][4]={0};

    int mode=0;

    int testScanf=NULL;

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
        scanf("%d", &mode);
    }while(mode!=1 && mode!=2 && mode!=3);

    switch(mode)
    {
        case 1:

    //Initialisation des cartes

    initMap(map);

    //positionement des bateauy

        //pour joueur 1

    printf("En cour de placement pour le joueur 1\n");

    bateau1(map,J1,vie);

    bateau2(map,J1,vie);

    bateau3(map,J1,vie);
    bateau3(map,J1,vie);

    bateau4(map,J1,vie);
    bateau4(map,J1,vie);

        //pour joueur 2

    printf("En cour de placement pour le joueur 2\n");

    bateau1(map,J2,vie);

    bateau2(map,J2,vie);

    bateau3(map,J2,vie);
    bateau3(map,J2,vie);

    bateau4(map,J2,vie);
    bateau4(map,J2,vie);

    write(map, vie);

                //Carte joueur 1 avec bateauy
    printMap(map,J1);
                 //Carte joueur 2 avec bateauy
    printMap(map,J2);

// IA Attaque
        while((vie[J1][0]>0 || vie[J1][1]>0 || vie[J1][2]>0 || vie[J1][3]>0) && (vie[J2][0]>0 || vie[J2][1]>0 || vie[J2][2]>0 || vie[J2][3]>0))  //Boucle jusqu'à ce que l'un des 2 joueur n'as plus de bateau en vie
            //Je ne comprend pas pourquoi il faut un "ET" ici... et non un "OU"...
        {
//Attaque du joueur 2 sur la carte du joueur 1 (c'est la carte map[i][j][1])
            do
            {
                attaqueyJ2 = doRand(0,YM+1);
                attaquexJ2 = doRand(0,XM+1);
            }
            while(map[attaqueyJ2][attaquexJ2][J1]=='.' || map[attaqueyJ2][attaquexJ2][J1]=='*');  // Boucle pour éviter de tirer plusieur fois au même endroit.

            if(map[attaqueyJ2][attaquexJ2][J1]=='1')
            {
                vie[J1][0]=vie[J1][0]-1;
                map[attaqueyJ2][attaquexJ2][J1]='*';
                printf("attaque du joueur 2 reussi en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
                pointVie(vie);
            }
            else if(map[attaqueyJ2][attaquexJ2][J1]=='2')
            {
                vie[J1][1]=vie[J1][1]-1;
                map[attaqueyJ2][attaquexJ2][J1]='*';
                printf("attaque du joueur 2 reussi en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
                pointVie(vie);
            }
            else if(map[attaqueyJ2][attaquexJ2][J1]=='3')
            {
                vie[J1][2]=vie[J1][2]-1;
                map[attaqueyJ2][attaquexJ2][J1]='*';
                printf("attaque du joueur 2 reussi en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
                pointVie(vie);
            }
            else if(map[attaqueyJ2][attaquexJ2][J1]=='4')
            {
                vie[J1][3]=vie[J1][3]-1;
                map[attaqueyJ2][attaquexJ2][J1]='*';
                printf("attaque du joueur 2 reussi en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
                pointVie(vie);
            }
            else if (map[attaqueyJ2][attaquexJ2][J1]=='0')
            {
                map[attaqueyJ2][attaquexJ2][J1]='.';
            }

            if(vie[J1][0]>0 || vie[J1][1]>0 || vie[J1][2]>0 || vie[J1][3]>0)
            {
//Attaque du joueur 1 sur la carte du joueur 2 (c'est la carte map[a][a][0])
                do
                {
                    attaqueyJ1 = doRand(0,YM+1);
                    attaquexJ1 = doRand(0,XM+1);
                }
                while(map[attaqueyJ1][attaquexJ1][J2]=='.' || map[attaqueyJ1][attaquexJ1][J2]=='*'); // Boucle pour éviter de tirer plusieur fois au même endroit.


                if(map[attaqueyJ1][attaquexJ1][J2]=='1')
                {
                    vie[J2][0]=vie[J2][0]-1;
                    map[attaqueyJ1][attaquexJ1][J2]='*';
                    printf("attaque du joueur 2 reussi en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
                    pointVie(vie);
                }
                else if(map[attaqueyJ1][attaquexJ1][J2]=='2')
                {
                    vie[J2][1]=vie[J2][1]-1;
                    map[attaqueyJ1][attaquexJ1][J2]='*';
                    printf("attaque du joueur 2 reussi en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
                    pointVie(vie);
                }
                else if(map[attaqueyJ1][attaquexJ1][J2]=='3')
                {
                    vie[J2][2]=vie[J2][2]-1;
                    map[attaqueyJ1][attaquexJ1][J2]='*';
                    printf("attaque du joueur 2 reussi en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
                    pointVie(vie);
                }
                else if(map[attaqueyJ1][attaquexJ1][J2]=='4')
                {
                    vie[J2][3]=vie[J2][3]-1;
                    map[attaqueyJ1][attaquexJ1][J2]='*';
                    printf("attaque du joueur 2 reussi en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
                    pointVie(vie);
                }

                else if (map[attaqueyJ1][attaquexJ1][J2]=='0')
                {
                    map[attaqueyJ1][attaquexJ1][J2]='.';
                }
            }
            else{}
        }

        printMap(map,J1);
        printMap(map,J2);

        pointVie(vie);

        if(vie[J1][0]==0 && vie[J1][1]==0 && vie[J1][2]==0 && vie[J1][3]==0)
        {
            printf("###############################################\n");
            printf("#                                             #\n");
            printf("#            Le joueur 2 a gagner!!           #\n");
            printf("#                                             #\n");
            printf("###############################################\n");
        }
        else if(vie[J2][0]==0 && vie[J2][1]==0 && vie[J2][2]==0 && vie[J2][3]==0)
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
//positionement des bateauy

//pour joueur 1

    bateau1Real(map,J1,vie);

    bateau2Real(map,J1,vie);

    bateau3Real(map,J1,vie);
    bateau3Real(map,J1,vie);

    bateau4Real(map,J1,vie);
    bateau4Real(map,J1,vie);

        //pour joueur 2 IA
    bateau1(map,J2,vie);

    bateau2(map,J2,vie);

    bateau3(map,J2,vie);
    bateau3(map,J2,vie);

    bateau4(map,J2,vie);
    bateau4(map,J2,vie);

//Carte joueur 1 avec bateauy
    printf("\nPoint de sauvegarde!\n");
    write(map, vie);
    printMap(map,J1);


 // IA Attaque  sur la carte du joueur 1 (c'est la carte map[i][j][1])
        while((vie[J1][0]>0 || vie[J1][1]>0 || vie[J1][2]>0 || vie[J2][3]>0) && (vie[J2][0]>0 || vie[J2][1]>0 || vie[J2][2]>0 || vie[J2][3]>0))  //Boucle jusqu'à ce que l'un des 2 joueur n'as plus de bateau en vie
        {
            do
            {
                attaqueyJ2 = doRand(0,YM+1);
                attaquexJ2 = doRand(0,XM+1);
            }
            while(map[attaqueyJ2][attaquexJ2][J1]=='.' || map[attaqueyJ2][attaquexJ2][J1]=='*');  // Boucle pour éviter de tirer plusieur fois au même endroit.

            if(map[attaqueyJ2][attaquexJ2][J1]=='1')
            {
                vie[J1][0]=vie[J1][0]-1;
                map[attaqueyJ2][attaquexJ2][J1]='*';
                printf("IA touche votre bateau 1 en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
            }
            else if(map[attaqueyJ2][attaquexJ2][J1]=='2')
            {
                vie[J1][1]=vie[J1][1]-1;
                map[attaqueyJ2][attaquexJ2][J1]='*';
                printf("IA touche votre bateau 2 en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
            }
            else if(map[attaqueyJ2][attaquexJ2][J1]=='3')
            {
                vie[J1][2]=vie[J1][2]-1;
                map[attaqueyJ2][attaquexJ2][J1]='*';
                printf("IA touche votre bateau 3 en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
            }
            else if(map[attaqueyJ2][attaquexJ2][J1]=='4')
            {
                vie[J1][3]=vie[J1][3]-1;
                map[attaqueyJ2][attaquexJ2][J1]='*';
                printf("IA touche votre bateau 4 en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
            }
            else if (map[attaqueyJ2][attaquexJ2][J1]=='0')
            {
                map[attaqueyJ2][attaquexJ2][J1]='.';
                printf("IA loupe y:%d x:%d\n", attaqueyJ2, attaquexJ2);
            }

            if(vie[J1][0]>0 || vie[J1][1]>0 || vie[J1][2]>0 || vie[J2][3]>0)
            {

//Attaque du joueur 1 sur la carte de L'IA (J2), La carte visible est map[][][IAVSJ
                do
                {
                    do
                    {
                        do
                        {
                            printf("Choisisez la position vertical(y) de votre attaque la position doit etre comprise entre 0 et %d :\n", YM-1);
                            testScanf = scanf("%d", &attaqueyJ1);
                            if(attaqueyJ1>YM-1 || attaqueyJ1<0 || testScanf != 1)
                            {
                                printf("Il faut un nombre entre 0 et %d \n", YM-1);
                            }
                            purge();
                        }
                        while(testScanf != 1);
                    }
                    while(attaqueyJ1>YM-1 || attaqueyJ1<0);
                    do
                    {
                        do
                        {
                            printf("Choisisez la position horizontal(x) de votre attaque la position doit etre comprise entre 0 et %d :\n", XM-1);
                            testScanf = scanf("%d", &attaquexJ1);
                            if(attaquexJ1>XM-1 || attaquexJ1<0 || testScanf != 1)
                            {
                                printf("Il faut un nombre entre 0 et %d \n", XM-1);
                            }
                            purge();
                        }
                        while(testScanf != 1);
                    }
                    while(attaquexJ1>XM-1 || attaquexJ1<0);

                    if(map[attaqueyJ1][attaquexJ1][J2]=='*')
                    {
                        printf("Votre attaque est en y: %d et x: %d\n", attaqueyJ1, attaquexJ1);
                        printf("Vous avez deja attaque ici! \n Vous aviez touche, vous pouvez recommencer votre attaque \n");
                    }
                    else if(map[attaqueyJ1][attaquexJ1][J2]=='.')
                    {
                        printf("Votre attaque est en y: %d et x: %d\n", attaqueyJ1, attaquexJ1);
                        printf("Vous avez deja attaque ici! \n Vous aviez loupe, vous pouvez recommencer votre attaque \n");
                    }
                }
                while(map[attaqueyJ1][attaquexJ1][J2]=='.' || map[attaqueyJ1][attaquexJ1][J2]=='*'); // Boucle pour éviter de tirer plusieur fois au même endroit.

                if(map[attaqueyJ1][attaquexJ1][J2]=='1')
                {
                    vie[J2][0]=vie[J2][0]-1;
                    map[attaqueyJ1][attaquexJ1][IAVSJ]='*';
                    map[attaqueyJ1][attaquexJ1][J2]='*';
                    printf("Votre attaque a reussi en y:%d x:%d \n", attaqueyJ2, attaquexJ2);
                    if(vie[J2][0]==0)
                        {
                            printf("Bateau 1 coule \n");
                        }
                }
                else if(map[attaqueyJ1][attaquexJ1][J2]=='2')
                {
                    vie[J2][1]=vie[J2][1]-1;
                    map[attaqueyJ1][attaquexJ1][IAVSJ]='*';
                    map[attaqueyJ1][attaquexJ1][J2]='*';
                    printf("Votre attaque a reussi en y:%d x:%d \n", attaqueyJ2, attaquexJ2);
                    if(vie[J2][1]==0)
                        {
                            printf("Bateau 2 coule \n");
                        }
                }
                else if(map[attaqueyJ1][attaquexJ1][J2]=='3')
                {
                    vie[J2][2]=vie[J2][2]-1;
                    map[attaqueyJ1][attaquexJ1][IAVSJ]='*';
                    map[attaqueyJ1][attaquexJ1][J2]='*';
                    printf("Votre attaque a reussi en y:%d x:%d \n", attaqueyJ2, attaquexJ2);
                    if(vie[J2][2]==0)
                        {
                            printf("Bateau 3 coule \n");
                        }
                }
                else if(map[attaqueyJ1][attaquexJ1][J2]=='4')
                {
                    vie[J2][3]=vie[J2][3]-1;
                    map[attaqueyJ1][attaquexJ1][IAVSJ]='*';
                    map[attaqueyJ1][attaquexJ1][J2]='*';
                    printf("Votre attaque a reussi en y:%d x:%d \n", attaqueyJ2, attaquexJ2);
                    if(vie[J2][3]==0)
                        {
                            printf("Bateau 4 coule \n");
                        }
                }

                else if (map[attaqueyJ1][attaquexJ1][J2]=='0')
                {
                    map[attaqueyJ1][attaquexJ1][IAVSJ]='.';
                    map[attaqueyJ1][attaquexJ1][J2]='.';
                    printf("Votre attaque a loupe en y:%d x:%d \n", attaqueyJ1, attaquexJ1);
                }
            }
            else{}
            printf("Point de sauvegarde! \n");
            write(map, vie);
        }
        printMap(map,J1);
        printMap(map,IAVSJ);
        printMap(map,J2); //Verification

        pointVie(vie);

        if(vie[J1][0]==0 && vie[J1][1]==0 && vie[J1][2]==0 && vie[J1][3]==0)
        {
            printf("###############################################\n");
            printf("#                                             #\n");
            printf("#            Le joueur 2 a gagner!!           #\n");
            printf("#                                             #\n");
            printf("###############################################\n");
        }
        else if(vie[J2][0]==0 && vie[J2][1]==0 && vie[J2][2]==0 && vie[J2][3]==0)
        {
            printf("###############################################\n");
            printf("#                                             #\n");
            printf("#            Le joueur 1 a gagner!!           #\n");
            printf("#                                             #\n");
            printf("###############################################\n");
        }
        break;

        case 3:

            filerRead(map, vie);
            printMap(map,J1);
            printMap(map,IAVSJ);
            printMap(map,J2); //Verification
           // IA Attaque  sur la carte du joueur 1 (c'est la carte map[i][j][1])
        while((vie[J1][0]>0 || vie[J1][1]>0 || vie[J1][2]>0 || vie[J2][3]>0) && (vie[J2][0]>0 || vie[J2][1]>0 || vie[J2][2]>0 || vie[J2][3]>0))  //Boucle jusqu'à ce que l'un des 2 joueur n'as plus de bateau en vie
        {
            do
            {
                attaqueyJ2 = doRand(0,YM+1);
                attaquexJ2 = doRand(0,XM+1);
            }
            while(map[attaqueyJ2][attaquexJ2][J1]=='.' || map[attaqueyJ2][attaquexJ2][J1]=='*');  // Boucle pour éviter de tirer plusieur fois au même endroit.

            if(map[attaqueyJ2][attaquexJ2][J1]=='1')
            {
                vie[J1][0]=vie[J1][0]-1;
                map[attaqueyJ2][attaquexJ2][J1]='*';
                printf("IA touche votre bateau 1 en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
            }
            else if(map[attaqueyJ2][attaquexJ2][J1]=='2')
            {
                vie[J1][1]=vie[J1][1]-1;
                map[attaqueyJ2][attaquexJ2][J1]='*';
                printf("IA touche votre bateau 2 en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
            }
            else if(map[attaqueyJ2][attaquexJ2][J1]=='3')
            {
                vie[J1][2]=vie[J1][2]-1;
                map[attaqueyJ2][attaquexJ2][J1]='*';
                printf("IA touche votre bateau 3 en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
            }
            else if(map[attaqueyJ2][attaquexJ2][J1]=='4')
            {
                vie[J1][3]=vie[J1][3]-1;
                map[attaqueyJ2][attaquexJ2][J1]='*';
                printf("IA touche votre bateau 4 en y:%d x:%d\n", attaqueyJ2, attaquexJ2);
            }
            else if (map[attaqueyJ2][attaquexJ2][J1]=='0')
            {
                map[attaqueyJ2][attaquexJ2][J1]='.';
                printf("IA loupe y:%d x:%d\n", attaqueyJ2, attaquexJ2);
            }

            if(vie[J1][0]>0 || vie[J1][1]>0 || vie[J1][2]>0 || vie[J2][3]>0)
            {

//Attaque du joueur 1 sur la carte de L'IA (J2), La carte visible est map[][][IAVSJ
                do
                {
                    do
                    {
                        do
                        {
                            printf("Choisisez la position vertical(y) de votre attaque la position doit etre comprise entre 0 et %d :\n", YM-1);
                            testScanf = scanf("%d", &attaqueyJ1);
                            if(attaqueyJ1>YM-1 || attaqueyJ1<0 || testScanf != 1)
                            {
                                printf("Il faut un nombre entre 0 et %d \n", YM-1);
                            }
                            purge();
                        }
                        while(testScanf != 1);
                    }
                    while(attaqueyJ1>YM-1 || attaqueyJ1<0);
                    do
                    {
                        do
                        {
                            printf("Choisisez la position horizontal(x) de votre attaque la position doit etre comprise entre 0 et %d :\n", XM-1);
                            testScanf = scanf("%d", &attaquexJ1);
                            if(attaquexJ1>XM-1 || attaquexJ1<0 || testScanf != 1)
                            {
                                printf("Il faut un nombre entre 0 et %d \n", XM-1);
                            }
                            purge();
                        }
                        while(testScanf != 1);
                    }
                    while(attaquexJ1>XM-1 || attaquexJ1<0);

                    if(map[attaqueyJ1][attaquexJ1][J2]=='*')
                    {
                        printf("Votre attaque est en y: %d et x: %d\n", attaqueyJ1, attaquexJ1);
                        printf("Vous avez deja attaque ici! \n Vous aviez touche, vous pouvez recommencer votre attaque \n");
                    }
                    else if(map[attaqueyJ1][attaquexJ1][J2]=='.')
                    {
                        printf("Votre attaque est en y: %d et x: %d\n", attaqueyJ1, attaquexJ1);
                        printf("Vous avez deja attaque ici! \n Vous aviez loupe, vous pouvez recommencer votre attaque \n");
                    }
                }
                while(map[attaqueyJ1][attaquexJ1][J2]=='.' || map[attaqueyJ1][attaquexJ1][J2]=='*'); // Boucle pour éviter de tirer plusieur fois au même endroit.

                if(map[attaqueyJ1][attaquexJ1][J2]=='1')
                {
                    vie[J2][0]=vie[J2][0]-1;
                    map[attaqueyJ1][attaquexJ1][IAVSJ]='*';
                    map[attaqueyJ1][attaquexJ1][J2]='*';
                    printf("Votre attaque a reussi en y:%d x:%d \n", attaqueyJ2, attaquexJ2);
                    if(vie[J2][0]==0)
                        {
                            printf("Bateau 1 coule \n");
                        }
                }
                else if(map[attaqueyJ1][attaquexJ1][J2]=='2')
                {
                    vie[J2][1]=vie[J2][1]-1;
                    map[attaqueyJ1][attaquexJ1][IAVSJ]='*';
                    map[attaqueyJ1][attaquexJ1][J2]='*';
                    printf("Votre attaque a reussi en y:%d x:%d \n", attaqueyJ2, attaquexJ2);
                    if(vie[J2][1]==0)
                        {
                            printf("Bateau 2 coule \n");
                        }
                }
                else if(map[attaqueyJ1][attaquexJ1][J2]=='3')
                {
                    vie[J2][2]=vie[J2][2]-1;
                    map[attaqueyJ1][attaquexJ1][IAVSJ]='*';
                    map[attaqueyJ1][attaquexJ1][J2]='*';
                    printf("Votre attaque a reussi en y:%d x:%d \n", attaqueyJ2, attaquexJ2);
                    if(vie[J2][2]==0)
                        {
                            printf("Bateau 3 coule \n");
                        }
                }
                else if(map[attaqueyJ1][attaquexJ1][J2]=='4')
                {
                    vie[J2][3]=vie[J2][3]-1;
                    map[attaqueyJ1][attaquexJ1][IAVSJ]='*';
                    map[attaqueyJ1][attaquexJ1][J2]='*';
                    printf("Votre attaque a reussi en y:%d x:%d \n", attaqueyJ2, attaquexJ2);
                    if(vie[J2][3]==0)
                        {
                            printf("Bateau 4 coule \n");
                        }
                }

                else if (map[attaqueyJ1][attaquexJ1][J2]=='0')
                {
                    map[attaqueyJ1][attaquexJ1][IAVSJ]='.';
                    map[attaqueyJ1][attaquexJ1][J2]='.';
                    printf("Votre attaque a loupe en y:%d x:%d \n", attaqueyJ1, attaquexJ1);
                }
            }
            else{}
            printf("Point de sauvegarde! \n");
            write(map, vie);
        }
        printMap(map,J1);
        printMap(map,IAVSJ);
        printMap(map,J2); //Verification

        pointVie(vie);

        if(vie[J1][0]==0 && vie[J1][1]==0 && vie[J1][2]==0 && vie[J1][3]==0)
        {
            printf("###############################################\n");
            printf("#                                             #\n");
            printf("#            Le joueur 2 a gagner!!           #\n");
            printf("#                                             #\n");
            printf("###############################################\n");
        }
        else if(vie[J2][0]==0 && vie[J2][1]==0 && vie[J2][2]==0 && vie[J2][3]==0)
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
