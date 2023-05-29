#include <iostream>
#include <string>

using namespace std;

enum Vrsta { privatni = 1, poslovni, super };

struct Datum {
    int dan, mjesec, godina;
};

struct Racun {
    int idPotrosaca;
    string imePrezime;
    Datum danIzdavanja;
    float iznos;
    Vrsta vrsta;

    void unosRacuna() {
        cout << "Unesite ID potrošača: ";
        cin >> idPotrosaca;

        cout << "Unesite ime i prezime: ";
        cin.ignore();
        getline(cin, imePrezime);

        cout << "Unesite datum izdavanja (dan mjesec godina): ";
        cin >> danIzdavanja.dan >> danIzdavanja.mjesec >> danIzdavanja.godina;

        cout << "Unesite iznos: ";
        cin >> iznos;

        cout << "Unesite vrstu računa (1 - privatni, 2 - poslovni, 3 - super): ";
        int vrstaInt;
        cin >> vrstaInt;
        vrsta = static_cast<Vrsta>(vrstaInt);
    }

    void pregledRacuna() {
        cout << "ID potrošača: " << idPotrosaca << endl;
        cout << "Ime i prezime: " << imePrezime << endl;
        cout << "Datum izdavanja: " << danIzdavanja.dan << "." << danIzdavanja.mjesec << "." << danIzdavanja.godina << endl;
        cout << "Iznos: " << iznos << endl;

        string vrstaStr;
        switch (vrsta) {
            case privatni:
                vrstaStr = "Privatni";
                break;
            case poslovni:
                vrstaStr = "Poslovni";
                break;
            case super:
                vrstaStr = "Super";
                break;
            default:
                vrstaStr = "Nepoznata";
                break;
        }
        cout << "Vrsta računa: " << vrstaStr << endl;
    }

    void ispisUplatnice() {
        cout << "---------------------------------------" << endl;
        cout << "UPLATNICA" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Ime i prezime: " << imePrezime << endl;
        cout << "Datum izdavanja: " << danIzdavanja.dan << "." << danIzdavanja.mjesec << "." << danIzdavanja.godina << endl;
        cout << "Iznos: " << iznos << endl;
        cout << "Vrsta računa: " << vrsta << endl;
        cout << "---------------------------------------" << endl;
    }
};

int main() {
    Racun racun;
    int opcija;

    do {
        cout << "----------------------------------------------\n";
        cout << "\t\tMeni:\n";
        cout << "----------------------------------------------\n";
        cout << "\t1. Unos racuna\n";
        cout << "\t2. Pregled racuna\n";
        cout << "\t3. Ispis uplatnice\n";
        cout << "\t4. Kraj\n";
        cout << "----------------------------------------------\n";
        cout << "Odaberite opciju: ";
        cin >> opcija;

        switch (opcija) {
            case 1:
                cout << "\nUnos racuna:\n";
                racun.unosRacuna();
                break;
            case 2:
                cout << "\nPregled racuna:\n";
                racun.pregledRacuna();
                break;
            case 3:
                cout << "\nIspis uplatnice:\n";
                racun.ispisUplatnice();
                break;
            case 4:
                cout << "\nKraj programa.\n";
                break;
            default:
                cout << "\nNepoznata opcija. Molimo odaberite ponovno.\n";
                break;
        }

        cout << endl;
    } while (opcija != 4);

    return 0;
}