#include "dosyaIslemleri.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "giris.h"


using namespace std;



int dosyaIslemleri::urun_bilgileri_yazdir() {

    giris menu_aktarim;//giris sýnýfýn nesnesi



    string marka_ad[40];//urun için marka ad dizisi

    string urun_ad[40];//urun için urun ad dizisi

    string urun_miktar[40];// urun için urun miktar dizisi

    string urun_birimi[40];// urun için urun birimi dizisi

    string fiyat[40];//urun için fiyat dizisi

    string urun_kod[40];//urun kodu dizisi

    int count = 0;//dosya satir sayisini bulmak için tanýmlana integer
    string line;

    ifstream okumaDosyasi;
    okumaDosyasi.open("urun_bilgileri"".txt");// txt dosyasýný açar

    ifstream file("urun_bilgileri.txt");



    //Dosya Satýr satisini Buluyor ve  dizi boyutuna belirliyor 
    while (getline(file, line))
    {
        count++;
    }
    ifstream Dosya_Okunur;

    Dosya_Okunur.open("urun_bilgileri.txt", ios::in);

    while (!Dosya_Okunur.eof())
    {
        for (int i = 0; i < count; i++) {
            // Dosya okunurkern bilgiler bu sýrayla alýnýr ve diziye atýyor
            Dosya_Okunur >> urun_kod[i] >> urun_ad[i] >> urun_miktar[i] >> urun_birimi[i] >> fiyat[i] >> marka_ad[i];
        }

    }


    string* urun_kodPtr;//Urun Kodu icin pointera yer açma
    urun_kodPtr = urun_kod;// Urun urun kodunu urun_kod atama 

    string* urun_adPtr;//Urun ad için pointera yer açma
    urun_adPtr = urun_ad;//Urun markadýný urun_ad atama

    string* urun_miktarPtr;//Urun miktarý icin pointera yer açma
    urun_miktarPtr = urun_miktar;// Urun fiyatini urun_miktar atama 

    string* urun_birimiPtr;//Urun birimi icin pointera yer açma
    urun_birimiPtr = urun_birimi;// Urun ön Kamere sayisini urun_birimi atama 

    string* fiyatPtr;//Urun fiyatý icin pointera yer açma
    fiyatPtr = fiyat;// Urun Arka Kamere sayisini fiyat atama 						

    string* marka_adPtr; //Urun marka ad için pointera yer açma
    marka_adPtr = marka_ad; //Urun marka adýný marka_ad atama					

    for (int i = 0; i < count; i = i + 2) {

        //Bu sutun pointerýn içindeki elemaný yazdýrýyor					//Bu sutun pointerýn içindeki elemaný yazdýrýyor

        cout << "Marka : " << *(urun_kod + i) << "\t\t\t\t|\t" << "Marka : " << *(urun_kod + (i + 1)) << endl;

        cout << "Fiyat : " << *(urun_ad + i) << "\t\t\t\t|\t" << "Fiyat : " << *(urun_ad + (i + 1)) << endl;

        cout << "On kamera :" << *(urun_miktar + i) << "\t\t\t\t|\t" << "On kamera : " << *(urun_miktar + (i + 1)) << endl;

        cout << "Arka kamera : " << *(urun_birimi + i) << "\t\t\t|\t" << "Arka kamera : " << *(urun_birimi + (i + 1)) << endl;

        cout << "RAM : " << *(fiyat + i) << "\t\t\t\t|\t" << "RAM : " << *(fiyat + (i + 1)) << endl;

        cout << "Urunun Kodu : " << *(marka_ad + i) << "\t\t\t|\t" << "Urunun Kodu : " << *(marka_ad + (i + 1)) << " \n\n" << endl;




    }

    Dosya_Okunur.close(); // dosya kapanýr

    //menu donmek için olusturulan döngü

    do {
        cout << "1-) Ana Menüye Dön" << endl;

        cout << "2-) Cikis" << endl;

        cin >> menu_donus;

    } while (menu_donus != 1 && menu_donus != 2);

    if (menu_donus == 1) {

        return menu_aktarim.Giris();
    }
    if (menu_donus == 2) {

        return 0;
    }

}

int dosyaIslemleri::urun_bilgileri_ekle() {


    giris menu_aktarim;



    ofstream DosyaYazma;

    DosyaYazma.open("urun_bilgileri.txt", ios::app);

    do {
        cout << "Marka Adini Girin : "; 								 cin >> marka_ad;

        cout << "Urun Fiyati Girin : "; 								 cin >> fiyat;

        cout << "Urunun miktarini : "; 	                                 cin >> urun_miktar;

        cout << "Urunun Ad  : ";	                                     cin >> urun_ad;

        cout << "Kodu giriniz : ";										 cin >> urun_kod;

        cout << "Birimini Giriniz : "; 						             cin >> urun_birimi;


        DosyaYazma << "\n" << urun_kod << " " << urun_ad << " " << urun_miktar << " " << urun_birimi << " " << fiyat << " " << marka_ad;

        cout << "Urun basariyla Eklenmistir...\n Cikmak icin 1 basiniz.... \n Yeni urun eklemek icin farkli tusa basiniz... "; cin >> yine_urun_ekleme;

    } while (yine_urun_ekleme != 1);


    DosyaYazma.close();


    system("cls");

    cout << "\n1-) Ana Menüye Dön" << endl;

    cout << "Cikis icin herhangi bir tusa basiniz" << endl;

    cin >> urun_ekleme_bolumu;


    if (urun_ekleme_bolumu == 1) {

        system("cls");
        return menu_aktarim.Giris();
    }
    else {
        system("cls");
        cout << "Cikis Yaptiniz..." << endl;

        return 0;
    }

}

int dosyaIslemleri::urun_cikar() {





    giris menu_aktarim;

    cout << "Cikarmak istediginiz urun Kodu : ";
    cin >> cikarmaUrunKodu;

    ifstream DosyaOkuma("urun_bilgileri.txt");
    ofstream DosyaYazma("urun_cikarma.txt");

    while (!(DosyaOkuma.eof())) {

        DosyaOkuma >> CikarmaUrunKod >> CikarUrunAd >> CikarmaMiktar >> CikarmaBirimi >> CikarmaFiyat >> CikarmaMarkaAd;

        if (CikarmaUrunKod == cikarmaUrunKodu) {

            cout << "Urunu cikardiniz" << endl;
        }
        else if (CikarmaUrunKod != cikarmaUrunKodu && CikarmaUrunKod != kontrol) {

            DosyaYazma << "\n" << CikarmaUrunKod << " " << CikarUrunAd << " " << " " << CikarmaMiktar << " " << CikarmaBirimi << " " << CikarmaFiyat << " " << CikarmaMarkaAd;
            kontrol = cikarmaUrunKodu;
        }
        DosyaYazma.close();
        DosyaOkuma.close();
        remove("urun_bilgileri");
        rename("urun_cikarma", "urun_bilgileri.txt");


    }
    do {
        cout << "1-) Ana Menüye Dön" << endl;

        cout << "2-) Cikis" << endl;

        cin >> menu_donus;

    } while (menu_donus != 1 && menu_donus != 2);

    if (menu_donus == 1) {

        return menu_aktarim.Giris();
    }
    if (menu_donus == 2) {

        return 0;
    }
}

