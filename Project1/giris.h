#ifndef GIRIS_H
#define GIRIS_H
#include <iostream>

using namespace std;
class giris
{
private:
    int yonetici_sifre;         // yonetici �ifre ve ad� private

    string yonetici_adi;


public:
    void setyonetici_sifre(int s)
    {

        yonetici_sifre = s;

    }
    int getyonetici_sifre()
    {

        return yonetici_sifre;

    }

    void setyonetici_adi(string isim)
    {

        yonetici_adi = isim;

    }

    string getyonetici_adi()
    {

        return yonetici_adi;

    }



    int Giris();//giri� fonksiyonun tan�m�

    string giris; //giris icin tan�mlana giris stringi
    int pin;// sifre i�in tan�mlanan pin integer degeri
    int Secim_Bir; // Bir kategori secimi i�in tan�lanan integer
    int Secim_urun_kategori;// Urun kategorisi i�in tan�mlana integer 
    int Secim_proje_kategori;// proje kategorisi i�in tan�mlanan integeer

};

#endif