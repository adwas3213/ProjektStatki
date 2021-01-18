//
// Created by Adam on 27.12.2020.
//

#include "Walka.h"

void Walka::gracz_vs_gracz_z_trackerem(Gracz &Gracz_nr_1, Gracz &Gracz_nr_2)
{
    int zycia_gracza_nr_1=Gracz_nr_1.ilosc_plywajacych_czesci();
    int zycia_gracza_nr_2=Gracz_nr_2.ilosc_plywajacych_czesci();
    Gracz_nr_1.zapis_do_pliku_swojej_tablicy(Gracz_nr_2);
    Gracz_nr_2.zapis_do_pliku_swojej_tablicy(Gracz_nr_1);

// warunek się nie wypisuje
// pamiętać nie zapisywać gdy gra jest trakerowana

    while((zycia_gracza_nr_1=Gracz_nr_1.ilosc_plywajacych_czesci()) != 0
          && (zycia_gracza_nr_2=Gracz_nr_2.ilosc_plywajacych_czesci() )!= 0){
        pair<int,int>ruch_gr_1;
        pair<int,int>ruch_gr_2;

        int status=0;
        if(ile_bylo_ruchow%10 == 0)
        {
            wypisywanie_informacji_o_mozliwosci_wyjscia_lub_zapisu();
        }
        cout<<endl<<"Gracz "<<Gracz_nr_1.imie<<" wykonuje swoj ruch "<<endl;
        Gracz_nr_2.wypisywanie_zinterpretowanej_tablicy_wojenne();
        cout<<"Podaj wspolrzedna strzalu x ";
        cin>>ruch_gr_1.first;
        cout<<"Podaj wspolrzedna y ";
        cin>>ruch_gr_1.second;
        bool czy_pasuje_kolejke_gr1=false;
        if(ruch_gr_1.first<0)
        {//zapis
            Gracz_nr_2.zapis_do_pliku_swojej_tablicy(Gracz_nr_1);
            Gracz_nr_1.zapis_do_pliku_swojej_tablicy(Gracz_nr_2);
            cout<<"Zapisano , prosze wprowadz po raz kolejny pierwsza wspolrzedna "<<endl;
            cin>>ruch_gr_1.first;
            pomocnicze_sprawdzanie_bledu_wejscia_z_tacker(ruch_gr_1,Gracz_nr_2,Gracz_nr_1);
        }
        if(ruch_gr_1.second<0)
        {

                exit(0);
        }


            pomocnicze_sprawdzanie_bledu_wejscia_z_tacker(ruch_gr_1, Gracz_nr_2,Gracz_nr_1);
            while ((status = Gracz_nr_2.otrzymaj_strzal(ruch_gr_1))&&Gracz_nr_2.ilosc_plywajacych_czesci()!=0) {
                status_strzalu_wypisywanie_z_trackerem(status, ruch_gr_1, Gracz_nr_2,Gracz_nr_1);
                ile_bylo_ruchow++;
            }


        status = 0;
        if(ile_bylo_ruchow%10 == 0)
        {
            wypisywanie_informacji_o_mozliwosci_wyjscia_lub_zapisu();
        }
        cout<<endl<<"Gracz "<<Gracz_nr_2.imie<<" wykonuje swoj ruch "<<endl;
        Gracz_nr_1.wypisywanie_zinterpretowanej_tablicy_wojenne();
        cout<<"Podaj wspolrzedna strzalu x ";
        cin>>ruch_gr_2.first;
        cout<<"Podaj wspolrzedna y ";
        cin>>ruch_gr_2.second;
        bool czy_pasuje_kolejke=false;
        if(ruch_gr_2.first<0)
        {
            //zapis
            Gracz_nr_2.zapis_do_pliku_swojej_tablicy(Gracz_nr_1);
            Gracz_nr_1.zapis_do_pliku_swojej_tablicy(Gracz_nr_2);
            cout<<"Zapisano , prosze wprowadz po raz kolejny pierwsza wspolrzedna "<<endl;

            cin>>ruch_gr_2.first;
            pomocnicze_sprawdzanie_bledu_wejscia_z_tacker(ruch_gr_2,Gracz_nr_1,Gracz_nr_2);
        }
        if(ruch_gr_2.second<0)
        {

            exit(0);
        }

            pomocnicze_sprawdzanie_bledu_wejscia_z_tacker(ruch_gr_2, Gracz_nr_1, Gracz_nr_2);


            /*
             * While będzie miał wartości różne od zera zawsze gdy nie będzie strzelał w pkt puste nieodkryte
             *  Podczas gdy gracz wpisze jako ujemną wartosc daną liczbę wtedy będzie pytanie się o
             */ // tutaj błąd
            while ((status = Gracz_nr_1.otrzymaj_strzal(ruch_gr_2))&&Gracz_nr_1.ilosc_plywajacych_czesci()!=0) {
                status_strzalu_wypisywanie_z_trackerem(status, ruch_gr_2, Gracz_nr_1, Gracz_nr_2);
                ile_bylo_ruchow++;
            }



    }


    if (zycia_gracza_nr_1 > 0) {
        cout << endl << Gracz_nr_1.imie << " wygral gre nr 1" << endl;
        exit(0);
    } else if (zycia_gracza_nr_2 > 0) {
        cout << endl << Gracz_nr_2.imie << " wygral gre nr 2" << endl;
        exit(0);
    } else if (zycia_gracza_nr_1 == 0 && zycia_gracza_nr_2 == 0) {
        cout << "Remis!";
        exit(0);
    }

}

