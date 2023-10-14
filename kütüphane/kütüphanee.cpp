#include <iostream> 
#include <fstream> 
#include <string> 
#include <iomanip>  

using namespace std;

void kitapEkle() {

    string kitapAdi;
    string yazarAdi;
    string yayinTarihi;

    fstream dosya;

    dosya.open("kitaplik.txt", ios::app);

    if (dosya.is_open() == true)
    {
        cout << endl << "---------------------------------" << endl;
        cout << "Kitap Adi : "; cin >> kitapAdi;
        cout << "Yazar Adi : "; cin >> yazarAdi;
        cout << "Yayin Tarihi : "; cin >> yayinTarihi;
        cout << endl << "-------------------Kitap Eklendi-------------------" << endl;
        dosya << kitapAdi << " " << yazarAdi << " " << yayinTarihi << endl;

    }
    else {
        cout << "Dosya Acilamadi! ";
    }

    dosya.close();

}

void kitapAra() {
    string kitapAdi;

    cout << "Aranacak kitap adini girin : ";  cin >> kitapAdi;

    fstream dosyaOku("kitaplik.txt", ios::in);

    string gecici;
    string satir;
    bool kosul = true;
    if (dosyaOku.is_open() == true)
    {
        int sayac = 0;
        while (dosyaOku >> gecici)
        {
            if (gecici == kitapAdi)
            {
                cout << "--------------------------------------------------------------------------------------------" << endl;
                cout << "Kitap Adi : " << setw(25) << left << kitapAdi;
                dosyaOku >> gecici;
                cout << "Yazar Adi : " << setw(25) << left << gecici;
                dosyaOku >> gecici;
                cout << "Yayin Tarihi : " << setw(25) << left << gecici;
                cout << endl;
                cout << "--------------------------------------------------------------------------------------------------" << endl;
                kosul = false;
            }
            dosyaOku >> gecici;
        }

        if (sayac == 0)
        {
            cout << endl << "Aranan kitap bulunamadi!" << endl << endl;
        }
    }
    else {
        cout << "Dosya Acilamadi!";
    }

    dosyaOku.close();
}

void kitaplariListele() {
    fstream dosyaListele;

    dosyaListele.open("kitaplik.txt", ios::in);

    if (dosyaListele.is_open() == true) {

        string ad;
        cout << endl << "---------------------------------------------------------" << endl;
        while (dosyaListele >> ad)
        {
            cout << "Kitap Adi : " << setw(25) << left << ad;
            dosyaListele >> ad;
            cout << "Yazar Adi : " << setw(25) << left << ad;
            dosyaListele >> ad;
            cout << "Yayin Tarihi : " << setw(25) << left << ad;
            cout << endl;
        }
        cout << "-------------------------------------------------------------------" << endl;
    }
    else {
        cout << "Dosya Acilamadi! ";
    }

    dosyaListele.close();
}

int main()
{
    int secim;

    while (1)
    {
        cout <<
            "1-Kitap Ekle \n" <<
            "2-Kitap Ara \n" <<
            "3-Kitaplari Listele \n" <<
            "Lutfen seciminizi girin : ";
        cin >> secim;

        if (secim == 1)
        {
            kitapEkle();
        }
        else if (secim == 2)
        {
            kitapAra();
        }
        else if (secim == 3)
        {
            kitaplariListele();
        }
    }


    system("pause");
}