int dosyaIslemleri::urun_arama() {


    giris menu_aktarim;

    string marka_ad[35];

    string urun_ad[35];

    string urun_miktar[35];

    string urun_birimi[35];

    string fiyat[35];

    int urun_kod[35];


    string line;

    int  count = 0;
    int no = -1;
    int satir_sayisi = 0;


    cout << "Urun Kodunu girin: ";
    cin >> aranan;


    ifstream okumaDosyasi;
    okumaDosyasi.open("urun_bilgileri"".txt");

    ifstream file("urun_bilgileri.txt");

    while (getline(file, line))
    {

        count++;

    }

    ifstream Dosya_Okunur;

    Dosya_Okunur.open("urun_bilgileri.txt", ios::in);

    while (!Dosya_Okunur.eof())
    {
        for (int i = 0; i < count; i++) {
            Dosya_Okunur >> urun_kod[i] >> urun_ad[i] >> urun_miktar[i] >> urun_birimi[i] >> fiyat[i] >> marka_ad[i];
        }

    }

    for (int i = 0; i < count; i++) {

        if (aranan == urun_kod[i])
        {
            no = i;
            break;

        }
    }

    cout << "\n" << "===========================================================================" << endl;

    if (no != -1) {
        cout << "\n" << "Urun Kod : " << urun_kod[no];

        cout << urun_kod[no] << "  " << urun_ad[no] << "  " << urun_miktar[no] << "  " << urun_birimi[no] << "  " << fiyat[no] << "  " << marka_ad[no] << "  " << endl;

    }
    cout << "\n" << "===========================================================================" << endl;
    do {
        cout << "\n\n1-) Ana Menüye Dön" << endl;

        cout << "2-) Cikis" << endl;

        cin >> menu_donus;

    } while (menu_donus != 1 && menu_donus != 2);

    if (menu_donus == 1) {

        return menu_aktarim.Giris();
    }
    if (menu_donus == 2) {

        return 0;
    }


}


int dosyaIslemleri::urunlerin_raporu() {

    giris menu_aktarim;


    string marka_ad[40];

    string urun_ad[40];

    int urun_miktar[40];

    string urun_birimi[40];

    int fiyat[40];

    string urun_kod[40];

    int tutucu[40];

    int count = 0;
    string line;
    int toplam = 0;

    ifstream okumaDosyasi;
    okumaDosyasi.open("urun_bilgileri"".txt");

    ifstream file("urun_bilgileri.txt");

    while (getline(file, line))
    {
        count++;
    }
    ifstream Dosya_Okunur;

    Dosya_Okunur.open("urun_bilgileri.txt", ios::in);

    while (!Dosya_Okunur.eof())
    {
        for (int i = 0; i < count; i++) {
            Dosya_Okunur >> urun_kod[i] >> urun_ad[i] >> urun_miktar[i] >> urun_birimi[i] >> fiyat[i] >> marka_ad[i];
        }

    }

    for (int i = 0; i < count; i++)
    {
        tutucu[i] = urun_miktar[i] * fiyat[i];

        cout << urun_miktar[i] << "\t" << urun_birimi[i] << "\t\t" << fiyat[i] << "\t =  " << urun_miktar[i] * fiyat[i] << endl;
    }

    for (int i = 0; i < count; i++)
    {

        toplam += tutucu[i];
    }
    cout << "==================================================" << endl;
    cout << "TOPLAM ÜRÜN FÝYATÝ  = " << toplam << endl;


    do {
        cout << "\n\n1-) Ana Menüye Dön" << endl;

        cout << "2-) Cikis" << endl;

        cin >> menu_donus;

    } while (menu_donus != 1 && menu_donus != 2);

    if (menu_donus == 1) {

        return menu_aktarim.Giris();
    }
    if (menu_donus == 2) {

        return 0;
    }
}


int dosyaIslemleri::proje_bilgileri_yazdir() {

    giris menu_aktarim;

    string proje_kodu[30];
    string proje_adi[30];
    string proje_firmaAd[30];
    string proje_sorumlusu[30];
    string proje_konum[30];
    string proje_durum[30];



    int count = 0;
    string line;

    ifstream okumaDosyasi;
    okumaDosyasi.open("proje"".txt");

    ifstream file("proje.txt");


    while (getline(file, line))
    {

        count++;

    }
    ifstream Dosya_Okunur;

    Dosya_Okunur.open("proje.txt", ios::in);

    while (!Dosya_Okunur.eof())
    {
        for (int i = 0; i < count; i++) {


            Dosya_Okunur >> proje_kodu[i] >> proje_adi[i] >> proje_firmaAd[i] >> proje_sorumlusu[i] >> proje_konum[i] >> proje_durum[i];

        }
    }


    string* proje_koduPtr;
    proje_koduPtr = proje_kodu;

    string* proje_adPtr;
    proje_adPtr = proje_adi;

    string* proje_firmaAdPtr;
    proje_firmaAdPtr = proje_firmaAd;

    string* proje_sorumlusuPtr;
    proje_sorumlusuPtr = proje_sorumlusu;

    string* proje_konumPtr;
    proje_konumPtr = proje_konum;

    string* proje_durumPtr;
    proje_durumPtr = proje_durum;



    for (int i = 0; i < count; i++) {



        cout << "\nProje Kodu : " << *(proje_kodu + i) << endl;

        cout << "Proje Adi : " << *(proje_adi + i) << endl;

        cout << "Proje Firma Adi :" << *(proje_firmaAd + i) << endl;

        cout << "Proje Sorumlusu : " << *(proje_sorumlusu + i) << endl;

        cout << "Proje Konumu : " << *(proje_konum + i) << endl;

        cout << "Proje Durumu : " << *(proje_durum + i) << "\n\n " << endl;


    }

    Dosya_Okunur.close();


    do {
        cout << "1-) Ana Menüye Dön" << endl;

        cout << "2-) Cikis" << endl;

        cin >> menu_donus;

    } while (menu_donus != 1 && menu_donus != 2);

    if (menu_donus == 1) {

        return menu_aktarim.Giris();
    }
    if (menu_donus == 2) {

        return 0;
    }

}


int dosyaIslemleri::proje_bilgileri_ekle() {

    giris menu_aktarim;

    int Proje_kodu;
    string Proje_Ad;
    string Proje_YurutenFirmaa;
    string Proje_Sorumlusu;
    string Proje_Konum;


    ofstream DosyaYazma;

    DosyaYazma.open("proje.txt", ios::app);
    do {
        cout << "Proje Kodu : ";        								 cin >> Proje_kodu;

        cout << "Proje Adi : "; 			        					 cin >> Proje_Ad;



        cout << "Proje sorumlu kisinin adi : ";	                         cin >> Proje_Sorumlusu;

        cout << "Proje Konummu : ";										 cin >> Proje_Konum;
        cout << "Proje Yuruten Firma : ";                	             cin >> Proje_YurutenFirmaa;

        Proje_Durum = "Devam_Ediyor";


        DosyaYazma << "\n" << Proje_kodu << " " << Proje_Ad << " " << Proje_YurutenFirmaa << " " << Proje_Sorumlusu << " " << Proje_Konum << " " << Proje_Durum;
        cout << "Urun basariyla Eklenmistir...\n Baska Urun Eklemek icin 1'e basiniz...\nSatici Menusune Donmek icin farkli tusa basiniz "; cin >> yine_urun_ekleme;
    } while (yine_urun_ekleme != 1);

    DosyaYazma.close();

    do {
        cout << "1-) Ana Menüye Dön" << endl;

        cout << "2-) Cikis" << endl;

        cin >> menu_donus;

    } while (menu_donus != 1 && menu_donus != 2);

    if (menu_donus == 1) {

        return menu_aktarim.Giris();
    }
    if (menu_donus == 2) {

        return 0;
    }


}


