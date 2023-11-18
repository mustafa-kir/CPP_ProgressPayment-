
#include <iostream>
using namespace std;
class dosyaIslemleri
{
public:

	int menu_donus;//menu donmek veya cikmak için kullanýlan integer geger
	int urun_ekleme_bolumu;//menu donuk veya cikmak için kullanýlan integer

	int urun_bilgileri_iki;
	int yine_urun_ekleme;// yeni ürün eklemek için döngüde kullanýlan integer

	string cikarmaUrunKodu; // urun cikarma için kullanýlan string deger
	string CikarmaUrunKod; // urun cikarma için kullanýlan string deger
	string CikarUrunAd; // urun cikarma için kullanýlan string deger
	string CikarmaMiktar; // urun cikarma için kullanýlan string deger
	string CikarmaBirimi; // urun cikarma için kullanýlan string deger
	string CikarmaFiyat; // urun cikarma için kullanýlan string deger
	string CikarmaMarkaAd; // urun cikarma için kullanýlan string deger


	int aranan; // urun aramak için kullanýlan iteger deger




	string kontrol;//txt dosyasýndan urun cikarýrýken kontrol olusturan string 
	string marka_ad;//marka adý tanýmlanan string
	string urun_ad;// urun adý tanýmlandýðý string 
	string urun_miktar;// urun miktarýnýn tanýmladýðý string 
	string urun_birimi;// urun birimini tanýmladýðý string
	string urun_kod;// urun kodu tanýmladýðý string
	string fiyat;// fiyatý tanýmladýðý string
	string Proje_Durum;// proje durumunun tanýmladýðý string
	string CikarmaProjeKodu;// Proje cikarýrken Proje kodunun tanýmladýðý string
	string CikarmaProjeAdi;// Proje cýkarýrken Proje adinin tanýmladýðý string
	string CikarmaProjeFirmaAdi;// Proje cýkarýrken proje firma adinin tanýmladýðý string
	string CikarmaProjeSorumlusu;// Proje cýkarýrýken proje sorumlusunun  tanýmladýðý string
	string CikarmaProjeKonum;// Proje cýkaririken proje konumunun tanýmladýðý string
	string CikarmaProjeDurum;// Proje cýkarýrýken proje durumunun tanýmladýðý string
	string CikarmaProjeKod;// Proje cýkarýrken proje kodunu tanýmladýðý string 
	int urun_bilgileri_yazdir(); // urun_bilgileri_yazdir fonksiyonun tanýmladýðý yer
	int urun_bilgileri_ekle();// urun_bilgileri_ekle fonksiyonun tanýmladýðý yer
	int urun_cikar();// urun_cikar fonksiyonun tanýmladýðý yer
	int urun_arama();// urun_arama fonksiyonun tanýmladýðý yer
	int urunlerin_raporu();// urunlerin_raporu fonksiyonun tanýmladýðý yer
	int proje_bilgileri_yazdir();// proje_bilgileri_yazdir fonksiyonun tanýmladýðý yer
	int proje_bilgileri_ekle();// proje_bilgileri_ekle fonksiyonun tanýmladýðý yer
	int proje_cikar();// proje_cikar fonksiyonun tanýmladýðý yer
	int proje_raporu();// proje_raporu fonksiyonun tanýmladýðý yer


	int hakedishesaplama();//hakedis hesaplama fonsiyonun tanýmý
	int Trabzon_Rezidans();// proje ile ilgili bilgileri yazdiran fonksiyonunun tanýmý
	int Tema_Istanbul();// proje ile ilgili bilgileri yazdiran fonksiyonunun tanýmý
	int Istek_Istanbul();// proje ile ilgili bilgileri yazdiran fonksiyonunun tanýmý
	int Alyans_Rezidans();// proje ile ilgili bilgileri yazdiran fonksiyonunun tanýmý
	int Finans_Sehir();// proje ile ilgili bilgileri yazdiran fonksiyonunun tanýmý
	int Istanbul_Kent();// proje ile ilgili bilgileri yazdiran fonksiyonunun tanýmý
	int proje_tercih;//hangi projeye geçmek istediði alan integer deðer
};
