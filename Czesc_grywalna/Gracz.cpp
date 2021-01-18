//
// Created by Adam on 21.12.2020.
//

#include "Gracz.h"



void Gracz::ustaw_statki()
{
    cout<<"Witaj teraz wprowadzisz a nastepnie ustawisz statki "<<endl;
    cout<<"Podaj liczbe 2 kratkowych statkow ";
    cin>>ilosc_dwu_kratkowych;
    cout<<endl<<"Podaj liczbe 3 kratkowych statkow ";
    cin>>ilosc_trzy_kratkowych;
    cout<<endl<<"Podaj liczbe 4 kratkowych statkow ";
    cin>>ilosc_cztero_kratkowych;
    cout<<endl<<"Podaj liczbe 5 kratkowych statkow ";
    cin>>ilosc_piecio_kratkowych;
    ile_statkow_aktualnie=ilosc_piecio_kratkowych+ilosc_cztero_kratkowych+ilosc_dwu_kratkowych+ilosc_trzy_kratkowych;
    while(ile_statkow_aktualnie>0)
    {
       //system("cls");
        wypisywanie_pomocnicze_dla_ustaw_statki();

       ustawiam_statki();
        wypisywanie_zinterpretowanej_tablicy(true);

    }
}
void Gracz::ustaw_losowo_statki()
{
    cout<<"Witaj teraz wprowadzisz a nastepnie ustawisz statki "<<endl;
    cout<<"Podaj liczbe 2 kratkowych statkow ";
    cin>>ilosc_dwu_kratkowych;
    cout<<endl<<"Podaj liczbe 3 kratkowych statkow ";
    cin>>ilosc_trzy_kratkowych;
    cout<<endl<<"Podaj liczbe 4 kratkowych statkow ";
    cin>>ilosc_cztero_kratkowych;
    cout<<endl<<"Podaj liczbe 5 kratkowych statkow ";
    cin>>ilosc_piecio_kratkowych;
    ile_statkow_aktualnie=ilosc_piecio_kratkowych+ilosc_cztero_kratkowych+ilosc_dwu_kratkowych+ilosc_trzy_kratkowych;
    while(ile_statkow_aktualnie>0)
    {
        ustawiam_losowo_statki();
    }
    wypisywanie_zinterpretowanej_tablicy(true);
}
char Gracz::interpreter(int miejsce_w_tablicy)
{
    // Kategoryzacja pól
    // 0 - nic nie ma i zakryte
    // 1 - jest i zakryte
    // 2 - nic nie było i odkryte
    // 3 - trafione i odkryte
    if(miejsce_w_tablicy==0)
    {
        return char(178);

    }else if(miejsce_w_tablicy==1)
    {
        return 'z';
    }else if(miejsce_w_tablicy==2)
    {
        return 'O';
    }else if(miejsce_w_tablicy==3)
    {
        return 'X';
    }

}

Gracz::Gracz()
{
    int rozmiar_X;
    int rozmiar_Y;
    cout<<"Podaj rozmiary twojej planszy "<<endl;
    cout<<"Podaj dlugosc planszy ";
    cin>>rozmiar_X;
    cout<<"Podaj wysokosc planszy  ";
    cin>>rozmiar_Y;
    cout<<"Podaj imie : ";
    cin>>imie;

    vector<vector<int>> przykladowaTablica2D(rozmiar_Y) ;
    for(int i=0;i<przykladowaTablica2D.size();i++) {
        for (int j = 0; j < rozmiar_X; j++) {
            przykladowaTablica2D[i].push_back(0);
        }
    }


    m_tablica=przykladowaTablica2D;
    //wypisywanie_tablicy();
    int wybor=0;
   while(wybor!=1||wybor!=2) {
       cout << endl << "Chcesz losowe ustawienie statkow czy samemu chcesz ustawic statki " << endl;
       cout << "By samemu ustawic daj 1 by losowo daj 2 "<<endl;
       cin >> wybor;
       if (wybor == 1) {
           ustaw_statki();
           break;
       } else if (wybor == 2) {
        ustaw_losowo_statki();
           break;
       }

   }
}