int dosyaIslemleri::proje_cikar() {

    giris menu_aktarim;


    cout << "Cikarmak istediginiz Proje Kodu : ";

    cin >> CikarmaProjeKodu;

    ifstream DosyaOkuma("proje.txt");
    ofstream DosyaYazma("projecikarma.txt");

    while (!(DosyaOkuma.eof())) {

        DosyaOkuma >> CikarmaProjeKod >> CikarmaProjeAdi >> CikarmaProjeFirmaAdi >> CikarmaProjeSorumlusu >> CikarmaProjeKonum >> CikarmaProjeDurum;

        if (CikarmaProjeKod == CikarmaProjeKodu) {

            cout << "Urunu cikardiniz" << endl;
        }
        else if (CikarmaProjeKod != CikarmaProjeKodu && CikarmaProjeKod != kontrol) {

            DosyaYazma << "\n" << CikarmaProjeKodu << " " << CikarmaProjeAdi << " " << " " << CikarmaProjeFirmaAdi << " " << CikarmaProjeSorumlusu << " " << CikarmaProjeKonum << " " << CikarmaProjeDurum;
            kontrol = CikarmaProjeKodu;
        }
        DosyaYazma.close();
        DosyaOkuma.close();

        remove("proje");
        rename("projecikarma.txt", "proje.txt");


    }
    do {
        cout << "1-) Ana Menüye Dön" << endl;

        cout << "2-) Cikis" << endl;

        cin >> menu_donus;

    } while (menu_donus != 1 && menu_donus != 2);

    if (menu_donus == 1) {

        return menu_aktarim.Giris();
    }
    if (menu_donus == 2) {

        return 0;
    }
}



int dosyaIslemleri::proje_raporu() {

    
    return hakedishesaplama();
}
int dosyaIslemleri::hakedishesaplama()
{
	//proje secip hakedis hesaplamasi gösteren döndü
	do
	{
		cout << "1-) Trabzon_Rezidans  " << endl;
		cout << "2-) Tema_Istanbul" << endl;
		cout << "3-) Istek_Istanbul " << endl;
		cout << "4-) Alyans_Rezidans" << endl;
		cout << "5-) Finans_Sehir " << endl;
		cout << "6-) Istanbul_Kent" << endl;
		cout << "Hangi Projeye Bakmak Ýstiyorsanýz Numarasýný Girin " << endl;

		cin >> proje_tercih;

	} while (proje_tercih != 1 && proje_tercih != 2 && proje_tercih != 3 && proje_tercih != 4 && proje_tercih != 5 && proje_tercih != 6);

	if (proje_tercih == 1)
	{
		return Trabzon_Rezidans();
	}
	if (proje_tercih == 2)
	{
		return Tema_Istanbul();
	}
	if (proje_tercih == 3)
	{
		return Istek_Istanbul();
	}
	if (proje_tercih == 4)
	{
		return Alyans_Rezidans();
	}
	if (proje_tercih == 5)
	{
		return Finans_Sehir();
	}
	if (proje_tercih == 6)
	{
		return Istanbul_Kent();
	}

}


//Projenin hakedis hesaplar ve ekrana yazdirir ve projeye urun eklenir
int dosyaIslemleri::Trabzon_Rezidans()
{
	string marka_ad[30];//telefon için marka adlarý

	string urun_ad[30];

	int urun_miktar[30];

	string urun_birimi[30];

	int fiyat[30];//telefon için fiyat dizisi

	string urun_kod[30];//urun kodu dizisi

	int toplam[30];


	int proje_urun_ekleme;
	int harcanan = 0;
	int count = 0;
	string line;

	ifstream okumaDosyasi;
	okumaDosyasi.open("Trabzon_Rezidans"".txt");

	ifstream file("Trabzon_Rezidans.txt");

	while (getline(file, line))
	{
		count++;
	}
	ifstream Dosya_Okunur;

	Dosya_Okunur.open("Trabzon_Rezidans.txt", ios::in);

	while (!Dosya_Okunur.eof())
	{
		for (int i = 0; i < count; i++) {
			Dosya_Okunur >> urun_kod[i] >> urun_ad[i] >> urun_miktar[i] >> urun_birimi[i] >> fiyat[i] >> marka_ad[i];
		}

	}

	cout << "Urun Kod " << setw(20) << "Urun Ad" << setw(20) << "Urun miktar" << setw(20) << "Urun Birimi" << setw(20) << "Urun birim fiyati" << setw(20) << " Marka Ad" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < count; i++)
	{
		cout << urun_kod[i] << setw(20) << urun_ad[i] << setw(20) << urun_miktar[i] << setw(20) << urun_birimi[i] << setw(20) << fiyat[i] << setw(20) << marka_ad[i] << "\n" << endl;

		toplam[i] = urun_miktar[i] * fiyat[i];
	}
	for (int i = 0; i < count; i++)
	{
		harcanan += toplam[i];
	}
	cout << "   +" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

	cout << "Proje Maliyeti  = " << harcanan << endl;
	Dosya_Okunur.close();

	cout << "Urun eklemek icin 1 e basiniz" << endl;
	cout << "Ana menu icin 2 e basiniz" << endl;
	cout << "Cikis icin farkli bir tusa" << endl;
	cin >> proje_urun_ekleme;


	if (proje_urun_ekleme == 1) {




		okumaDosyasi.open("urun_bilgileri"".txt");

		//  ifstream file("urun_bilgileri.txt");

		while (getline(file, line))
		{
			count++;
		}
		// ifstream Dosya_Okunur;

		Dosya_Okunur.open("urun_bilgileri.txt", ios::in);

		while (!Dosya_Okunur.eof())
		{
			for (int i = 0; i < count; i++) {
				Dosya_Okunur >> urun_kod[i] >> urun_ad[i] >> urun_miktar[i] >> urun_birimi[i] >> fiyat[i] >> marka_ad[i];
			}

		}


		string* urun_kodPtr;//Telefon marka ad için poþntera yer açma
		urun_kodPtr = urun_kod;//Telefon markadýný tel_marka_ad atama

		string* urun_adPtr;//Telefon marka ad için poþntera yer açma
		urun_adPtr = urun_ad;//Telefon markadýný tel_marka_ad atama

		int* urun_miktarPtr;//Telefon fiyat icin pointera yer açma
		urun_miktarPtr = urun_miktar;// Telefon fiyatini tel_fiyatPtr atama 

		string* urun_birimiPtr;//Telefon on kamera icin pointera yer açma
		urun_birimiPtr = urun_birimi;// Telefon ön Kamere sayisini tel_on_kamera atama 

		int* fiyatPtr;//Telefon Arka kamera icin pointera yer açma
		fiyatPtr = fiyat;// Telefon Arka Kamere sayisini tel_arka_kamera atama 						

		string* marka_adPtr; //Telefon Urun Kodu icin pointera yer açma
		marka_adPtr = marka_ad; // Telefon urun kodunu tel_urun_kodPtr atama 						

		for (int i = 0; i < count; i = i + 2) {

			//Bu sutun pointerýn içindeki elemaný yazdýrýyor					//Bu sutun pointerýn içindeki elemaný yazdýrýyor

			cout << "Marka : " << *(urun_kod + i) << "\t\t\t\t|\t" << "Marka : " << *(urun_kod + (i + 1)) << endl;

			cout << "Fiyat : " << *(urun_ad + i) << "\t\t\t\t|\t" << "Fiyat : " << *(urun_ad + (i + 1)) << endl;

			cout << "On kamera :" << *(urun_miktar + i) << "\t\t\t\t|\t" << "On kamera : " << *(urun_miktar + (i + 1)) << endl;

			cout << "Arka kamera : " << *(urun_birimi + i) << "\t\t\t|\t" << "Arka kamera : " << *(urun_birimi + (i + 1)) << endl;

			cout << "RAM : " << *(fiyat + i) << "\t\t\t\t|\t" << "RAM : " << *(fiyat + (i + 1)) << endl;

			cout << "Urunun Kodu : " << *(marka_ad + i) << "\t\t\t|\t" << "Urunun Kodu : " << *(marka_ad + (i + 1)) << " \n\n" << endl;




		}

		Dosya_Okunur.close(); // dosya kapanýr

		string yaz_marka_ad;
		int yaz_fiyat;
		int yaz_urun_miktar;
		string yaz_urun_ad;
		int yaz_urun_kod;
		string yaz_urun_birimi;
		int yine_urun_ekleme;

		//cout << "urun kodunu girin.... " ; cin >> proje_urun_ekleme;

		ofstream DosyaYazma;

		DosyaYazma.open("Trabzon_Rezidans.txt", ios::app);
		do {
			cout << "Marka Adini Girin : "; 								 cin >> yaz_marka_ad;

			cout << "Urun Fiyati Girin : "; 								 cin >> yaz_fiyat;

			cout << "Urunun miktarini : "; 	                                 cin >> yaz_urun_miktar;

			cout << "Urunun Ad  : ";	                                     cin >> yaz_urun_ad;

			cout << "Kodu giriniz : ";										 cin >> yaz_urun_kod;

			cout << "Birimini Giriniz : "; 						             cin >> yaz_urun_birimi;


			DosyaYazma << "\n" << yaz_urun_kod << " " << yaz_urun_ad << " " << yaz_urun_miktar << " " << yaz_urun_birimi << " " << yaz_fiyat << " " << yaz_marka_ad;

			cout << "Urun basariyla Eklenmistir...\n Baska Urun Eklemek icin 1'e basiniz...\nSatici Menusune Donmek icin farkli tusa basiniz "; cin >> yine_urun_ekleme;

		} while (yine_urun_ekleme == 1);


		DosyaYazma.close();
	}
	if (proje_urun_ekleme == 2) {

		giris hakedis_aktarma;

		return hakedis_aktarma.Giris();
	}
	else {

		return 0;
	}

}