void Walka::gracz_vs_gracz(Gracz &Gracz_nr_1, Gracz &Gracz_nr_2)
{
    int zycia_gracza_nr_1=Gracz_nr_1.ilosc_plywajacych_czesci();
    int zycia_gracza_nr_2=Gracz_nr_2.ilosc_plywajacych_czesci();
while((zycia_gracza_nr_1=Gracz_nr_1.ilosc_plywajacych_czesci()) != 0
        && (zycia_gracza_nr_2=Gracz_nr_2.ilosc_plywajacych_czesci() )!= 0){
    pair<int,int>ruch_gr_1;
    pair<int,int>ruch_gr_2;
    int status=0;
    if(ile_bylo_ruchow%10 == 0)
    {
    wypisywanie_informacji_o_mozliwosci_wyjscia_lub_zapisu();
    }
    cout<<endl<<"Gracz "<<Gracz_nr_1.imie<<" wykonuje swoj ruch "<<endl;
    Gracz_nr_2.wypisywanie_zinterpretowanej_tablicy_wojenne();
    cout<<"Podaj wspolrzedna strzalu x ";
    cin>>ruch_gr_1.first;
    cout<<"Podaj wspolrzedna y ";
    cin>>ruch_gr_1.second;
    bool czy_pasuje_kolejke_gr1=false;
    if(ruch_gr_1.first<0)
    {//zapis
        Gracz_nr_2.zapis_do_pliku_swojej_tablicy(Gracz_nr_1);
        Gracz_nr_1.zapis_do_pliku_swojej_tablicy(Gracz_nr_2);
        cout<<"Zapisano , prosze wprowadz po raz kolejny pierwsza wspolrzedna "<<endl;
        cin>>ruch_gr_1.first;
        pomocnicze_sprawdzanie_bledu_wejscia(ruch_gr_1,Gracz_nr_2,Gracz_nr_1,czy_pasuje_kolejke_gr1);
    }
    if(ruch_gr_1.second<0)
    {
        if(ruch_gr_1.second==-1)
        {
            czy_pasuje_kolejke_gr1=true;
        } else
        exit(0);
    }
    if(!czy_pasuje_kolejke_gr1)
    {
        pomocnicze_sprawdzanie_bledu_wejscia(ruch_gr_1, Gracz_nr_2,Gracz_nr_1,czy_pasuje_kolejke_gr1);
        while (status = Gracz_nr_2.otrzymaj_strzal(ruch_gr_1)&&Gracz_nr_2.ilosc_plywajacych_czesci()!=0) {
            status_strzalu_wypisywanie(status, ruch_gr_1, Gracz_nr_2,Gracz_nr_1);
            ile_bylo_ruchow++;
        }
    }
    status = 0;
    if(ile_bylo_ruchow%10 == 0)
    {
        wypisywanie_informacji_o_mozliwosci_wyjscia_lub_zapisu();
    }
    cout<<endl<<"Gracz "<<Gracz_nr_2.imie<<" wykonuje swoj ruch "<<endl;
    Gracz_nr_1.wypisywanie_zinterpretowanej_tablicy_wojenne();
    cout<<"Podaj wspolrzedna strzalu x ";
    cin>>ruch_gr_2.first;
    cout<<"Podaj wspolrzedna y ";
    cin>>ruch_gr_2.second;
   bool czy_pasuje_kolejke=false;
    if(ruch_gr_2.first<0)
    {
        //zapis
        Gracz_nr_2.zapis_do_pliku_swojej_tablicy(Gracz_nr_1);
        Gracz_nr_1.zapis_do_pliku_swojej_tablicy(Gracz_nr_2);
        cout<<"Zapisano , prosze wprowadz po raz kolejny pierwsza wspolrzedna "<<endl;

        cin>>ruch_gr_2.first;
        pomocnicze_sprawdzanie_bledu_wejscia(ruch_gr_2,Gracz_nr_1,Gracz_nr_2,czy_pasuje_kolejke);
    }
    if(ruch_gr_2.second<0)
    {

            exit(0);
    }
    if(Gracz_nr_1.ilosc_plywajacych_czesci()!=0&&Gracz_nr_2.ilosc_plywajacych_czesci()!=0) {
        pomocnicze_sprawdzanie_bledu_wejscia(ruch_gr_2, Gracz_nr_1, Gracz_nr_2,czy_pasuje_kolejke);
        while ((status = Gracz_nr_1.otrzymaj_strzal(ruch_gr_2))&&Gracz_nr_1.ilosc_plywajacych_czesci()!=0) {
            status_strzalu_wypisywanie(status, ruch_gr_2, Gracz_nr_1, Gracz_nr_2);
            ile_bylo_ruchow++;
        }

    }

}
        if (zycia_gracza_nr_1 > 0) {
            cout << endl << Gracz_nr_1.imie << " wygral gre nr 1" << endl;
            exit(0);
        } else if (zycia_gracza_nr_2 > 0) {
            cout << endl << Gracz_nr_2.imie << " wygral gre nr 2" << endl;
            exit(0);
        } else if (zycia_gracza_nr_1 == 0 && zycia_gracza_nr_2 == 0) {
            cout << "Remis!";
            exit(0);
        }
}

