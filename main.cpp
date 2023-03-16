#include <iostream>
#include <fstream>

using namespace std;

int ile_pierwszych(int liczba){

    int ile_pierwszych = 0;
    int pierwsza=2;
    while(liczba>1){
            while( liczba%pierwsza == 0){
                // cout << " " << pierwsza << " " << endl;
                liczba = liczba / pierwsza;
                ile_pierwszych++;
            }
            pierwsza++;
    }
    return ile_pierwszych;
}

int ile_roznych_pierwszych(int liczba){

    int ile_roznych_pierwszych = 0;
    int pierwsza=2;

    int poprzednia=0;

    while(liczba>1){

            while( liczba % pierwsza == 0){

                liczba /= pierwsza;
                if( pierwsza != poprzednia){
                    ile_roznych_pierwszych++;
                    poprzednia = pierwsza;
                }

            }
            pierwsza++;
    }

    // cout << liczba << "  " << ile_roznych_pierwszych << endl;
    return ile_roznych_pierwszych;
}

int main()
{
    ifstream in_liczby("liczby.txt");
    // ifstream in_liczby("przyklad.txt");
    string line;

    int takie_same = 0;
    string pierwsza = "";

    for(int i = 0; i < 200; i++)
    {
        in_liczby >> line;
        int length = line.length();

        if (line[0] == line[length-1])
        {
            takie_same++;
            pierwsza = (pierwsza == "") ? pierwsza = line : pierwsza;
            // cout << line << endl;
        }

    }

    ofstream out_wynik("wyniki4.txt");
    out_wynik << "4.1:" << endl;
    out_wynik << "ile - takie same cyfry na pocz¹tku i koñcu: " << takie_same << " pierwsza znaleziona " << pierwsza << endl;

    in_liczby.close();

    in_liczby.open("liczby.txt");
    // in_liczby.open("przyklad.txt");
    int ile_max = 0;
    int max_liczba = 0;

    int ile_roznych_max = 0;
    int max_roznych_liczba = 0;

    for(int i = 0; i < 200; i++)
    {
        in_liczby >> line;

        int liczba = stoi(line);

        int ile = ile_pierwszych(liczba);
        if( ile > ile_max )
        {
           ile_max = ile;
           max_liczba = liczba;
        }

        int ile_roznych = ile_roznych_pierwszych(liczba);
        if( ile_roznych > ile_roznych_max )
        {
            ile_roznych_max = ile_roznych;
            max_roznych_liczba = liczba;
        }

    }

    out_wynik << "4.2: " << endl;
    out_wynik << max_liczba << " "  << ile_max << endl;
    out_wynik << max_roznych_liczba << " "  << ile_roznych_max << endl;

    in_liczby.close();

    // Zadanie 4.3

    in_liczby.open("liczby.txt");
    //in_liczby.open("przyklad.txt");
    int liczby[200];

    for(int i=0; i<200; i++)
    {
        in_liczby >> liczby[i];
    }

    ofstream out_trojki("trojki.txt");


    int licznik_trojek = 0;
    for(int i=0; i<200; i++)
    {
        for(int j=0; j<200; j++)
        {
            for( int k=0; k<200; k++)
            {
                if( (liczby[i] < liczby[j]) &
                    (liczby[j] < liczby[k]) )
                    {
                        if( (liczby[j] % liczby[i] == 0) &
                            (liczby[k] % liczby[j] == 0) )
                            {
                                licznik_trojek++;
                                out_trojki << liczby[i] << " " << liczby[j] << " " << liczby[k] << endl;
                            }
                    }
            }
        }
    }

    int licznik_piatek = 0;


    // uwaga, trwa dlugo, cout po to by widziec, ze cos sie dziej
    for(int i=0; i<200; i++)
    {
        cout << i << " ";
        for(int j=0; j<200; j++)
        {
            for(int k=0; k<200; k++)
            {
                for(int l=0; l<200; l++)
                {
                    for(int m=0; m<200; m++)
                    {

                        if( (liczby[i] < liczby[j]) &
                            (liczby[j] < liczby[k]) &
                            (liczby[k] < liczby[l]) &
                            (liczby[l] < liczby[m]) )
                            {
                                if( (liczby[j] % liczby[i] == 0) &
                                    (liczby[k] % liczby[j] == 0) &
                                    (liczby[l] % liczby[k] == 0) &
                                    (liczby[m] % liczby[l] == 0) )
                                {

                                    licznik_piatek++;
                                }

                            }
                    }
                }
            }
        }
    }

    out_wynik << "4.3:" << endl;
    out_wynik << "dobrych trojek: " << licznik_trojek << endl;
    out_wynik << "dobrych piatke: " << licznik_piatek << endl;

    return 0;
}