//Projenin hakedis hesaplar ve ekrana yazdirir ve projeye urun eklenir
int dosyaIslemleri::Tema_Istanbul()
{
	string marka_ad[30];//telefon için marka adlarý

	string urun_ad[30];

	int urun_miktar[30];

	string urun_birimi[30];

	int fiyat[30];//telefon için fiyat dizisi

	string urun_kod[30];//urun kodu dizisi

	int toplam[30];


	int proje_urun_ekleme;
	int harcanan = 0;
	int count = 0;
	string line;

	ifstream okumaDosyasi;
	okumaDosyasi.open("Tema_Istanbul"".txt");

	ifstream file("Tema_Istanbul.txt");

	while (getline(file, line))
	{
		count++;
	}
	ifstream Dosya_Okunur;

	Dosya_Okunur.open("Tema_Istanbul.txt", ios::in);

	while (!Dosya_Okunur.eof())
	{
		for (int i = 0; i < count; i++) {
			Dosya_Okunur >> urun_kod[i] >> urun_ad[i] >> urun_miktar[i] >> urun_birimi[i] >> fiyat[i] >> marka_ad[i];
		}

	}

	cout << "Urun Kod " << setw(20) << "Urun Ad" << setw(20) << "Urun miktar" << setw(20) << "Urun Birimi" << setw(20) << "Urun birim fiyati" << setw(20) << " Marka Ad" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < count; i++)
	{
		cout << urun_kod[i] << setw(20) << urun_ad[i] << setw(20) << urun_miktar[i] << setw(20) << urun_birimi[i] << setw(20) << fiyat[i] << setw(20) << marka_ad[i] << "\n" << endl;

		toplam[i] = urun_miktar[i] * fiyat[i];
	}
	for (int i = 0; i < count; i++)
	{
		harcanan += toplam[i];
	}
	cout << "   +" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

	cout << "Proje Maliyeti  = " << harcanan << endl;
	Dosya_Okunur.close();

	cout << "Urun eklemek icin 1 e basiniz" << endl;
	cout << "Ana menu icin 2 e basiniz" << endl;
	cout << "Cikis icin farkli bir tusa" << endl;
	cin >> proje_urun_ekleme;


	if (proje_urun_ekleme == 1) {




		okumaDosyasi.open("urun_bilgileri"".txt");

		//  ifstream file("urun_bilgileri.txt");

		while (getline(file, line))
		{
			count++;
		}
		// ifstream Dosya_Okunur;

		Dosya_Okunur.open("urun_bilgileri.txt", ios::in);

		while (!Dosya_Okunur.eof())
		{
			for (int i = 0; i < count; i++) {
				Dosya_Okunur >> urun_kod[i] >> urun_ad[i] >> urun_miktar[i] >> urun_birimi[i] >> fiyat[i] >> marka_ad[i];
			}

		}


		string* urun_kodPtr;//Telefon marka ad için poþntera yer açma
		urun_kodPtr = urun_kod;//Telefon markadýný tel_marka_ad atama

		string* urun_adPtr;//Telefon marka ad için poþntera yer açma
		urun_adPtr = urun_ad;//Telefon markadýný tel_marka_ad atama

		int* urun_miktarPtr;//Telefon fiyat icin pointera yer açma
		urun_miktarPtr = urun_miktar;// Telefon fiyatini tel_fiyatPtr atama 

		string* urun_birimiPtr;//Telefon on kamera icin pointera yer açma
		urun_birimiPtr = urun_birimi;// Telefon ön Kamere sayisini tel_on_kamera atama 

		int* fiyatPtr;//Telefon Arka kamera icin pointera yer açma
		fiyatPtr = fiyat;// Telefon Arka Kamere sayisini tel_arka_kamera atama 						

		string* marka_adPtr; //Telefon Urun Kodu icin pointera yer açma
		marka_adPtr = marka_ad; // Telefon urun kodunu tel_urun_kodPtr atama 						

		for (int i = 0; i < count; i = i + 2) {

			//Bu sutun pointerýn içindeki elemaný yazdýrýyor					//Bu sutun pointerýn içindeki elemaný yazdýrýyor

			cout << "Marka : " << *(urun_kod + i) << "\t\t\t\t|\t" << "Marka : " << *(urun_kod + (i + 1)) << endl;

			cout << "Fiyat : " << *(urun_ad + i) << "\t\t\t\t|\t" << "Fiyat : " << *(urun_ad + (i + 1)) << endl;

			cout << "On kamera :" << *(urun_miktar + i) << "\t\t\t\t|\t" << "On kamera : " << *(urun_miktar + (i + 1)) << endl;

			cout << "Arka kamera : " << *(urun_birimi + i) << "\t\t\t|\t" << "Arka kamera : " << *(urun_birimi + (i + 1)) << endl;

			cout << "RAM : " << *(fiyat + i) << "\t\t\t\t|\t" << "RAM : " << *(fiyat + (i + 1)) << endl;

			cout << "Urunun Kodu : " << *(marka_ad + i) << "\t\t\t|\t" << "Urunun Kodu : " << *(marka_ad + (i + 1)) << " \n\n" << endl;




		}

		Dosya_Okunur.close(); // dosya kapanýr

		string yaz_marka_ad;
		int yaz_fiyat;
		int yaz_urun_miktar;
		string yaz_urun_ad;
		int yaz_urun_kod;
		string yaz_urun_birimi;
		int yine_urun_ekleme;

		//cout << "urun kodunu girin.... " ; cin >> proje_urun_ekleme;

		ofstream DosyaYazma;

		DosyaYazma.open("Tema_Istanbul.txt", ios::app);
		do {
			cout << "Marka Adini Girin : "; 								 cin >> yaz_marka_ad;

			cout << "Urun Fiyati Girin : "; 								 cin >> yaz_fiyat;

			cout << "Urunun miktarini : "; 	                                 cin >> yaz_urun_miktar;

			cout << "Urunun Ad  : ";	                                     cin >> yaz_urun_ad;

			cout << "Kodu giriniz : ";										 cin >> yaz_urun_kod;

			cout << "Birimini Giriniz : "; 						             cin >> yaz_urun_birimi;


			DosyaYazma << "\n" << yaz_urun_kod << " " << yaz_urun_ad << " " << yaz_urun_miktar << " " << yaz_urun_birimi << " " << yaz_fiyat << " " << yaz_marka_ad;

			cout << "Urun basariyla Eklenmistir...\n Baska Urun Eklemek icin 1'e basiniz...\nSatici Menusune Donmek icin farkli tusa basiniz "; cin >> yine_urun_ekleme;

		} while (yine_urun_ekleme == 1);


		DosyaYazma.close();
	}
	if (proje_urun_ekleme == 2) {

		giris hakedis_aktarma;

		return hakedis_aktarma.Giris();
	}
	else {

		return 0;
	}

}


