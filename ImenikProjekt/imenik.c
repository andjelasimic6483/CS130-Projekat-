#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "imenik.h"

// Referenca na niz definisan u main.c
extern Kontakt imenik[MAX_KONTAKATA];
extern int brojTrenutnihKontakata;

void dodajKontakt() {
    if (brojTrenutnihKontakata >= MAX_KONTAKATA) {
        printf("\nGreska: Kapacitet imenika je popunjen.\n");
        return;
    }
    printf("\n--- Unos podataka ---\n");
    printf("Ime: ");
    (void)scanf("%s", imenik[brojTrenutnihKontakata].ime);
    printf("Prezime: ");
    (void)scanf("%s", imenik[brojTrenutnihKontakata].prezime);
    printf("Broj telefona (bez razmaka): ");
    (void)scanf("%s", imenik[brojTrenutnihKontakata].broj);

    brojTrenutnihKontakata++;
    printf("Uspesno ste dodali kontakt.\n");
}

void prikaziSve() {
    if (brojTrenutnihKontakata == 0) {
        printf("\nImenik je prazan.\n");
        return;
    }
    printf("\n%-15s | %-15s | %-15s\n", "IME", "PREZIME", "BROJ");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < brojTrenutnihKontakata; i++) {
        printf("%-15s | %-15s | %-15s\n", imenik[i].ime, imenik[i].prezime, imenik[i].broj);
    }
}

void pretraziKontakt() {
    char kriterijum[30];
    printf("\nUnesite ime za pretragu: ");
    (void)scanf("%s", kriterijum);

    for (int i = 0; i < brojTrenutnihKontakata; i++) {
        // _stricmp ignorise velika i mala slova (Specificno za Windows/VS)
        if (_stricmp(imenik[i].ime, kriterijum) == 0) {
            printf("Pronadjen: %s %s - Tel: %s\n", imenik[i].ime, imenik[i].prezime, imenik[i].broj);
            return;
        }
    }
    printf("Kontakt nije pronadjen.\n");
}

void obrisiKontakt() {
    char brisanje[30];
    printf("\nUnesite ime kontakta za brisanje: ");
    (void)scanf("%s", brisanje);

    for (int i = 0; i < brojTrenutnihKontakata; i++) {
        if (strcmp(imenik[i].ime, brisanje) == 0) {
            for (int j = i; j < brojTrenutnihKontakata - 1; j++) {
                imenik[j] = imenik[j + 1];
            }
            brojTrenutnihKontakata--;
            printf("Kontakt je uspesno obrisan.\n");
            return;
        }
    }
    printf("Greska: Kontakt nije pronadjen.\n");
}

void sacuvajUFajl() {
    FILE* f = fopen("imenik.txt", "w");
    if (f == NULL) return;
    for (int i = 0; i < brojTrenutnihKontakata; i++) {
        fprintf(f, "%s %s %s\n", imenik[i].ime, imenik[i].prezime, imenik[i].broj);
    }
    fclose(f);
}

void ucitajIzFajla() {
    FILE* f = fopen("imenik.txt", "r");
    if (f == NULL) return; // Ako fajl ne postoji, program samo nastavlja dalje

    while (brojTrenutnihKontakata < MAX_KONTAKATA &&
        fscanf(f, "%s %s %s", imenik[brojTrenutnihKontakata].ime,
            imenik[brojTrenutnihKontakata].prezime,
            imenik[brojTrenutnihKontakata].broj) != EOF) {
        brojTrenutnihKontakata++;
    }
    fclose(f);
} 