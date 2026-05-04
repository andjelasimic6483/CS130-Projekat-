#ifndef IMENIK_H
#define IMENIK_H

#define MAX_KONTAKATA 100

// Struktura koja opisuje jedan kontakt
typedef struct {
    char ime[30];
    char prezime[30];
    char broj[20];
} Kontakt;

// Deklaracije funkcija
void dodajKontakt();
void prikaziSve();
void pretraziKontakt();
void obrisiKontakt();
void sacuvajUFajl();
void ucitajIzFajla();

#endif