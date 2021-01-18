#include "Czesc_grywalna/Gracz.h"
#include "Czesc_grywalna/Walka.h"



void wczytywanie_gracz_vs_gracz()
{
    cout<<endl<<"Podaj nazwe gracza "<<endl;
    string imie_gracza1,imie_gracza2;
    cin>>imie_gracza1;
    Gracz gracz(imie_gracza1);
    cout<<endl<<"Podaj imie drugiego gracza "<<endl;
    cin>>imie_gracza2;
    Gracz gracz2(imie_gracza2);
   bool czy_jest_zapis_dla_pierwszego_gracza= gracz.wczytanie_z_pliku(gracz2);
   bool czy_jest_zapis_dla_drugiego_gracza= gracz2.wczytanie_z_pliku(gracz);
    Walka walka;
    if(czy_jest_zapis_dla_drugiego_gracza&&czy_jest_zapis_dla_pierwszego_gracza) {


        walka.gracz_vs_gracz(gracz, gracz2);
    }
    if (!czy_jest_zapis_dla_pierwszego_gracza)
    {
        gracz=Gracz();

    }
    if(!czy_jest_zapis_dla_drugiego_gracza)
    {
        gracz2=Gracz();

    }
    walka.gracz_vs_gracz(gracz,gracz2);

}
void stworz_nowa_gre_gracz_vs_gracz()
{
    Gracz gracz1;
    Gracz gracz2;
    Walka test;
    test.gracz_vs_gracz(gracz1,gracz2);

}
void stworz_nowa_gre_gracz_vs_gracz_z_trackerem()
{
    Gracz Gracz_nr_1;
    Gracz Gracz_nr_2;
    Walka walka_z_trackerem(Gracz_nr_1,Gracz_nr_2);
    walka_z_trackerem.gracz_vs_gracz_z_trackerem(Gracz_nr_1,Gracz_nr_2);


}
void odtworz_symulacje()
{
    cout<<"Podaj miedzy kim a kim ma zostac  odtworzona symulacja ";
    string imie_gracza_nr_1;
    string imie_gracza_nr_2;
    cout<<"Podaj imie pierwszego gracza ";
    cin>>imie_gracza_nr_1;
    cout<<endl<<"Podaj imie  drugiego gracza ";
    cin>>imie_gracza_nr_2;
    Gracz Gracz_nr_1(imie_gracza_nr_1);
    Gracz Gracz_nr_2(imie_gracza_nr_2);
    Gracz_nr_1.wczytanie_z_pliku(Gracz_nr_2);
    Gracz_nr_2.wczytanie_z_pliku(Gracz_nr_1);
    Walka symulacja(Gracz_nr_1,Gracz_nr_2);
    symulacja.symulacja(Gracz_nr_1,Gracz_nr_2);
}
int main() {
int wybor;
cout<<"Witaj w grze statki zrobionej przez Adama Wasylewicza i Dawida Wolkowicza"<<endl;
cout<<"By stworzyc nowa gre gracz vs gracz wpisz 1 "<<endl;
cout<<"By wczytac gre gracz vs gracz wpisz 2 "<<endl;
cout<<"Jesli chcesz zrobic gre z trackerem daj 3 "<<endl;
cout<<"A jesli chcesz odtworzyc symulacje bitwy daj 4"<<endl;
cin>>wybor;

switch(wybor)
{
    case 1 :
    {
        stworz_nowa_gre_gracz_vs_gracz();
        break;
    }
    case 2 :
    {
        wczytywanie_gracz_vs_gracz();
        break;

    }
    case 3:
    {
        stworz_nowa_gre_gracz_vs_gracz_z_trackerem();
        break;
    }
    case 4:
    {
        odtworz_symulacje();
        break;
    }
    defalut :
    {
        cout<<"Wczytales niepoprawna liczbe . Tym razem wpisz dobra ";
        main();
    };
}


    return 0;
}
