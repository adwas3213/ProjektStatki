//
// Created by Adam on 27.12.2020.
//
#ifndef PROJEKT_STATKI_WALKA_H
#define PROJEKT_STATKI_WALKA_H
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Gracz.h"
class Gracz;
class Walka
        {
       friend Gracz;
       stringstream nazwa_symulacji;
         int ile_bylo_ruchow;
private:
            void wypisywanie_informacji_o_mozliwosci_wyjscia_lub_zapisu();
            void status_strzalu_wypisywanie(int status,pair<int,int>&strzal,Gracz &atakowany,Gracz &aktualny);
        public:
            Walka();
            Walka(Gracz &gracz1,Gracz &gracz2);
            void gracz_vs_gracz (Gracz &Gracz_nr_1,Gracz &Gracz_nr_2);
            pair<int,int> wczytaj_ruch(string ruch,string &kto);
            void gracz_vs_gracz_z_trackerem(Gracz & Gracz_nr_1,Gracz & Gracz_nr_2);
            void tracker(Gracz & Gracz_nr_1,pair<int,int>);
    stringstream nazwa_pliku_symulacja(Gracz &gracz1,Gracz &gracz2);
    void
    pomocnicze_sprawdzanie_bledu_wejscia(pair<int, int> &atak, Gracz &atakowany, Gracz &aktualny,
                                         bool &czy_pasuje_kolejke);
    void pomocnicze_sprawdzanie_bledu_wejscia_z_tacker(pair<int, int> &atak, Gracz &atakowany, Gracz &aktualny);
    void
    status_strzalu_wypisywanie_z_trackerem(int status, pair<int, int> &gdzie_strzelano, Gracz &atakowany,
                                           Gracz &aktualny);
    void symulacja(Gracz &gracz1,Gracz &gracz2);
        };
#endif //PROJEKT_STATKI_WALKA_H