//Projenin hakedis hesaplar ve ekrana yazdirir ve projeye urun eklenir
int dosyaIslemleri::Istek_Istanbul()
{
	string marka_ad[30];//telefon için marka adlarý

	string urun_ad[30];

	int urun_miktar[30];

	string urun_birimi[30];

	int fiyat[30];//telefon için fiyat dizisi

	string urun_kod[30];//urun kodu dizisi

	int toplam[30];


	int proje_urun_ekleme;
	int harcanan = 0;
	int count = 0;
	string line;

	ifstream okumaDosyasi;
	okumaDosyasi.open("Istek_Istanbul"".txt");

	ifstream file("Istek_Istanbul.txt");

	while (getline(file, line))
	{
		count++;
	}
	ifstream Dosya_Okunur;

	Dosya_Okunur.open("Istek_Istanbul.txt", ios::in);

	while (!Dosya_Okunur.eof())
	{
		for (int i = 0; i < count; i++) {
			Dosya_Okunur >> urun_kod[i] >> urun_ad[i] >> urun_miktar[i] >> urun_birimi[i] >> fiyat[i] >> marka_ad[i];
		}

	}

	cout << "Urun Kod " << setw(20) << "Urun Ad" << setw(20) << "Urun miktar" << setw(20) << "Urun Birimi" << setw(20) << "Urun birim fiyati" << setw(20) << " Marka Ad" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < count; i++)
	{
		cout << urun_kod[i] << setw(20) << urun_ad[i] << setw(20) << urun_miktar[i] << setw(20) << urun_birimi[i] << setw(20) << fiyat[i] << setw(20) << marka_ad[i] << "\n" << endl;

		toplam[i] = urun_miktar[i] * fiyat[i];
	}
	for (int i = 0; i < count; i++)
	{
		harcanan += toplam[i];
	}
	cout << "   +" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

	cout << "Proje Maliyeti  = " << harcanan << endl;
	Dosya_Okunur.close();

	cout << "Urun eklemek icin 1 e basiniz" << endl;
	cout << "Ana menu icin 2 e basiniz" << endl;
	cout << "Cikis icin farkli bir tusa" << endl;
	cin >> proje_urun_ekleme;


	if (proje_urun_ekleme == 1) {




		okumaDosyasi.open("urun_bilgileri"".txt");

		//  ifstream file("urun_bilgileri.txt");

		while (getline(file, line))
		{
			count++;
		}
		// ifstream Dosya_Okunur;

		Dosya_Okunur.open("urun_bilgileri.txt", ios::in);

		while (!Dosya_Okunur.eof())
		{
			for (int i = 0; i < count; i++) {
				Dosya_Okunur >> urun_kod[i] >> urun_ad[i] >> urun_miktar[i] >> urun_birimi[i] >> fiyat[i] >> marka_ad[i];
			}

		}


		string* urun_kodPtr;//Telefon marka ad için poþntera yer açma
		urun_kodPtr = urun_kod;//Telefon markadýný tel_marka_ad atama

		string* urun_adPtr;//Telefon marka ad için poþntera yer açma
		urun_adPtr = urun_ad;//Telefon markadýný tel_marka_ad atama

		int* urun_miktarPtr;//Telefon fiyat icin pointera yer açma
		urun_miktarPtr = urun_miktar;// Telefon fiyatini tel_fiyatPtr atama 

		string* urun_birimiPtr;//Telefon on kamera icin pointera yer açma
		urun_birimiPtr = urun_birimi;// Telefon ön Kamere sayisini tel_on_kamera atama 

		int* fiyatPtr;//Telefon Arka kamera icin pointera yer açma
		fiyatPtr = fiyat;// Telefon Arka Kamere sayisini tel_arka_kamera atama 						

		string* marka_adPtr; //Telefon Urun Kodu icin pointera yer açma
		marka_adPtr = marka_ad; // Telefon urun kodunu tel_urun_kodPtr atama 						

		for (int i = 0; i < count; i = i + 2) {

			//Bu sutun pointerýn içindeki elemaný yazdýrýyor					//Bu sutun pointerýn içindeki elemaný yazdýrýyor

			cout << "Marka : " << *(urun_kod + i) << "\t\t\t\t|\t" << "Marka : " << *(urun_kod + (i + 1)) << endl;

			cout << "Fiyat : " << *(urun_ad + i) << "\t\t\t\t|\t" << "Fiyat : " << *(urun_ad + (i + 1)) << endl;

			cout << "On kamera :" << *(urun_miktar + i) << "\t\t\t\t|\t" << "On kamera : " << *(urun_miktar + (i + 1)) << endl;

			cout << "Arka kamera : " << *(urun_birimi + i) << "\t\t\t|\t" << "Arka kamera : " << *(urun_birimi + (i + 1)) << endl;

			cout << "RAM : " << *(fiyat + i) << "\t\t\t\t|\t" << "RAM : " << *(fiyat + (i + 1)) << endl;

			cout << "Urunun Kodu : " << *(marka_ad + i) << "\t\t\t|\t" << "Urunun Kodu : " << *(marka_ad + (i + 1)) << " \n\n" << endl;




		}

		Dosya_Okunur.close(); // dosya kapanýr

		string yaz_marka_ad;
		int yaz_fiyat;
		int yaz_urun_miktar;
		string yaz_urun_ad;
		int yaz_urun_kod;
		string yaz_urun_birimi;
		int yine_urun_ekleme;

		//cout << "urun kodunu girin.... " ; cin >> proje_urun_ekleme;

		ofstream DosyaYazma;

		DosyaYazma.open("Istek_Istanbul.txt", ios::app);
		do {
			cout << "Marka Adini Girin : "; 								 cin >> yaz_marka_ad;

			cout << "Urun Fiyati Girin : "; 								 cin >> yaz_fiyat;

			cout << "Urunun miktarini : "; 	                                 cin >> yaz_urun_miktar;

			cout << "Urunun Ad  : ";	                                     cin >> yaz_urun_ad;

			cout << "Kodu giriniz : ";										 cin >> yaz_urun_kod;

			cout << "Birimini Giriniz : "; 						             cin >> yaz_urun_birimi;


			DosyaYazma << "\n" << yaz_urun_kod << " " << yaz_urun_ad << " " << yaz_urun_miktar << " " << yaz_urun_birimi << " " << yaz_fiyat << " " << yaz_marka_ad;

			cout << "Urun basariyla Eklenmistir...\n Baska Urun Eklemek icin 1'e basiniz...\nSatici Menusune Donmek icin farkli tusa basiniz "; cin >> yine_urun_ekleme;

		} while (yine_urun_ekleme == 1);


		DosyaYazma.close();
	}
	if (proje_urun_ekleme == 2) {

		giris hakedis_aktarma;

		return hakedis_aktarma.Giris();
	}
	else {

		return 0;
	}

}