void Gracz::wypisywanie_pomocnicze_dla_ustaw_statki()
{
    cout<<"\nMasz do dyspozycji "<<ile_statkow_aktualnie<<" statkow "<<endl;
    if(ilosc_piecio_kratkowych>0)
    {
        cout<<"Mozesz postawic "<<ilosc_piecio_kratkowych<<" pieciokratkowych statkow "<<endl;
    }
    if(ilosc_cztero_kratkowych>0)
    {
        cout<<"Mozesz postawic "<<ilosc_cztero_kratkowych<<" czterokratkowych statkow "<<endl;
    }
    if(ilosc_trzy_kratkowych>0)
    {
        cout<<"Mozesz postawic "<<ilosc_trzy_kratkowych<<" trzykratkowych statkow "<<endl;
    }
    if(ilosc_dwu_kratkowych>0)
    {
        cout<<"Mozesz postawic "<<ilosc_dwu_kratkowych<<" dwukratkowych statkow "<<endl;
    }


}
void Gracz::ustawiam_statki() {
    cout << "Podasz teraz poczatkowe wspolrzedne i koncowe na ktorych ma sie znajdowac statek " << endl;
    pair<int, int> poczatek;
    pair<int, int> koniec;
    pair<int, int> delta;
///Możemy liczyć na to że wprowadzone dane będą prawidłowe
        cout << "Podaj poczatkowa wspolrzedna x"<<endl;
        cin >> poczatek.first;
        cout << "Podaj poczatkowa wspolrzedna y"<<endl;
        cin >> poczatek.second;
        cout << "Teraz podasz koncowa wspolrzedna x"<<endl;
        cin >> koniec.first;
        cout << "A teraz koncowa wspolrzedna y"<<endl;
        cin >> koniec.second;
    delta.first = koniec.first - poczatek.first;
    delta.second = koniec.second - poczatek.second;
    bool czy_nadpisac_tablice = true;
    if (delta.first != 0 && delta.second != 0) {
        cout << "Podales punkty niewspolliniowe , nastapi ponowne wprowadzenie danych ";
        _sleep(3000);
        czy_nadpisac_tablice = false;
        ustawiam_statki();
    }
    //zabezpieczenia przed wyrzucaniem śmieci przez referencje
    if (czy_nadpisac_tablice) {
        int jaki_typ_tego_statku_jest = 1;

        if (delta.first != 0) {
            jaki_typ_tego_statku_jest += abs(delta.first);
        }
        if (delta.second != 0) {
            jaki_typ_tego_statku_jest += abs(delta.second);
        }
        switch (jaki_typ_tego_statku_jest) {
            case 2: {
                if (ilosc_dwu_kratkowych == 0) {
                    cout << "Przykro mi ale nie masz juz dwukratkowych statkow " << endl;
                    wypisywanie_pomocnicze_dla_ustaw_statki();
                    czy_nadpisac_tablice=false;
                    ustawiam_statki();
                }
                break;
            }
            case 3: {
                if (ilosc_trzy_kratkowych == 0) {
                    cout << "Przykro mi ale nie masz juz trzykratkowych statkow " << endl;
                    wypisywanie_pomocnicze_dla_ustaw_statki();
                    czy_nadpisac_tablice=false;
                    ustawiam_statki();
                }
                break;
            }
            case 4: {
                if (ilosc_cztero_kratkowych == 0) {
                    cout << "Przykro mi ale nie masz juz czterokratkowych statkow " << endl;
                    wypisywanie_pomocnicze_dla_ustaw_statki();
                    czy_nadpisac_tablice=false;
                    ustawiam_statki();
                }
                break;
            }
            case 5: {
                if (ilosc_piecio_kratkowych == 0) {
                    cout << "Przykro mi ale nie masz juz pieciokratkowych statkow " << endl;
                    wypisywanie_pomocnicze_dla_ustaw_statki();
                    czy_nadpisac_tablice=false;
                    ustawiam_statki();
                }
                break;
            }
            default: {
                cout << "Podales zly rozmiar statku " << jaki_typ_tego_statku_jest << " , prosze podaj dobra wartosc ";
                wypisywanie_pomocnicze_dla_ustaw_statki();
                czy_nadpisac_tablice=false;
                ustawiam_statki();
            }
        }
        if(czy_nadpisac_tablice){
            vector<vector<int>> klon_tablicy = m_tablica;
            while (delta.first != 0 || delta.second != 0) {
                if (delta.first > 0) {
                    if (klon_tablicy[poczatek.second][poczatek.first] == 0) {
                        klon_tablicy[poczatek.second][poczatek.first] = 1;
                        poczatek.first++;
                        delta.first--;
                    } else {
                        ustawiam_statki();
                        czy_nadpisac_tablice = false;
                    }
                } else if (delta.first < 0) {
                    if (klon_tablicy[poczatek.second][poczatek.first] == 0) {
                        klon_tablicy[poczatek.second][poczatek.first] = 1;
                        poczatek.first--;
                        delta.first++;
                    } else {
                        ustawiam_statki();
                        czy_nadpisac_tablice = false;
                    }
                } else if (delta.second > 0) {
                    if (klon_tablicy[poczatek.second][poczatek.first] == 0) {
                        klon_tablicy[poczatek.second][poczatek.first] = 1;
                        poczatek.second++;
                        delta.second--;
                    } else {
                        ustawiam_statki();
                        czy_nadpisac_tablice = false;
                    }
                } else if (delta.second < 0) {
                    if (klon_tablicy[poczatek.second][poczatek.first] == 0) {
                        klon_tablicy[poczatek.second][poczatek.first] = 1;
                        poczatek.second--;
                        delta.second++;
                    } else {
                        ustawiam_statki();
                        czy_nadpisac_tablice = false;
                    }
                }
            }
                if(czy_nadpisac_tablice){
                if (klon_tablicy[koniec.second][koniec.first] == 0) {
                    klon_tablicy[koniec.second][koniec.first] = 1;
                } else {
                    czy_nadpisac_tablice=false;
                    ustawiam_statki();
                }
                if (czy_nadpisac_tablice) {
                    switch (jaki_typ_tego_statku_jest) {
                        case 2: {
                            ilosc_dwu_kratkowych--;
                            ile_statkow_aktualnie--;
                            m_tablica = klon_tablicy;
                            break;
                            }
                        case 3: {
                            ilosc_trzy_kratkowych--;
                            ile_statkow_aktualnie--;
                            m_tablica = klon_tablicy;
                            break;
                            }
                        case 4: {
                            ilosc_cztero_kratkowych--;
                            ile_statkow_aktualnie--;
                            m_tablica = klon_tablicy;
                            break;
                            }
                        case 5: {
                            ilosc_piecio_kratkowych--;
                            ile_statkow_aktualnie--;
                            m_tablica = klon_tablicy;
                            break;
                            }
                        }
                    }
                }
            }
    }
}


