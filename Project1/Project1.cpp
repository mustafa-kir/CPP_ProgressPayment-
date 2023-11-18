/****************************************************
**				SAKARYA ÜNİVERSİTESİ
** 			BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
** 				BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**					PROGRAMLAMAYA GİRİŞİ DERSİ
**
**
** ÖĞRENCİ ADI...............:Mustafa Kır
** ÖĞRENCİ NUMARASI.:s191210680
** DERS GRUBU…………:Programlaya Giriş
****************************************************************************/
#include <iostream>
#include "giris.h"
#include "dosyaIslemleri.h"

using namespace std;

int main()
{
    giris giris;

    giris.Giris();
    giris.giris;
    giris.pin;
    giris.Secim_Bir;
    giris.Secim_urun_kategori;
    giris.Secim_proje_kategori;


    dosyaIslemleri dosyaIslemeleri;

    dosyaIslemeleri.marka_ad;
    dosyaIslemeleri.fiyat;
    dosyaIslemeleri.urun_miktar;
    dosyaIslemeleri.urun_ad;
    dosyaIslemeleri.urun_kod;
    dosyaIslemeleri.urun_birimi;


}

// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
