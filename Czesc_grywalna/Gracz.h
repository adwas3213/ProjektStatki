//
// Created by Adam on 21.12.2020.
//
#ifndef PROJEKT_STATKI_GRACZ_H
#define PROJEKT_STATKI_GRACZ_H
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <utility>
#include <fstream>
#include <sstream>
#include <random>

using namespace std;

 class  Gracz
        {
        protected:

        vector<vector<int>> m_tablica ;
       int ilosc_dwu_kratkowych;
       int ilosc_trzy_kratkowych;
       int ilosc_cztero_kratkowych;
       int ilosc_piecio_kratkowych ;
        int ile_statkow_aktualnie;
        void czesc_techniczna(pair<int,int> poczatek,pair<int,int> koniec,pair<int,int> delta,int jaki_typ_tego_statku_jest);
     static char interpreter(int miejsce_w_tablicy);
       void wypisywanie_pomocnicze_dla_ustaw_statki();
     void wypisywanie_tablicy();
        public:
        Gracz();
        Gracz(string);
        string imie;
         int get_rozmiar_tablicy_pion();
         int get_rozmiar_tablicy_poziom();
     void wypisywanie_zinterpretowanej_tablicy(bool tryb_bitewny);
     void wypisywanie_zinterpretowanej_tablicy_wojenne();
    char interpreter_wojenny(int wartosc);
     void ustaw_statki();
    void ustawiam_statki();
     void wypisywanie_tablicy(vector<vector<int>> tablica);
     short otrzymaj_strzal(pair<int,int>);
    int ilosc_plywajacych_czesci();
    void zapis_do_pliku_swojej_tablicy(Gracz &gracz2);
    void ustawiam_losowo_statki();
    void ustaw_losowo_statki();
      char interpreter(int miejsce_w_tablicy, bool tryb_bitewny);
    bool wczytanie_z_pliku(Gracz &oponent);
};
#endif //PROJEKT_STATKI_GRACZ_H