Gracz::Gracz(string imie)// tylko do wczytywania i symulacji
{
this->imie=imie;


}

void Gracz::wypisywanie_zinterpretowanej_tablicy_wojenne() {
    string pozioma_linia = "--";
    cout << "  ";
    int rzad_wielkosci;
    rzad_wielkosci = m_tablica.size();
    int liczba_spacji_przed = 0;
    while (rzad_wielkosci /= 10) {
        pozioma_linia += "-";
        liczba_spacji_przed++;
        cout << " ";
    }
    for (int i = 0; i < m_tablica[0].size(); i++) {
        if (i / 10 > 0) {
            cout << i / 10 << "|";
        } else cout << "  ";

    }
    cout << endl << "  ";
    while (liczba_spacji_przed != 0) {
        cout << " ";
        liczba_spacji_przed--;
    }
    for (int i = 0; i < m_tablica[0].size(); i++) {
        cout << i % 10 << "|";
        pozioma_linia += "--";
    }
    cout << endl;
    for (int i = 0; i < m_tablica.size(); i++) {
        if (!(i / 10)) {
            cout << pozioma_linia << endl << i << " |";
        } else {
            cout << pozioma_linia << endl << i << "|";
        }
        for (int j = 0; j < m_tablica[i].size(); j++) {


            cout << interpreter_wojenny(m_tablica[i][j]) << "|";
        }
        cout << endl;

    }

}

