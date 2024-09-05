
# include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef  struct Contacts
{
    char Nom [100];
    char Numéro [100];
    char Adresse [100];
}Contact_t;


void    ajouter( Contact_t contact[100], int count);
void    afficher(Contact_t Contact[100], int count);
void    Rechercher (Contact_t Contact[100],char stre[],int count);
void    update(Contact_t Contact[100], char stre[],int count);
void    Supprimer (Contact_t Contact[100], char stre[],int count);
void    afich();

int main ()
{
    Contact_t contact[100];
    char stre[100];
    int count = 0;
    int choix;

  while(1){
        afich();
        printf("Entee votre choix: ");
        scanf("%d", &choix);
        system("cls");
        switch (choix) {
            case 1:
               ajouter( contact, count);
                count++;
                break;
            case 2:
                afficher(contact, count);
                break;
            case 3:
                printf("Enter the Nom : ");
                scanf("%s", stre);
                update(contact,stre,count);
                break;
            case 4:
                printf("Enter the Nom  to Supprimer: ");
                scanf("%s", stre);
                Supprimer(contact,stre,count);
                count--;
                break;
            case 5:
                char stre[100];
                printf("Enter the Nom Rechercher : ");
                scanf("%s", stre);
                Rechercher(contact,stre,count);
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


void  ajouter(Contact_t Contact[100],  int count) 
{
    printf("\n/==============================Afficher Tous les Contact====================================/\n");
    printf ("Nom  : ");
    scanf ("%s", &Contact[count].Nom);
    printf ("Numero  : ");
    scanf ("%s", &Contact[count].Numéro);
    printf ("Adresse  : ");
    scanf ("%s", &Contact[count].Adresse);


}

void  afficher(Contact_t Contact[100], int count) 
{
    printf("/==============================Afficher Tous les Contact====================================/\n");
    for (int i = 0; i < count; i++)
    {
        printf ("\n|-------------------------------------|\n");
        printf ("Nom      : %s\n",Contact[i].Nom);
        printf ("Numero   : %s\n",Contact[i].Numéro);
        printf ("Adresse  : %s\n",Contact[i].Adresse);

    }
}

void Rechercher (Contact_t Contact[100],char stre[],int count)
{
    printf("/==============================Rechercher Contact====================================/\n\n");
      int r = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(Contact[i].Nom,stre) == 0)
        {
            printf ("\n|-------------------------------------|\n");
            printf ("Nom      : %s\n",Contact[i].Nom);
            printf ("Numero   : %s\n",Contact[i].Numéro);
            printf ("Adresse  : %s\n",Contact[i].Adresse);
            r++;    
        }
    }
    if (r == 0)
    {
        printf("no contact\n");
    }

}

void update(Contact_t Contact[100],char stre[],int count)
{
    printf("/==============================update  Contact====================================/\n");
    int r = 0;
    char stri[100];
    for (int i = 0; i < count; i++)
    {
        if (strcmp(Contact[i].Nom ,stre) == 0)
        {
            printf ("Nom  : ");
             scanf ("%s", &Contact[i].Nom);
            printf ("Numero  : ");
            scanf ("%s", &Contact[i].Numéro);
            printf ("Adresse  : ");
            scanf ("%s", &Contact[i].Adresse);
            r++;    
        }
    }
    if (r == 0)
    {
        printf("no contact\n");
    }
    
 
}


void Supprimer (Contact_t Contact[100], char stre[],int count)
{  
    int i, j,s;
    s = 0;
    for (i = 0; i < count; i++) {
        if (strcmp(Contact[i].Nom, stre) == 0) {
            for (j = i; j < count - 1; j++) {
                s = 1;
                printf("\nyes to suprime\n");
                strcpy(Contact[j].Nom, Contact[j + 1].Nom);
                strcpy(Contact[j].Numéro,Contact[j+1].Numéro);
                strcpy(Contact[j].Adresse,Contact[j + 1].Adresse);
            }
            break;
        }
    }
    if (s == 0)
    {
        printf("\nno de suprm\n");
    }
}
