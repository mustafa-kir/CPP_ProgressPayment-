
#include <iostream>
using namespace std;
class dosyaIslemleri
{
public:

	int menu_donus;//menu donmek veya cikmak i�in kullan�lan integer geger
	int urun_ekleme_bolumu;//menu donuk veya cikmak i�in kullan�lan integer

	int urun_bilgileri_iki;
	int yine_urun_ekleme;// yeni �r�n eklemek i�in d�ng�de kullan�lan integer

	string cikarmaUrunKodu; // urun cikarma i�in kullan�lan string deger
	string CikarmaUrunKod; // urun cikarma i�in kullan�lan string deger
	string CikarUrunAd; // urun cikarma i�in kullan�lan string deger
	string CikarmaMiktar; // urun cikarma i�in kullan�lan string deger
	string CikarmaBirimi; // urun cikarma i�in kullan�lan string deger
	string CikarmaFiyat; // urun cikarma i�in kullan�lan string deger
	string CikarmaMarkaAd; // urun cikarma i�in kullan�lan string deger


	int aranan; // urun aramak i�in kullan�lan iteger deger




	string kontrol;//txt dosyas�ndan urun cikar�r�ken kontrol olusturan string 
	string marka_ad;//marka ad� tan�mlanan string
	string urun_ad;// urun ad� tan�mland��� string 
	string urun_miktar;// urun miktar�n�n tan�mlad��� string 
	string urun_birimi;// urun birimini tan�mlad��� string
	string urun_kod;// urun kodu tan�mlad��� string
	string fiyat;// fiyat� tan�mlad��� string
	string Proje_Durum;// proje durumunun tan�mlad��� string
	string CikarmaProjeKodu;// Proje cikar�rken Proje kodunun tan�mlad��� string
	string CikarmaProjeAdi;// Proje c�kar�rken Proje adinin tan�mlad��� string
	string CikarmaProjeFirmaAdi;// Proje c�kar�rken proje firma adinin tan�mlad��� string
	string CikarmaProjeSorumlusu;// Proje c�kar�r�ken proje sorumlusunun  tan�mlad��� string
	string CikarmaProjeKonum;// Proje c�kaririken proje konumunun tan�mlad��� string
	string CikarmaProjeDurum;// Proje c�kar�r�ken proje durumunun tan�mlad��� string
	string CikarmaProjeKod;// Proje c�kar�rken proje kodunu tan�mlad��� string 
	int urun_bilgileri_yazdir(); // urun_bilgileri_yazdir fonksiyonun tan�mlad��� yer
	int urun_bilgileri_ekle();// urun_bilgileri_ekle fonksiyonun tan�mlad��� yer
	int urun_cikar();// urun_cikar fonksiyonun tan�mlad��� yer
	int urun_arama();// urun_arama fonksiyonun tan�mlad��� yer
	int urunlerin_raporu();// urunlerin_raporu fonksiyonun tan�mlad��� yer
	int proje_bilgileri_yazdir();// proje_bilgileri_yazdir fonksiyonun tan�mlad��� yer
	int proje_bilgileri_ekle();// proje_bilgileri_ekle fonksiyonun tan�mlad��� yer
	int proje_cikar();// proje_cikar fonksiyonun tan�mlad��� yer
	int proje_raporu();// proje_raporu fonksiyonun tan�mlad��� yer


	int hakedishesaplama();//hakedis hesaplama fonsiyonun tan�m�
	int Trabzon_Rezidans();// proje ile ilgili bilgileri yazdiran fonksiyonunun tan�m�
	int Tema_Istanbul();// proje ile ilgili bilgileri yazdiran fonksiyonunun tan�m�
	int Istek_Istanbul();// proje ile ilgili bilgileri yazdiran fonksiyonunun tan�m�
	int Alyans_Rezidans();// proje ile ilgili bilgileri yazdiran fonksiyonunun tan�m�
	int Finans_Sehir();// proje ile ilgili bilgileri yazdiran fonksiyonunun tan�m�
	int Istanbul_Kent();// proje ile ilgili bilgileri yazdiran fonksiyonunun tan�m�
	int proje_tercih;//hangi projeye ge�mek istedi�i alan integer de�er
};