void Walka::status_strzalu_wypisywanie(int status,pair<int,int>&gdzie_strzelano,Gracz &atakowany,Gracz &aktualny)
{
    /*
    // Kategoryzacja zwracanych wartości
    // 0 - nietrafione  -> nie będzie powtórzony strzał
    // 1 - trafione i zostanie powtórzony strzał
    // 2 - strzelone w pole które było już stzelane -> będzie powtórzony strzał
    // 3 - strzelone w pole gdzie był statek ale kratka jest już zatopiona -> będzie powtórzony strzał
    // Kategoryzacja pól
    // 0 - nic nie ma i zakryte
    // 1 - jest i zakryte
    // 2 - nic nie było i odkryte
    // 3 - trafione i odkryte
     */
    bool czy_pasuje_kolejke=false;
    if(status==1)
    {
        cout<<"Brawo, pod punktem "<<gdzie_strzelano.second<<","<<gdzie_strzelano.first<<" znajdowal sie statek"<<endl;
        cout<<"W nagrodę bedziesz mial kolejna kolejke "<<endl;
        atakowany.wypisywanie_zinterpretowanej_tablicy_wojenne();
        cout<<endl<<"Podaj x ";
        cin>>gdzie_strzelano.first;
        cout<<"Podaj y ";
        cin>>gdzie_strzelano.second;
        pomocnicze_sprawdzanie_bledu_wejscia(gdzie_strzelano,atakowany,aktualny,czy_pasuje_kolejke);
    }
    if(status==2)
    {
        cout<<"W ten punkt juz strzelales, "<<gdzie_strzelano.second<<","<<gdzie_strzelano.first<<" lecz nic nie bylo "<<endl;
        cout<<"Teraz ponowisz ruch"<<endl;
        atakowany.wypisywanie_zinterpretowanej_tablicy_wojenne();
        cout<<endl<<"Podaj x ";
        cin>>gdzie_strzelano.first;
        cout<<"Podaj y ";
        cin>>gdzie_strzelano.second;
        pomocnicze_sprawdzanie_bledu_wejscia(gdzie_strzelano,atakowany,aktualny,czy_pasuje_kolejke);
    }
    if(status==3)
    {
        cout<<"W ten punkt juz strzelales, "<<gdzie_strzelano.second<<","<<gdzie_strzelano.first<<" jednak jest tutaj juz zatopiony statek "<<endl;
        cout<<"Teraz ponowisz ruch"<<endl;
        atakowany.wypisywanie_zinterpretowanej_tablicy_wojenne();
        cout<<endl<<"Podaj x ";
        cin>>gdzie_strzelano.first;
        cout<<"Podaj y ";
        cin>>gdzie_strzelano.second;
        pomocnicze_sprawdzanie_bledu_wejscia(gdzie_strzelano,atakowany,aktualny,czy_pasuje_kolejke);
    }
}
void Walka::status_strzalu_wypisywanie_z_trackerem(int status,pair<int,int>&gdzie_strzelano,Gracz &atakowany,Gracz &aktualny)
{
    /*
    // Kategoryzacja zwracanych wartości
    // 0 - nietrafione  -> nie będzie powtórzony strzał
    // 1 - trafione i zostanie powtórzony strzał
    // 2 - strzelone w pole które było już stzelane -> będzie powtórzony strzał
    // 3 - strzelone w pole gdzie był statek ale kratka jest już zatopiona -> będzie powtórzony strzał

    // Kategoryzacja pól
    // 0 - nic nie ma i zakryte
    // 1 - jest i zakryte
    // 2 - nic nie było i odkryte
    // 3 - trafione i odkryte
     */

    bool czy_pasuje_kolejke=false;
    if(status==1)
    {
        cout<<"Brawo, pod punktem "<<gdzie_strzelano.second<<","<<gdzie_strzelano.first<<" znajdowal sie statek"<<endl;
        cout<<"W nagrodę bedziesz mial kolejna kolejke "<<endl;
        atakowany.wypisywanie_zinterpretowanej_tablicy_wojenne();
        cout<<endl<<"Podaj x ";
        cin>>gdzie_strzelano.first;
        cout<<"Podaj y ";
        cin>>gdzie_strzelano.second;
        pomocnicze_sprawdzanie_bledu_wejscia_z_tacker(gdzie_strzelano,atakowany,aktualny);
    }
    if(status==2)// c++ potraktował - jako jedynkę ... WTF ?

    {
        cout<<"W ten punkt juz strzelales, "<<gdzie_strzelano.second<<","<<gdzie_strzelano.first<<" lecz nic nie bylo "<<endl;
        cout<<"Teraz ponowisz ruch"<<endl;
        atakowany.wypisywanie_zinterpretowanej_tablicy_wojenne();
        cout<<endl<<"Podaj x ";
        cin>>gdzie_strzelano.first;
        cout<<"Podaj y ";
        cin>>gdzie_strzelano.second;
        pomocnicze_sprawdzanie_bledu_wejscia_z_tacker(gdzie_strzelano,atakowany,aktualny);
    }
    if(status==3)
    {
        cout<<"W ten punkt juz strzelales, "<<gdzie_strzelano.second<<","<<gdzie_strzelano.first<<" jednak jest tutaj juz zatopiony statek "<<endl;
        cout<<"Teraz ponowisz ruch"<<endl;
        atakowany.wypisywanie_zinterpretowanej_tablicy_wojenne();
        cout<<endl<<"Podaj x ";
        cin>>gdzie_strzelano.first;
        cout<<"Podaj y ";
        cin>>gdzie_strzelano.second;
        pomocnicze_sprawdzanie_bledu_wejscia_z_tacker(gdzie_strzelano,atakowany,aktualny);
    }

}
void Walka::wypisywanie_informacji_o_mozliwosci_wyjscia_lub_zapisu()
{
    cout<<endl<<"Przypominam ze masz mozliwosc zapisac aktualna gre lub wyjsc z rozgrywki "<<endl;
    cout<<"Daj wartosc ujemna w X-sowej wspolrzednej by zapisac"<<endl;
    cout<<"Daj wartosc ujemna w Y-kowej wspolrzednej by wyjsc "<<endl;
}