char Gracz::interpreter_wojenny(int miejsce_w_tablicy) {


        // Kategoryzacja pól
        // 0 - nic nie ma i zakryte
        // 1 - jest i zakryte
        // 2 - nic nie było i odkryte
        // 3 - trafione i odkryte
        if(miejsce_w_tablicy==0||miejsce_w_tablicy==1)
        {
            return char(178);

        }else if(miejsce_w_tablicy==2)
        {
            return 'O';
        }else if(miejsce_w_tablicy==3)
        {
            return 'X';
        }


}

void Gracz::zapis_do_pliku_swojej_tablicy(Gracz &gracz2)
{
    stringstream nazwa;
    string nazwa_pliku;
    nazwa<<"save_"<<imie<<"_vs_"<<gracz2.imie<<".txt";
    ofstream gracz1(nazwa.str());
    for(int i =0;i<m_tablica.size();i++)
    {
        for(int j=0;j<m_tablica[0].size();j++)
        {
            gracz1<<m_tablica[i][j]<<" ";
        }
        gracz1<<endl;
    }
    gracz1.close();
}
bool Gracz::wczytanie_z_pliku(Gracz &oponent)
{
vector<string> wiersze(0);
stringstream nazwa_pliku;
nazwa_pliku<<"save_"<<imie<<"_vs_"<<oponent.imie<<".txt";
string pomoc;
ifstream zapis(nazwa_pliku.str());

if(zapis.good())
{
    while(getline(zapis,pomoc))
    {
        wiersze.push_back(pomoc);
    }
   int kolumny_wraz_ze_spacjami= wiersze[0].size();
    vector<vector<int>> tablica_wczytana (wiersze.size());
    for(int i =0;i<wiersze.size();i++) {
        for (int j = 0; j < kolumny_wraz_ze_spacjami; j++)
        {
            if(wiersze[i][j]==' ')
            {
            }else
            {
                tablica_wczytana[i].push_back(wiersze[i][j]-'0');
            }
        }
    }
m_tablica=tablica_wczytana;
    zapis.close();
    return true;
} else {cout<<"Niestety nie ma dostepnego zapisu dla was . Zacznijcie nowa gre";
    zapis.close();
    return false;
}
}
void Gracz::ustawiam_losowo_statki() {
    bool czy_koniec = false;
    default_random_engine silnik2;
    uniform_int_distribution<int> rozrzucenie_w_pionie(0, m_tablica.size() - 1);
    uniform_int_distribution<int> rozrzucenie_w_poziomie(0, m_tablica[0].size() - 1);

    uniform_int_distribution<int> czy_w_pionie(0, 1);
    default_random_engine silnik;
    while (!czy_koniec) {
        bool sprawdzamy_ustawienie_pionowo = czy_w_pionie(silnik); // 0 1
        pair<int, int> poczatek;
        pair<int, int> koniec;
        pair<int, int> delta;
        bool czy_nadpisac_tablice = true;
        int jaki_typ_tego_statku_jest = 1;
        bool czy_wybrano_rozmiar_statku = false;

        while (!czy_wybrano_rozmiar_statku) {
            if (sprawdzamy_ustawienie_pionowo) {
                poczatek.second = rozrzucenie_w_pionie(silnik2);
                koniec.second = rozrzucenie_w_pionie(silnik2);
                poczatek.first = rozrzucenie_w_poziomie(silnik2);
                koniec.first = poczatek.first;
                delta.first = koniec.first - poczatek.first;
                delta.second = koniec.second - poczatek.second;
                if (delta.first != 0) {
                    jaki_typ_tego_statku_jest += abs(delta.first);
                }
                if (delta.second != 0) {
                    jaki_typ_tego_statku_jest += abs(delta.second);
                }
                switch (jaki_typ_tego_statku_jest) {
                    case 2: {
                        if (ilosc_dwu_kratkowych != 0) {
                            czy_wybrano_rozmiar_statku = true;
                        }
                        break;
                    }
                    case 3: {
                        if (ilosc_trzy_kratkowych != 0) {
                            czy_wybrano_rozmiar_statku = true;
                        }
                        break;
                    }
                    case 4: {
                        if (ilosc_cztero_kratkowych != 0) {
                            czy_wybrano_rozmiar_statku = true;
                        }
                        break;
                    }
                    case 5: {
                        if (ilosc_piecio_kratkowych != 0) {
                            czy_wybrano_rozmiar_statku = true;
                        }
                        break;
                    }
                    default: {
                        jaki_typ_tego_statku_jest = 1;
                        continue;
                    }
                }
            }
            else if (!sprawdzamy_ustawienie_pionowo) {
                poczatek.first = rozrzucenie_w_poziomie(silnik2);
                koniec.first = rozrzucenie_w_poziomie(silnik2);
                poczatek.second = rozrzucenie_w_pionie(silnik2);
                koniec.second = poczatek.second;
                delta.second = koniec.second - poczatek.second;
                delta.first = koniec.first - poczatek.first;
                if (delta.first != 0) {
                    jaki_typ_tego_statku_jest += abs(delta.first);
                }
                if (delta.second != 0) {
                    jaki_typ_tego_statku_jest += abs(delta.second);
                }
                switch (jaki_typ_tego_statku_jest) {
                    case 2: {
                        if (ilosc_dwu_kratkowych != 0) {
                            czy_wybrano_rozmiar_statku = true;
                        }
                        break;
                    }
                    case 3: {
                        if (ilosc_trzy_kratkowych != 0) {
                            czy_wybrano_rozmiar_statku = true;
                        }
                        break;
                    }
                    case 4: {
                        if (ilosc_cztero_kratkowych != 0) {
                            czy_wybrano_rozmiar_statku = true;
                        }
                        break;
                    }
                    case 5: {
                        if (ilosc_piecio_kratkowych != 0) {
                            czy_wybrano_rozmiar_statku = true;
                        }
                        break;
                    }
                    default: {
                        jaki_typ_tego_statku_jest = 1;
                        continue;
                    }
                }
            }
        }
            if (czy_nadpisac_tablice) {
                vector<vector<int> > klon_tablicy = m_tablica;

                while (delta.first != 0 || delta.second != 0) {
                    if (delta.first > 0) {
                        if (klon_tablicy[poczatek.second][poczatek.first] == 0) {
                            klon_tablicy[poczatek.second][poczatek.first] = 1;
                            poczatek.first++;
                            delta.first--;
                        } else {
                            czy_nadpisac_tablice = false;
                            break;
                        }
                    } else if (delta.first < 0) {
                        if (klon_tablicy[poczatek.second][poczatek.first] == 0) {
                            klon_tablicy[poczatek.second][poczatek.first] = 1;
                            poczatek.first--;
                            delta.first++;
                        } else {
                            czy_nadpisac_tablice = false;
                            break;
                        }
                    } else if (delta.second > 0) {
                        if (klon_tablicy[poczatek.second][poczatek.first] == 0) {
                            klon_tablicy[poczatek.second][poczatek.first] = 1;
                            poczatek.second++;
                            delta.second--;
                        } else {
                            czy_nadpisac_tablice = false;
                            break;
                        }
                    } else if (delta.second < 0) {
                        if (klon_tablicy[poczatek.second][poczatek.first] == 0) {
                            klon_tablicy[poczatek.second][poczatek.first] = 1;
                            poczatek.second--;
                            delta.second++;
                        } else {
                            czy_nadpisac_tablice = false;
                            break;
                        }
                    }
                }
                if (czy_nadpisac_tablice) {

                    if (klon_tablicy[koniec.second][koniec.first] == 0) {
                        klon_tablicy[koniec.second][koniec.first] = 1;
                    } else {
                        czy_nadpisac_tablice = false;
                    }
                    if (czy_nadpisac_tablice) {
                        switch (jaki_typ_tego_statku_jest) {
                            case 2: {
                                ilosc_dwu_kratkowych--;
                                ile_statkow_aktualnie--;
                                m_tablica = klon_tablicy;
                                czy_koniec=true;
                                break;
                            }
                            case 3: {
                                ilosc_trzy_kratkowych--;
                                ile_statkow_aktualnie--;
                                m_tablica = klon_tablicy;
                                czy_koniec=true;
                                break;
                            }
                            case 4: {
                                ilosc_cztero_kratkowych--;
                                ile_statkow_aktualnie--;
                                m_tablica = klon_tablicy;
                                czy_koniec=true;
                                break;
                            }
                            case 5: {
                                ilosc_piecio_kratkowych--;
                                ile_statkow_aktualnie--;
                                m_tablica = klon_tablicy;
                                czy_koniec=true;
                                break;
                            }
                        }
                    }
                }
            }

    }
}
void Gracz::czesc_techniczna(pair<int,int> poczatek,pair<int,int> koniec,pair<int,int> delta,int jaki_typ_tego_statku_jest)
{

    cout<<"Wypisuje wszystkie aktualne wartosci "<<endl;
    cout<<"Wypisuje poczatek . first "<<poczatek.first<<endl;
    cout<<"Wypisuje poczatek . second  "<<poczatek.second<<endl;
    cout<<"Wypisuje koniec . first  "<<koniec.first<<endl;
    cout<<"Wypisuje koniec . second  "<<koniec.second<<endl;
    cout<<"Wypisuje delta . first  "<<delta.first<<endl;
    cout<<"Wypisuje delta . second "<<delta.second<<endl;
    cout<<"Wypisuje jaki_typ_tego_statku  "<<jaki_typ_tego_statku_jest<<endl;
    // część techniczno informacyjna w poszukiwaniu błędów
}


