# include <stdio.h>
#include <string.h>
#include <stdlib.h>

void    ajouter(char Nom [][100], char Numéro [][100], char Adresse[][100], int count);
void    afficher(char Nom [][100], char Numéro [][100], char Adresse[][100], int count);
void    Rechercher (char Nom [][100], char Numéro [][100], char Adresse[][100],char stre[],int count);
void    update(char Nom [][100], char Numéro [][100], char Adresse[][100], char stre[],int count);
void    Supprimer (char Nom [][100], char Numéro [][100], char Adresse[][100], char stre[],int count);
void    afich();

int main ()
{
    int count = 0;
    char Nom [10][100];
    char Numéro [10][100];
    char Adresse [10][100];
    int choix;

  while(1){
        afich();
        printf("Entee votre choix: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                ajouter(Nom , Numéro , Adresse , count);
                count++;
                break;
            case 2:
                afficher(Nom , Numéro , Adresse , count);
                break;
            case 3:
                char word[100];
                printf("Enter the Nom : ");
                scanf("%s", word);
                update(Nom , Numéro , Adresse , word, count);
                break;
            case 4:
                char mot[100];
                printf("Enter the Nom  to Supprimer: ");
                scanf("%s", mot);
                Supprimer(Nom  ,Numéro , Adresse , mot, count);
                count--;
                break;
            case 5:
                char stre[100];
                printf("Enter the Nom : ");
                scanf("%s", stre);
                Rechercher(Nom  ,Numéro ,Adresse , stre, count);
                break;
            case  0:
                printf("sorti");
                exit(0);
            default:
                printf("Default!");
        }
    }
}

void afich()
{
    printf("/==============================ENTER NUMERO====================================/\n");
    printf("             1 => ajouter       \t");
    printf("             2 => afficher \t\n");
    printf("             3 => update        \t");
    printf("             4 => Supprimer \t\n");
    printf("             5 => Rechercher    \t");
    printf("             0 => ext \t\n");
    printf("/============================================================================/\n");
}


void  ajouter(char Nom [][100], char Numéro [][100], char Adresse[][100],  int count) 
{
    printf ("Nom  : ");
    scanf ("%s", &Nom [count]);
    printf ("Numero  : ");
    scanf ("%s", &Numéro [count]);
    printf ("Adresse  : ");
    scanf ("%s", &Adresse [count]);

}

void  afficher(char Nom [][100], char Numéro [][100], char Adresse[][100], int count) 
{
    printf("/==============================Afficher Tous les Contacts====================================/\n");
    for (int i = 0; i < count; i++)
    {
        printf ("\n|-------------------------------------|\n");
        printf ("Nom      : %s\n",Nom [i]);
        printf ("Numero   : %s\n",Numéro [i]);
        printf ("Adresse  : %s\n",Adresse [i]);

    }
}

void Rechercher (char Nom [][100], char Numéro [][100], char Adresse[][100],char stre[],int count)
{
    printf("/==============================Rechercher Contacts====================================/\n");
    int r = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(Nom [i] ,stre) == 0)
        {
            printf ("\n|-------------------------------------|\n");
            printf ("Nom   : %s\n",Nom [i] );
            printf ("Numero   : %s\n",Numéro [i] );
            printf ("Adresse   : %s\n",Adresse [i] );
            r++;    
        }
    }
    if (r == 0)
    {
        printf("no contact\n");
    }
}

void update(char Nom [][100], char Numéro [][100], char Adresse[][100],char stre[],int count)
{
    printf("/==============================update  Contacts====================================/\n");
    int r = 0;
    int n;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(Nom [i] ,stre) == 0)
        {
           
            printf ("Nom  : ");
            scanf ("%s", &Nom [i]);
            printf ("Numero  : ");
            scanf ("%s", &Numéro [i]);
            printf ("Adresse  : ");
            scanf ("%s", &Adresse [i]);
            r = 1;
        }
    }
    if (r == 0)
    {
        printf("no ajoute name");
    }
    
 
}


void Supprimer (char Nom [][100], char Numéro [][100], char Adresse[][100], char stre[],int count)
{
    int i, j,sprm;
    sprm = 0;
    for (i = 0; i < count; i++) {
        if (strcmp(Nom [i], stre) == 0) {
            for (j = i; j < count - 1; j++) {
                printf("\nyes to suprime\n");
                strcpy(Nom [j], Nom [j + 1]);
                strcpy(Numéro [j], Numéro [j + 1]);
                strcpy(Adresse [j], Adresse [j + 1]);
                sprm++;
            }
            break;
        }
    }
    if (sprm == 0)
    {
        printf("\nno de suprm\n");
    }
    
}