void Walka::pomocnicze_sprawdzanie_bledu_wejscia(pair<int, int> &atak, Gracz &atakowany, Gracz &aktualny,bool &czy_pasuje_kolejke)
{
    czy_pasuje_kolejke =false;

    if(atak.first<0)
    {
        //zapis
        atakowany.zapis_do_pliku_swojej_tablicy(aktualny);
        aktualny.zapis_do_pliku_swojej_tablicy(atakowany);
        cout<<"Zapisano , prosze wprowadz po raz kolejny pierwsza wspolrzedna "<<endl;
        cin>>atak.first;
    }
    if(atak.second<0)
    {
            exit(0);
    }

    while((atak.first>atakowany.get_rozmiar_tablicy_pion()
          ||atak.second>atakowany.get_rozmiar_tablicy_poziom()||atak.first<0||atak.second<0)&&!czy_pasuje_kolejke)
    {
        if(atak.first>atakowany.get_rozmiar_tablicy_poziom()||atak.first<0)
        {
            cout<<"Podales zla X-owa wspolrzedna , wprowadz ja ponownie "<<endl;
            cin>>atak.first;
        }

        if(atak.second>atakowany.get_rozmiar_tablicy_pion()||atak.second<0)
        {
            cout<<"Podales zla Y-owa wspolrzedna , wprowadz ja ponownie "<<endl;
            cin>>atak.second;
        }

    }

}

