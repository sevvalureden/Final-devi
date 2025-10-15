#include <stdio.h>

// --- Renk Kodlarý için Tanýmlamalar ---
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int getSingleDigit(const char* prompt) { //sistem tanýmlara 
    int number; // Sadece bir tane sayý deðiþkeni yeterli
    int input_status;

    do {
        printf("%s" ANSI_COLOR_RED " (0 dan 9 a kadar herhangi bir sayi giriniz) "ANSI_COLOR_RESET ":", prompt);
        input_status = scanf("%d", &number); // number için deðiþken tam sayý


        if (input_status != 1) { //doðrulu deðerini kontrol eder
            printf(ANSI_COLOR_RED "Lutfen gecerli bir rakam giriniz!\n" ANSI_COLOR_RESET); //mesaj
            while (getchar() != '\n');  //do komutunun çalýþmasý için koþul
        } else if (number < 0 || number > 9) {  // istenilen deðerler arasýnda kalmasý için
            printf(ANSI_COLOR_RED "okuma yazman yok mu? hata!\n" ANSI_COLOR_RESET);  //hata mesajý
        }

    } while (input_status != 1 || number < 0 || number > 9); //girdi yanlýþsa baþa sarmasý için koþul

    // Sadece bir tane return olmalý ve doðru deðiþkeni döndürmeli
    return number;
}

int main() {
    int x, y, result; //x y ve sonuç için tanýmlama

    do {
        printf("\n" ANSI_COLOR_YELLOW "----------------------------------------\n" ANSI_COLOR_RESET);
        
        x = getSingleDigit("Lütfen birinci sayýyý giriniz");  //x için tek deðer alma 
        // 2. Çaðrý: 'y' için bir sayý alýr
        y = getSingleDigit("Lütfen ikinci sayýyý giriniz");  //y için tek deðer alma 
 
        result = x + y; // sonucu x+y olarak tanýmla
        printf("\n" ANSI_COLOR_GREEN "Sonuç: %d + %d = %d\n" ANSI_COLOR_RESET, x, y, result);

        if (result > 9) {
            printf(ANSI_COLOR_RED "Toplam 9'dan büyük olamaz! Lütfen sayýlarý tekrar giriniz.\n" ANSI_COLOR_RESET);
        }

    } while (result > 9);

    // --- Baþarýlý Sonuç Ekraný ---
    printf("\n\n" ANSI_COLOR_GREEN ">>> Girdi Baþarýlý: Toplam 0-9 Aralýðýnda <<<\n" ANSI_COLOR_RESET);
    printf("Girilen Birinci Sayý: %d\n", x);
    printf("Girilen Ýkinci Sayý: %d\n", y);
    printf("Sayýlarýn Toplamý: %d\n", result);

    printf("\n--- Rakam Karakterlerinin ASCII Karþýlýklarý ---\n");
    printf("'%c' karakterinin (Sayý %d) ASCII Kodu: %d\n", (char)(x + '0'), x, (x + '0'));  //ASCII kodu 48+x þeklinde tanýmladým 
    printf("'%c' karakterinin (Sayý %d) ASCII Kodu: %d\n", (char)(y + '0'), y, (y + '0'));  //ASCII kodu 48+y þeklinde tanýmladým 
    printf("'%c' karakterinin (Sonuç %d) ASCII Kodu: %d\n", (char)(result + '0'), result, (result + '0')); //ASCII kodu 48+x+y þeklinde tanýmladým 

    return 0;
}