//Projenin hakedis hesaplar ve ekrana yazdirir ve projeye urun eklenir
int dosyaIslemleri::Alyans_Rezidans()
{
	string marka_ad[30];//telefon için marka adlarý

	string urun_ad[30];

	int urun_miktar[30];

	string urun_birimi[30];

	int fiyat[30];//telefon için fiyat dizisi

	string urun_kod[30];//urun kodu dizisi

	int toplam[30];


	int proje_urun_ekleme;
	int harcanan = 0;
	int count = 0;
	string line;

	ifstream okumaDosyasi;
	okumaDosyasi.open("Alyans_Rezidans"".txt");

	ifstream file("Alyans_Rezidans.txt");

	while (getline(file, line))
	{
		count++;
	}
	ifstream Dosya_Okunur;

	Dosya_Okunur.open("Alyans_Rezidans.txt", ios::in);

	while (!Dosya_Okunur.eof())
	{
		for (int i = 0; i < count; i++) {
			Dosya_Okunur >> urun_kod[i] >> urun_ad[i] >> urun_miktar[i] >> urun_birimi[i] >> fiyat[i] >> marka_ad[i];
		}

	}

	cout << "Urun Kod " << setw(20) << "Urun Ad" << setw(20) << "Urun miktar" << setw(20) << "Urun Birimi" << setw(20) << "Urun birim fiyati" << setw(20) << " Marka Ad" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < count; i++)
	{
		cout << urun_kod[i] << setw(20) << urun_ad[i] << setw(20) << urun_miktar[i] << setw(20) << urun_birimi[i] << setw(20) << fiyat[i] << setw(20) << marka_ad[i] << "\n" << endl;

		toplam[i] = urun_miktar[i] * fiyat[i];
	}
	for (int i = 0; i < count; i++)
	{
		harcanan += toplam[i];
	}
	cout << "   +" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

	cout << "Proje Maliyeti  = " << harcanan << endl;
	Dosya_Okunur.close();

	cout << "Urun eklemek icin 1 e basiniz" << endl;
	cout << "Ana menu icin 2 e basiniz" << endl;
	cout << "Cikis icin farkli bir tusa" << endl;
	cin >> proje_urun_ekleme;


	if (proje_urun_ekleme == 1) {




		okumaDosyasi.open("urun_bilgileri"".txt");

		//  ifstream file("urun_bilgileri.txt");

		while (getline(file, line))
		{
			count++;
		}
		// ifstream Dosya_Okunur;

		Dosya_Okunur.open("urun_bilgileri.txt", ios::in);

		while (!Dosya_Okunur.eof())
		{
			for (int i = 0; i < count; i++) {
				Dosya_Okunur >> urun_kod[i] >> urun_ad[i] >> urun_miktar[i] >> urun_birimi[i] >> fiyat[i] >> marka_ad[i];
			}

		}


		string* urun_kodPtr;//Telefon marka ad için poþntera yer açma
		urun_kodPtr = urun_kod;//Telefon markadýný tel_marka_ad atama

		string* urun_adPtr;//Telefon marka ad için poþntera yer açma
		urun_adPtr = urun_ad;//Telefon markadýný tel_marka_ad atama

		int* urun_miktarPtr;//Telefon fiyat icin pointera yer açma
		urun_miktarPtr = urun_miktar;// Telefon fiyatini tel_fiyatPtr atama 

		string* urun_birimiPtr;//Telefon on kamera icin pointera yer açma
		urun_birimiPtr = urun_birimi;// Telefon ön Kamere sayisini tel_on_kamera atama 

		int* fiyatPtr;//Telefon Arka kamera icin pointera yer açma
		fiyatPtr = fiyat;// Telefon Arka Kamere sayisini tel_arka_kamera atama 						

		string* marka_adPtr; //Telefon Urun Kodu icin pointera yer açma
		marka_adPtr = marka_ad; // Telefon urun kodunu tel_urun_kodPtr atama 						

		for (int i = 0; i < count; i = i + 2) {

			//Bu sutun pointerýn içindeki elemaný yazdýrýyor					//Bu sutun pointerýn içindeki elemaný yazdýrýyor

			cout << "Marka : " << *(urun_kod + i) << "\t\t\t\t|\t" << "Marka : " << *(urun_kod + (i + 1)) << endl;

			cout << "Fiyat : " << *(urun_ad + i) << "\t\t\t\t|\t" << "Fiyat : " << *(urun_ad + (i + 1)) << endl;

			cout << "On kamera :" << *(urun_miktar + i) << "\t\t\t\t|\t" << "On kamera : " << *(urun_miktar + (i + 1)) << endl;

			cout << "Arka kamera : " << *(urun_birimi + i) << "\t\t\t|\t" << "Arka kamera : " << *(urun_birimi + (i + 1)) << endl;

			cout << "RAM : " << *(fiyat + i) << "\t\t\t\t|\t" << "RAM : " << *(fiyat + (i + 1)) << endl;

			cout << "Urunun Kodu : " << *(marka_ad + i) << "\t\t\t|\t" << "Urunun Kodu : " << *(marka_ad + (i + 1)) << " \n\n" << endl;




		}

		Dosya_Okunur.close(); // dosya kapanýr

		string yaz_marka_ad;
		int yaz_fiyat;
		int yaz_urun_miktar;
		string yaz_urun_ad;
		int yaz_urun_kod;
		string yaz_urun_birimi;
		int yine_urun_ekleme;

		//cout << "urun kodunu girin.... " ; cin >> proje_urun_ekleme;

		ofstream DosyaYazma;

		DosyaYazma.open("Alyans_Rezidans.txt", ios::app);
		do {
			cout << "Marka Adini Girin : "; 								 cin >> yaz_marka_ad;

			cout << "Urun Fiyati Girin : "; 								 cin >> yaz_fiyat;

			cout << "Urunun miktarini : "; 	                                 cin >> yaz_urun_miktar;

			cout << "Urunun Ad  : ";	                                     cin >> yaz_urun_ad;

			cout << "Kodu giriniz : ";										 cin >> yaz_urun_kod;

			cout << "Birimini Giriniz : "; 						             cin >> yaz_urun_birimi;


			DosyaYazma << "\n" << yaz_urun_kod << " " << yaz_urun_ad << " " << yaz_urun_miktar << " " << yaz_urun_birimi << " " << yaz_fiyat << " " << yaz_marka_ad;

			cout << "Urun basariyla Eklenmistir...\n Baska Urun Eklemek icin 1'e basiniz...\nSatici Menusune Donmek icin farkli tusa basiniz "; cin >> yine_urun_ekleme;

		} while (yine_urun_ekleme == 1);


		DosyaYazma.close();
	}
	if (proje_urun_ekleme == 2) {

		giris hakedis_aktarma;

		return hakedis_aktarma.Giris();
	}
	else {

		return 0;
	}

}