void Walka::pomocnicze_sprawdzanie_bledu_wejscia_z_tacker(pair<int, int> &atak, Gracz &atakowany, Gracz &aktualny)
{


    if(atak.first<0)
    {
        //zapis
        atakowany.zapis_do_pliku_swojej_tablicy(aktualny);
        aktualny.zapis_do_pliku_swojej_tablicy(atakowany);
        cout<<"Zapisano , prosze wprowadz po raz kolejny pierwsza wspolrzedna "<<endl;
        cin>>atak.first;
    }
    if(atak.second<0)
    {

        exit(0);
    }

    while((atak.first>atakowany.get_rozmiar_tablicy_pion()
           ||atak.second>atakowany.get_rozmiar_tablicy_poziom()||atak.first<0||atak.second<0))
    {
        if(atak.first>atakowany.get_rozmiar_tablicy_poziom()||atak.first<0)
        {
            cout<<"Podales zla X-owa wspolrzedna , wprowadz ja ponownie "<<endl;
            cin>>atak.first;
        }

        if(atak.second>atakowany.get_rozmiar_tablicy_pion()||atak.second<0)
        {
            cout<<"Podales zla Y-owa wspolrzedna , wprowadz ja ponownie "<<endl;
            cin>>atak.second;
        }

    }
    tracker(aktualny,atak);
}

Walka::Walka()
{
    ile_bylo_ruchow=0;
}
Walka::Walka(Gracz &gracz1,Gracz &gracz2)
{
    ile_bylo_ruchow=0;
    nazwa_symulacji=nazwa_pliku_symulacja(gracz1,gracz2);
    // konstruktor do symulacji
}
stringstream Walka::nazwa_pliku_symulacja(Gracz &gracz1,Gracz &gracz2)
{
stringstream nazwa_symulacji;
nazwa_symulacji<<"symulacja_"<<gracz1.imie<<"_vs_"<<gracz2.imie<<".txt";
return nazwa_symulacji;

}

