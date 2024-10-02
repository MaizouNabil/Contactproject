#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max_string 100
#define max_char 30
#define max_nombres 30

struct contacts {
    char Nom[max_string][max_char];
    char numero[max_string][max_nombres];
    char e_mail[max_string][max_char];
    int id;
};

struct contacts contact = {
    .Nom = {"hassan", "mahjob", "rania", "khalid", "rabi3"},
    .numero = {"0713442474", "06758891920", "06277779", "0612343278", "09664548872"},
    .e_mail = {"johdoe@eXample.com", "saror@sampmail.com", "wonder@@ficti.com", "bob.builder@homemail.com", "charliDown@dommail.com"}
};

int nbr_contact = 4, choix_menu;
char choix[4], recherch[25];


int is_valid_number(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0; 
        }
    }
    return 1; 
}


int is_non_empty(char* str) {
    return strlen(str) > 0;
}


int is_valid_email(char* email) {
    
    return (strchr(email, '@') != NULL && strchr(email, '.') != NULL);
}

void menu() {
    printf("\n******************** MENU Contacts ****************\n");
    printf("*                                                  *\n");
    printf("*     1 - Ajouter un Contact.                      *\n");
    printf("*     2 - Modifier un Contact.                     *\n");
    printf("*     3 - Supprimer un Contact.                    *\n");
    printf("*     4 - Afficher Tous les Contacts.              *\n");
    printf("*     5 - Rechercher un Contact.                   *\n");
    printf("*     6 - Quitter.                                 *\n");
    printf("*                                                  *\n");
    printf("****************************************************\n");
}

void ajouter() {
    do {
        if (nbr_contact >= max_string) {
            printf("Impossible d'ajouter plus de contacts, limite atteinte.\n");
            return;
        }

        getchar();

        
        do {
            printf("Nom: ");
            fgets(contact.Nom[nbr_contact], max_char, stdin);
            contact.Nom[nbr_contact][strcspn(contact.Nom[nbr_contact], "\n")] = 0; // remove newline

            if (!is_non_empty(contact.Nom[nbr_contact])) {
                printf("Erreur: Le nom ne doit pas être vide.\n");
            }
        } while (!is_non_empty(contact.Nom[nbr_contact]));

       
        do {
            printf("Numero: ");
            fgets(contact.numero[nbr_contact], max_nombres, stdin);
            contact.numero[nbr_contact][strcspn(contact.numero[nbr_contact], "\n")] = 0; // remove newline
            
            if (!is_valid_number(contact.numero[nbr_contact])) {
                printf("Erreur: Entrez un numero valide avec uniquement des chiffres.\n");
            }
        } while (!is_valid_number(contact.numero[nbr_contact]));

        
        do {
            printf("E-mail: ");
            fgets(contact.e_mail[nbr_contact], max_char, stdin);
            contact.e_mail[nbr_contact][strcspn(contact.e_mail[nbr_contact], "\n")] = 0; // remove newline

            if (!is_valid_email(contact.e_mail[nbr_contact])) {
                printf("Erreur: Entrez une adresse e-mail valide (doit contenir '@' et '.').\n");
            }
        } while (!is_valid_email(contact.e_mail[nbr_contact]));

        nbr_contact++;

        printf("Ajouter un nouveau contact (oui ou non): ");
        fgets(choix, 4, stdin);
        choix[strcspn(choix, "\n")] = 0;

    } while (strcmp(choix, "oui") == 0);
}

void modifier() {
    getchar();
    printf("Donner le nom de contact: ");
    fgets(recherch, max_char, stdin);
    recherch[strcspn(recherch, "\n")] = 0;

    for (int i = 0; i < nbr_contact; i++) {
        if (strcmp(recherch, contact.Nom[i]) == 0) {

            
            do {
                printf("Numero: ");
                fgets(contact.numero[i], max_nombres, stdin);
                contact.numero[i][strcspn(contact.numero[i], "\n")] = 0; 
                
                if (!is_valid_number(contact.numero[i])) {
                    printf("Erreur: Entrez un numero valide avec uniquement des chiffres.\n");
                }
            } while (!is_valid_number(contact.numero[i]));

        
            do {
                printf("E-mail: ");
                fgets(contact.e_mail[i], max_char, stdin);
                contact.e_mail[i][strcspn(contact.e_mail[i], "\n")] = 0; 
                if (!is_valid_email(contact.e_mail[i])) {
                    printf("Erreur: Entrez une adresse e-mail valide (doit contenir '@' et '.').\n");
                }
            } while (!is_valid_email(contact.e_mail[i]));

            printf("Votre modification a reussi.\n");
            return;
        }
    }
    printf("Le contact %s n'existe pas.\n", recherch);
}

void afficher() {
    for (int i = 0; i < nbr_contact; i++) {
        printf("\n*************** Contact N%d ***********\n", i + 1);
        printf("         Nom: %s\n", contact.Nom[i]);
        printf("         Numero: %s\n", contact.numero[i]);
        printf("         E-mail: %s\n", contact.e_mail[i]);
        printf("         id: %d\n", i + 1);
        printf("\n***************************************\n");
    }
}

void supprimer() {
    getchar();
    printf("Donner le nom de contact: ");
    fgets(recherch, max_char, stdin);
    recherch[strcspn(recherch, "\n")] = 0;

    for (int i = 0; i < nbr_contact; i++) {
        if (strcmp(recherch, contact.Nom[i]) == 0) {
            for (int j = i; j < nbr_contact - 1; j++) {
                strcpy(contact.Nom[j], contact.Nom[j + 1]);
                strcpy(contact.numero[j], contact.numero[j + 1]);
                strcpy(contact.e_mail[j], contact.e_mail[j + 1]);
            }
            printf("%s supprime avec succes.\n", recherch);
            nbr_contact--;
            return;
        }
    }
    printf("[%s] n'existe pas dans les contacts.\n", recherch);
}

void rechercher() {
    getchar();
    printf("Donner le nom de contact: ");
    fgets(recherch, max_char, stdin);
    recherch[strcspn(recherch, "\n")] = 0;

    for (int i = 0; i < nbr_contact; i++) {
        if (strcmp(recherch, contact.Nom[i]) == 0) {
            printf("\n*************** Contact N%d ***********\n", i + 1);
            printf("         Nom: %s\n", contact.Nom[i]);
            printf("         Numero: %s\n", contact.numero[i]);
            printf("         E-mail: %s\n", contact.e_mail[i]);
            printf("         id: %d\n", i + 1);
            printf("\n***************************************\n");
            return;
        }
    }
    printf("[%s] n'existe pas dans les contacts.\n", recherch);
}


int main() {
    do {
        menu();
        printf("Entrez votre choix: ");
        scanf("%d", &choix_menu);

        switch (choix_menu) {
            case 1:
                ajouter();
                break;
            case 2:
                modifier();
                break;
            case 3:
                supprimer();
                break;
            case 4:
                afficher();
                break;
            case 5:
                rechercher();
                break;
            
            case 6:
                printf("Quitter le programme.\n");
                exit(0);
                break;
            default:
                printf("Choix non valide, essayez encore.\n");
                break;
        }
    } while (1);

    return 0;
}