//Projenin hakedis hesaplar ve ekrana yazdirir ve projeye urun eklenir

int dosyaIslemleri::Finans_Sehir()
{
	string marka_ad[30];//telefon için marka adlarý

	string urun_ad[30];

	int urun_miktar[30];

	string urun_birimi[30];

	int fiyat[30];//telefon için fiyat dizisi

	string urun_kod[30];//urun kodu dizisi

	int toplam[30];


	int proje_urun_ekleme;
	int harcanan = 0;
	int count = 0;
	string line;

	ifstream okumaDosyasi;
	okumaDosyasi.open("Finans_Sehir"".txt");

	ifstream file("Finans_Sehir.txt");

	while (getline(file, line))
	{
		count++;
	}
	ifstream Dosya_Okunur;

	Dosya_Okunur.open("Finans_Sehir.txt", ios::in);

	while (!Dosya_Okunur.eof())
	{
		for (int i = 0; i < count; i++) {
			Dosya_Okunur >> urun_kod[i] >> urun_ad[i] >> urun_miktar[i] >> urun_birimi[i] >> fiyat[i] >> marka_ad[i];
		}

	}

	cout << "Urun Kod " << setw(20) << "Urun Ad" << setw(20) << "Urun miktar" << setw(20) << "Urun Birimi" << setw(20) << "Urun birim fiyati" << setw(20) << " Marka Ad" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < count; i++)
	{
		cout << urun_kod[i] << setw(20) << urun_ad[i] << setw(20) << urun_miktar[i] << setw(20) << urun_birimi[i] << setw(20) << fiyat[i] << setw(20) << marka_ad[i] << "\n" << endl;

		toplam[i] = urun_miktar[i] * fiyat[i];
	}
	for (int i = 0; i < count; i++)
	{
		harcanan += toplam[i];
	}
	cout << "   +" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

	cout << "Proje Maliyeti  = " << harcanan << endl;
	Dosya_Okunur.close();

	cout << "Urun eklemek icin 1 e basiniz" << endl;
	cout << "Ana menu icin 2 e basiniz" << endl;
	cout << "Cikis icin farkli bir tusa" << endl;
	cin >> proje_urun_ekleme;


	if (proje_urun_ekleme == 1) {




		okumaDosyasi.open("urun_bilgileri"".txt");

		//  ifstream file("urun_bilgileri.txt");

		while (getline(file, line))
		{
			count++;
		}
		// ifstream Dosya_Okunur;

		Dosya_Okunur.open("urun_bilgileri.txt", ios::in);

		while (!Dosya_Okunur.eof())
		{
			for (int i = 0; i < count; i++) {
				Dosya_Okunur >> urun_kod[i] >> urun_ad[i] >> urun_miktar[i] >> urun_birimi[i] >> fiyat[i] >> marka_ad[i];
			}

		}


		string* urun_kodPtr;//Telefon marka ad için poþntera yer açma
		urun_kodPtr = urun_kod;//Telefon markadýný tel_marka_ad atama

		string* urun_adPtr;//Telefon marka ad için poþntera yer açma
		urun_adPtr = urun_ad;//Telefon markadýný tel_marka_ad atama

		int* urun_miktarPtr;//Telefon fiyat icin pointera yer açma
		urun_miktarPtr = urun_miktar;// Telefon fiyatini tel_fiyatPtr atama 

		string* urun_birimiPtr;//Telefon on kamera icin pointera yer açma
		urun_birimiPtr = urun_birimi;// Telefon ön Kamere sayisini tel_on_kamera atama 

		int* fiyatPtr;//Telefon Arka kamera icin pointera yer açma
		fiyatPtr = fiyat;// Telefon Arka Kamere sayisini tel_arka_kamera atama 						

		string* marka_adPtr; //Telefon Urun Kodu icin pointera yer açma
		marka_adPtr = marka_ad; // Telefon urun kodunu tel_urun_kodPtr atama 						

		for (int i = 0; i < count; i = i + 2) {

			//Bu sutun pointerýn içindeki elemaný yazdýrýyor					//Bu sutun pointerýn içindeki elemaný yazdýrýyor

			cout << "Marka : " << *(urun_kod + i) << "\t\t\t\t|\t" << "Marka : " << *(urun_kod + (i + 1)) << endl;

			cout << "Fiyat : " << *(urun_ad + i) << "\t\t\t\t|\t" << "Fiyat : " << *(urun_ad + (i + 1)) << endl;

			cout << "On kamera :" << *(urun_miktar + i) << "\t\t\t\t|\t" << "On kamera : " << *(urun_miktar + (i + 1)) << endl;

			cout << "Arka kamera : " << *(urun_birimi + i) << "\t\t\t|\t" << "Arka kamera : " << *(urun_birimi + (i + 1)) << endl;

			cout << "RAM : " << *(fiyat + i) << "\t\t\t\t|\t" << "RAM : " << *(fiyat + (i + 1)) << endl;

			cout << "Urunun Kodu : " << *(marka_ad + i) << "\t\t\t|\t" << "Urunun Kodu : " << *(marka_ad + (i + 1)) << " \n\n" << endl;




		}

		Dosya_Okunur.close(); // dosya kapanýr

		string yaz_marka_ad;
		int yaz_fiyat;
		int yaz_urun_miktar;
		string yaz_urun_ad;
		int yaz_urun_kod;
		string yaz_urun_birimi;
		int yine_urun_ekleme;

		//cout << "urun kodunu girin.... " ; cin >> proje_urun_ekleme;

		ofstream DosyaYazma;

		DosyaYazma.open("Finans_Sehir.txt", ios::app);
		do {
			cout << "Marka Adini Girin : "; 								 cin >> yaz_marka_ad;

			cout << "Urun Fiyati Girin : "; 								 cin >> yaz_fiyat;

			cout << "Urunun miktarini : "; 	                                 cin >> yaz_urun_miktar;

			cout << "Urunun Ad  : ";	                                     cin >> yaz_urun_ad;

			cout << "Kodu giriniz : ";										 cin >> yaz_urun_kod;

			cout << "Birimini Giriniz : "; 						             cin >> yaz_urun_birimi;


			DosyaYazma << "\n" << yaz_urun_kod << " " << yaz_urun_ad << " " << yaz_urun_miktar << " " << yaz_urun_birimi << " " << yaz_fiyat << " " << yaz_marka_ad;

			cout << "Urun basariyla Eklenmistir...\n Baska Urun Eklemek icin 1'e basiniz...\nSatici Menusune Donmek icin farkli tusa basiniz "; cin >> yine_urun_ekleme;

		} while (yine_urun_ekleme == 1);


		DosyaYazma.close();
	}
	if (proje_urun_ekleme == 2) {

		giris hakedis_aktarma;

		return hakedis_aktarma.Giris();
	}
	else {

		return 0;
	}

}