void Gracz::wypisywanie_tablicy()
{
    string pozioma_linia="--";
    cout<<"  ";
    int rzad_wielkosci;
    rzad_wielkosci = m_tablica.size();
    int liczba_spacji_przed=0;
    while(rzad_wielkosci/=10)
    {
        pozioma_linia+="-";
        liczba_spacji_przed++;
        cout<<" ";
    }
    for(int i=0;i<m_tablica[0].size();i++)
    {
        if(i/10>0) {
            cout << i/10 << "|";
        } else cout<<"  ";

    }
    cout<<endl<<"  ";
    while(liczba_spacji_przed!=0) {
        cout << " ";
        liczba_spacji_przed--;
    }
    for(int i=0;i<m_tablica[0].size();i++)
    {
        cout<<i%10<<"|";
        pozioma_linia+="--";
    }
    cout<<endl;
    for(int i=0;i<m_tablica.size();i++) {
        if(!(i/10)) {
            cout << pozioma_linia << endl << i << " |";
        }else
        {
            cout << pozioma_linia << endl << i << "|";
        }
        for(int j=0;j<m_tablica[i].size();j++) {


            cout<< interpreter(m_tablica[i][j])<< "|" ;
        }
        cout<<endl;

    }
}

void Gracz::wypisywanie_tablicy(vector<vector<int>> tablica)
{

    string pozioma_linia="--";
    cout<<"  ";
    int rzad_wielkosci;
    rzad_wielkosci = tablica.size();
    int liczba_spacji_przed=0;
    while(rzad_wielkosci/=10)
    {
        pozioma_linia+="-";
        liczba_spacji_przed++;
        cout<<" ";
    }
    for(int i=0;i<tablica[0].size();i++)
    {
        if(i/10>0) {
            cout << i/10 << "|";
        } else cout<<"  ";

    }
    cout<<endl<<"  ";
    while(liczba_spacji_przed!=0) {
        cout << " ";
        liczba_spacji_przed--;
    }
    for(int i=0;i<tablica[0].size();i++)
    {
        cout<<i%10<<"|";
        pozioma_linia+="--";
    }
    cout<<endl;
    for(int i=0;i<tablica.size();i++) {
        if(!(i/10)) {
            cout << pozioma_linia << endl << i << " |";
        }else
        {
            cout << pozioma_linia << endl << i << "|";
        }
        for(int j=0;j<tablica[i].size();j++) {


            cout<< interpreter(tablica[i][j])<< "|" ;
        }
        cout<<endl;

    }

}
void Gracz::wypisywanie_zinterpretowanej_tablicy(bool tryb_bitewny)
{
    string pozioma_linia="--";
    cout<<" ";
    int rzad_wielkosci;
    rzad_wielkosci = m_tablica.size();
    int liczba_spacji_przed=0;
    while(rzad_wielkosci/=10)
    {
        pozioma_linia+="-";
        liczba_spacji_przed++;
        cout<<" ";
    }
    for(int i=0;i<m_tablica[0].size();i++)
    {
        if(i/10>0) {
            cout << i/10 << "|";
        } else cout<<"  ";

    }
    cout<<endl<<"  ";
    while(liczba_spacji_przed!=0) {
        cout << " ";
        liczba_spacji_przed--;
    }
    for(int i=0;i<m_tablica[0].size();i++)
    {
        cout<<i%10<<"|";
        pozioma_linia+="--";
    }
    cout<<endl;
    for(int i=0;i<m_tablica.size();i++) {
        if(!(i/10)) {
            cout << pozioma_linia << endl << i << " |";
        }else
        {
            cout << pozioma_linia << endl << i << "|";
        }
        for(int j=0;j<m_tablica[i].size();j++) {


            cout<< interpreter(m_tablica[i][j])<< "|" ;
        }
        cout<<endl;

    }

}



//---------



int Gracz::get_rozmiar_tablicy_pion() {
    return m_tablica.size();
}

int Gracz::get_rozmiar_tablicy_poziom() {
    return m_tablica[0].size();
}
int Gracz::ilosc_plywajacych_czesci() {
    int plywa=0;
    for( int i =0;i<m_tablica.size();i++)
    {
        for(int j =0;j<m_tablica[0].size();j++)
        {
            if(m_tablica[i][j]==1)
            {
                plywa++;
            }
        }
    }
    return plywa;
}
short Gracz::otrzymaj_strzal(pair<int,int> gdzie)
{
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
    if(m_tablica[gdzie.second][gdzie.first]==0)
    {
        m_tablica[gdzie.second][gdzie.first]=2;
        return 0;
    }
    if(m_tablica[gdzie.second][gdzie.first]==1)
    {
        m_tablica[gdzie.second][gdzie.first]=3;
        return 1;
    }
    if(m_tablica[gdzie.second][gdzie.first]==2)
    {
        return 2;
    }
    if(m_tablica[gdzie.second][gdzie.first]==3)
    {
        return 3;
    }
    return 0;
}