void Walka::tracker(Gracz &atakujacy,pair<int,int> ruch)
{
//kto wykonał ruch
//x wspolrzedna
//y wspolrzedna
    fstream symulacja(nazwa_symulacji.str(),ios::app);
       symulacja<<atakujacy.imie<<" "<<ruch.first<<" "<<ruch.second<<endl;
    symulacja.close();
}

pair<int, int> Walka::wczytaj_ruch(string ruch,string &kto) {
    string imie="";
    string strzal_first="",strzal_second="";

    int first=0;
    int second=0;
    int ktore_przejscie=0;

    for(auto znak:ruch) // cpp 11
    {
        if(znak==' ')
        {
            ktore_przejscie++;
        }
        else if(ktore_przejscie==0)
        {
            imie+=znak;
            continue;
        } else if(ktore_przejscie==1)
        {
            strzal_first+=znak;
            continue;

        } else if(ktore_przejscie==2)
        {
            strzal_second+=znak;
            continue;
        }
    }
    kto=imie;

    first=atoi(strzal_first.c_str());
    second=atoi(strzal_second.c_str());
pair<int,int>oddany_strzal;
oddany_strzal.first=first;
oddany_strzal.second=second;

    return oddany_strzal;
}

void Walka::symulacja(Gracz &gracz1, Gracz &gracz2) {
/*
 * Należy pamiętać że gracz 1 oraz gracz 2 muszą mieć wczytaną tablicę wcześniej .
 */
    cout<<"Witaj w trybie symulacji "<<endl;
    _sleep(500);
    cout<<"Dzis zostanie rozegrana bitwa miedzy "<<gracz1.imie<<" a "<<gracz2.imie<<endl;
_sleep(3000);
    ifstream plik_symulacji(nazwa_symulacji.str());
    if(plik_symulacji.good())
    {
        string linia="";
        cout<<"Plik dobry "<<endl<<"Tablica : "<<gracz1.imie<<endl;
        gracz1.wypisywanie_zinterpretowanej_tablicy(true);
        cout<<endl<<"Tablica : "<<gracz2.imie<<endl;
        gracz2.wypisywanie_zinterpretowanej_tablicy(true);
        _sleep(5000);
        while(getline(plik_symulacji,linia))
        {
            string kto="";
            pair<int,int> ruch=wczytaj_ruch(linia,kto);
            if(kto==gracz1.imie) // pojedyncza formula wypisania ruchu
            {
                cout<<"Atakuje "<<gracz1.imie<<" wspolrzedne ("<<ruch.second<<","<<ruch.first<<")"<< endl;
                _sleep(1000);
                gracz2.otrzymaj_strzal(ruch);

                gracz2.wypisywanie_zinterpretowanej_tablicy(true);
                _sleep(2000);
            }
            else
                if(kto==gracz2.imie)
                {
                    cout<<"Atakuje "<<gracz2.imie<<" wspolrzedne ("<<ruch.second<<","<<ruch.first<<")"<< endl;
                    _sleep(1000);
                    gracz1.otrzymaj_strzal(ruch);

                    gracz1.wypisywanie_zinterpretowanej_tablicy_wojenne();
                    _sleep(2000);
                }
        }

        if (gracz1.ilosc_plywajacych_czesci() > 0) {
            cout << endl << gracz1.imie << " wygral gre nr 1" << endl;
            exit(0);
        } else if (gracz2.ilosc_plywajacych_czesci() > 0) {
            cout << endl << gracz2.imie << " wygral gre nr 2" << endl;
            exit(0);
        } else if (gracz1.ilosc_plywajacych_czesci() == 0 && gracz2.ilosc_plywajacych_czesci() == 0) {
            cout << "Remis!";
            exit(0);
        }
    } else
        {
        cout<<"Niestety nie odnaleziono pliku symulacyjnego ";
         }
}