//Projenin hakedis hesaplar ve ekrana yazdirir ve projeye urun eklenir

int dosyaIslemleri::Istanbul_Kent()
{


	string marka_ad[30];//telefon için marka adlarý

	string urun_ad[30];

	int urun_miktar[30];

	string urun_birimi[30];

	int fiyat[30];//telefon için fiyat dizisi

	string urun_kod[30];//urun kodu dizisi

	int toplam[30];


	int proje_urun_ekleme;
	int harcanan = 0;
	int count = 0;
	string line;

	ifstream okumaDosyasi;
	okumaDosyasi.open("Istanbul_Kent"".txt");

	ifstream file("Istanbul_Kent.txt");

	while (getline(file, line))
	{
		count++;
	}
	ifstream Dosya_Okunur;

	Dosya_Okunur.open("Istanbul_Kent.txt", ios::in);

	while (!Dosya_Okunur.eof())
	{
		for (int i = 0; i < count; i++) {
			Dosya_Okunur >> urun_kod[i] >> urun_ad[i] >> urun_miktar[i] >> urun_birimi[i] >> fiyat[i] >> marka_ad[i];
		}

	}

	cout << "Urun Kod " << setw(20) << "Urun Ad" << setw(20) << "Urun miktar" << setw(20) << "Urun Birimi" << setw(20) << "Urun birim fiyati" << setw(20) << " Marka Ad" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < count; i++)
	{
		cout << urun_kod[i] << setw(20) << urun_ad[i] << setw(20) << urun_miktar[i] << setw(20) << urun_birimi[i] << setw(20) << fiyat[i] << setw(20) << marka_ad[i] << "\n" << endl;

		toplam[i] = urun_miktar[i] * fiyat[i];
	}
	for (int i = 0; i < count; i++)
	{
		harcanan += toplam[i];
	}
	cout << "   +" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

	cout << "Proje Maliyeti  = " << harcanan << endl;
	Dosya_Okunur.close();

	cout << "Urun eklemek icin 1 e basiniz" << endl;
	cout << "Ana menu icin 2 e basiniz" << endl;
	cout << "Cikis icin farkli bir tusa" << endl;
	cin >> proje_urun_ekleme;


	if (proje_urun_ekleme == 1) {




		okumaDosyasi.open("urun_bilgileri"".txt");

		//  ifstream file("urun_bilgileri.txt");

		while (getline(file, line))
		{
			count++;
		}
		// ifstream Dosya_Okunur;

		Dosya_Okunur.open("urun_bilgileri.txt", ios::in);

		while (!Dosya_Okunur.eof())
		{
			for (int i = 0; i < count; i++) {
				Dosya_Okunur >> urun_kod[i] >> urun_ad[i] >> urun_miktar[i] >> urun_birimi[i] >> fiyat[i] >> marka_ad[i];
			}

		}


		string* urun_kodPtr;//Telefon marka ad için poþntera yer açma
		urun_kodPtr = urun_kod;//Telefon markadýný tel_marka_ad atama

		string* urun_adPtr;//Telefon marka ad için poþntera yer açma
		urun_adPtr = urun_ad;//Telefon markadýný tel_marka_ad atama

		int* urun_miktarPtr;//Telefon fiyat icin pointera yer açma
		urun_miktarPtr = urun_miktar;// Telefon fiyatini tel_fiyatPtr atama 

		string* urun_birimiPtr;//Telefon on kamera icin pointera yer açma
		urun_birimiPtr = urun_birimi;// Telefon ön Kamere sayisini tel_on_kamera atama 

		int* fiyatPtr;//Telefon Arka kamera icin pointera yer açma
		fiyatPtr = fiyat;// Telefon Arka Kamere sayisini tel_arka_kamera atama 						

		string* marka_adPtr; //Telefon Urun Kodu icin pointera yer açma
		marka_adPtr = marka_ad; // Telefon urun kodunu tel_urun_kodPtr atama 						

		for (int i = 0; i < count; i = i + 2) {

			//Bu sutun pointerýn içindeki elemaný yazdýrýyor					//Bu sutun pointerýn içindeki elemaný yazdýrýyor

			cout << "Marka : " << *(urun_kod + i) << "\t\t\t\t|\t" << "Marka : " << *(urun_kod + (i + 1)) << endl;

			cout << "Fiyat : " << *(urun_ad + i) << "\t\t\t\t|\t" << "Fiyat : " << *(urun_ad + (i + 1)) << endl;

			cout << "On kamera :" << *(urun_miktar + i) << "\t\t\t\t|\t" << "On kamera : " << *(urun_miktar + (i + 1)) << endl;

			cout << "Arka kamera : " << *(urun_birimi + i) << "\t\t\t|\t" << "Arka kamera : " << *(urun_birimi + (i + 1)) << endl;

			cout << "RAM : " << *(fiyat + i) << "\t\t\t\t|\t" << "RAM : " << *(fiyat + (i + 1)) << endl;

			cout << "Urunun Kodu : " << *(marka_ad + i) << "\t\t\t|\t" << "Urunun Kodu : " << *(marka_ad + (i + 1)) << " \n\n" << endl;




		}

		Dosya_Okunur.close(); // dosya kapanýr

		string yaz_marka_ad;
		int yaz_fiyat;
		int yaz_urun_miktar;
		string yaz_urun_ad;
		int yaz_urun_kod;
		string yaz_urun_birimi;
		int yine_urun_ekleme;

		//cout << "urun kodunu girin.... " ; cin >> proje_urun_ekleme;

		ofstream DosyaYazma;

		DosyaYazma.open("Istanbul_Kent.txt", ios::app);
		do {
			cout << "Marka Adini Girin : "; 								 cin >> yaz_marka_ad;

			cout << "Urun Fiyati Girin : "; 								 cin >> yaz_fiyat;

			cout << "Urunun miktarini : "; 	                                 cin >> yaz_urun_miktar;

			cout << "Urunun Ad  : ";	                                     cin >> yaz_urun_ad;

			cout << "Kodu giriniz : ";										 cin >> yaz_urun_kod;

			cout << "Birimini Giriniz : "; 						             cin >> yaz_urun_birimi;


			DosyaYazma << "\n" << yaz_urun_kod << " " << yaz_urun_ad << " " << yaz_urun_miktar << " " << yaz_urun_birimi << " " << yaz_fiyat << " " << yaz_marka_ad;

			cout << "Urun basariyla Eklenmistir...\n Baska Urun Eklemek icin 1'e basiniz...\nSatici Menusune Donmek icin farkli tusa basiniz "; cin >> yine_urun_ekleme;

		} while (yine_urun_ekleme == 1);


		DosyaYazma.close();
	}
	if (proje_urun_ekleme == 2) {

		giris hakedis_aktarma;

		return hakedis_aktarma.Giris();
	}
	else {

		return 0;
	}


}