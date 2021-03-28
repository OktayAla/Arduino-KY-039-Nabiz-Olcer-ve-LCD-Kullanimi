//-----------------------------------------//
//----------------OKTAY ALA----------------//
//---Arduino | KY-039 Nabız Ölçer ve LCD---//
//-----------------------------------------//

#include <Wire.h> //Arduino ile I2C LCD Ekranın haberleşmesi için Wire kütüphanesini tanımlıyoruz
#include <LiquidCrystal_I2C.h> //I2C LCD Ekranımızın kütüphane tanımlamasını yapıyoruz

  const int nabizsensor = A0; //KY-039 Parmak nabız sensörünün pin tanımlamasını yapıyoruz

  LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); //Kullanacağımız ekranın pixel boyutunu tanımlıyoruz

//Nabız değerinin sensör verisi tarafından hesaplanabilmesi için, sensöre özel olan formülleri tanımlıyoruz
   double hesapdeger=0.75;
   int hesapbolum=20;
   double degertekrar=0.0;
   
void setup(void)
{
  pinMode(nabizsensor,INPUT); //Bağlı olan pinin bir INPUT, giriş türü olduğunu belirtiyoruz

  //LCD Ekranımızın arka ışığını ve çalışması için gereken kodları yazıyoruz
  lcd.init();
  lcd.backlight();
}

void loop(void)
{
   //Değerlerin kendi içinde hesaplanması için değişkenleri tanımlıyoruz
   static double eskideger=0;
   static double eskideger tekrar=0;
 
   //A0 pinine bağlı olan sensörümüzden gelen verileri, nabiz değişkenine atıyoruz
   int nabiz = analogRead(nabizsensor);
  
   //Nabız değerinin sensör verisi tarafından hesaplamasını yapıyoruz
   double deger = eskideger * hesapdeger + (0-hesapdeger) * nabiz;
   degertekrar = deger-eskideger;
  
  
   lcd.setCursor(0,0);
   lcd.print(" Nabiz Olcer "); 

   lcd.setCursor(0,1);
   lcd.print("  ");

   lcd.setCursor(0,1); 
   lcd.print(nabiz/10); 
//Sensör üzerinden gelen verileri nabiz değişkenine tanımladığımız için, ekran çıktısı olarak "nabiz" yazıyoruz

   //Nabız değerinin kendi içinde tekrarlayan verisinin üzerinden hesaplatma yaptırıyoruz
   eskideger = deger;
   eskidegertekrar = degertekrar;
   delay(hesapbolum*10);

}