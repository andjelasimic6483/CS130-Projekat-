#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "imenik.h"

// Inicijalizacija globalnih podataka
Kontakt imenik[MAX_KONTAKATA];
int brojTrenutnihKontakata = 0;

int main() {
    int izbor = 0;
    int c;

    ucitajIzFajla(); // Automatsko ucitavanje podataka

    do {
        printf("\n======= TELEFONSKI IMENIK =======\n");
        printf("1. Dodaj novi kontakt\n");
        printf("2. Prikazi listu svih kontakata\n");
        printf("3. Pronadji kontakt po imenu\n");
        printf("4. Izbrisi postojeci kontakt\n");
        printf("5. Sacuvaj i zatvori program\n");
        printf("==================================\n");
        printf("Vas izbor: ");

        if (scanf("%d", &izbor) != 1) {
            printf("\nGreska: Dozvoljen je samo unos cifara.\n");
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        // Ciscenje bafera za stabilan rad menija
        while ((c = getchar()) != '\n' && c != EOF);

        switch (izbor) {
        case 1: dodajKontakt(); break;
        case 2: prikaziSve(); break;
        case 3: pretraziKontakt(); break;
        case 4: obrisiKontakt(); break;
        case 5:
            sacuvajUFajl();
            printf("\nSvi podaci su sacuvani. Kraj rada.\n");
            break;
        default: printf("\nOpcija %d ne postoji.\n", izbor);
        }
    } while (izbor != 5);

    return 0;
}