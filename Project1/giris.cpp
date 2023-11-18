#include "giris.h"
#include "dosyaIslemleri.h"
#include<locale.h> 

// Giris Bölüm Fonksiyonu
int giris::Giris()
{
    setlocale(LC_ALL, "Turkish");// Trükçe karekterleri kullanmak için
    dosyaIslemleri aktarim; // dosayIslemleri sýnýfýn aktarim nesnesi



    setyonetici_adi("istanbul");
    setyonetici_sifre(1453);


    system("cls"); // konsol ekranýný temizler
    //Kullanýcý Adi ve sifre doðrulama döngüsü
    do {
        cout << "\n\n\t\t =   Kullanici adi giriniz : ";
        cin >> giris;

        cout << "\n\n\t\t =   Pin giriniz : (Pin sayi olmak zorundadir) : ";
        cin >> pin;


    } while (giris != yonetici_adi && pin != yonetici_sifre);

    cout << "Merhaba, Hoþgeldiniz...." << endl;

    // Birinci kategorisini gösteren döngü
    do {
        system("cls");

        cout << "1-) Ürün Bilgileri " << endl;
        cout << "2-) Proje Bilgileri " << endl;
        cout << "Ne yapmak istiyorsanýz numarasý girin...";
        cin >> Secim_Bir;

    } while (Secim_Bir != 1 && Secim_Bir != 2);


    //Urun bilgileri gösteren döngü
    if (Secim_Bir == 1) {
        do {

            system("cls");

            cout << "1-) Ürün Bilgileri " << endl;
            cout << "2-) Ürün ekle " << endl;
            cout << "3-) Ürün Cýkar " << endl;
            cout << "4-) Ürün Özel Arama" << endl;
            cout << "5-) Ürün ile ilgili Rapor" << endl;
            cout << "Ne yapmak istiyorsanýz lütfen numarasý girin...";

            cin >> Secim_urun_kategori;

        } while (Secim_urun_kategori != 1 && Secim_urun_kategori != 2 && Secim_urun_kategori != 3 && Secim_urun_kategori != 4 && Secim_urun_kategori != 5);

        system("cls");

        if (Secim_urun_kategori == 1) {

            //urun bilgilerini fonksiyona atar
            return aktarim.urun_bilgileri_yazdir();
        }
        if (Secim_urun_kategori == 2) {

            //urun bilgileri ekle fonksiyonuna atar
            return aktarim.urun_bilgileri_ekle();
        }
        if (Secim_urun_kategori == 3) {

            //urun cikar fonksiyonuna atar
            return aktarim.urun_cikar();
        }
        if (Secim_urun_kategori == 4) {

            //urun arama fonksiyonuna atar 
            return aktarim.urun_arama();
        }
        if (Secim_urun_kategori == 5) {

            //urun rapor fonkisyonuna atar 
            return aktarim.urunlerin_raporu();
        }
    }
    //proje Kategorisini gösteren döngü
    if (Secim_Bir == 2) {
        do {

            system("cls");

            cout << "1-) Proje Bilgileri " << endl;
            cout << "2-) Proje ekle " << endl;
            cout << "3-) Proje Cýkar " << endl;
            cout << "4-) Proje ile ilgili Rapor" << endl;
            cout << "Ne yapmak istiyorsanýz lütfen numarasý girin...";

            cin >> Secim_proje_kategori;

        } while (Secim_proje_kategori != 1 && Secim_proje_kategori != 2 && Secim_proje_kategori != 3 && Secim_proje_kategori != 4);


        if (Secim_proje_kategori == 1) {
            system("cls");

            return aktarim.proje_bilgileri_yazdir();

        }
        if (Secim_proje_kategori == 2) {
            system("cls");
            //proje bigileri ekle fonkisyonuna atar
            return aktarim.proje_bilgileri_ekle();
        }
        if (Secim_proje_kategori == 3) {
            system("cls");

            //proje cikar fonksiyonuna atar
            return aktarim.proje_cikar();
        }

        if (Secim_proje_kategori == 4) {
            system("cls");

            //Proje  raporu fonksiyonuna atar
            return aktarim.proje_raporu();
        }



        return 0;
    }

}