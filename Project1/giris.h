#ifndef GIRIS_H
#define GIRIS_H
#include <iostream>

using namespace std;
class giris
{
private:
    int yonetici_sifre;         // yonetici þifre ve adý private

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



    int Giris();//giriþ fonksiyonun tanýmý

    string giris; //giris icin tanýmlana giris stringi
    int pin;// sifre için tanýmlanan pin integer degeri
    int Secim_Bir; // Bir kategori secimi için tanýlanan integer
    int Secim_urun_kategori;// Urun kategorisi için tanýmlana integer 
    int Secim_proje_kategori;// proje kategorisi için tanýmlanan integeer

};

#endif