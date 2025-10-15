#include <stdio.h>

// --- Renk Kodlar� i�in Tan�mlamalar ---
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int getSingleDigit(const char* prompt) { //sistem tan�mlara 
    int number; // Sadece bir tane say� de�i�keni yeterli
    int input_status;

    do {
        printf("%s" ANSI_COLOR_RED " (0 dan 9 a kadar herhangi bir sayi giriniz) "ANSI_COLOR_RESET ":", prompt);
        input_status = scanf("%d", &number); // number i�in de�i�ken tam say�


        if (input_status != 1) { //do�rulu de�erini kontrol eder
            printf(ANSI_COLOR_RED "Lutfen gecerli bir rakam giriniz!\n" ANSI_COLOR_RESET); //mesaj
            while (getchar() != '\n');  //do komutunun �al��mas� i�in ko�ul
        } else if (number < 0 || number > 9) {  // istenilen de�erler aras�nda kalmas� i�in
            printf(ANSI_COLOR_RED "okuma yazman yok mu? hata!\n" ANSI_COLOR_RESET);  //hata mesaj�
        }

    } while (input_status != 1 || number < 0 || number > 9); //girdi yanl��sa ba�a sarmas� i�in ko�ul

    // Sadece bir tane return olmal� ve do�ru de�i�keni d�nd�rmeli
    return number;
}

int main() {
    int x, y, result; //x y ve sonu� i�in tan�mlama

    do {
        printf("\n" ANSI_COLOR_YELLOW "----------------------------------------\n" ANSI_COLOR_RESET);
        
        x = getSingleDigit("L�tfen birinci say�y� giriniz");  //x i�in tek de�er alma 
        // 2. �a�r�: 'y' i�in bir say� al�r
        y = getSingleDigit("L�tfen ikinci say�y� giriniz");  //y i�in tek de�er alma 
 
        result = x + y; // sonucu x+y olarak tan�mla
        printf("\n" ANSI_COLOR_GREEN "Sonu�: %d + %d = %d\n" ANSI_COLOR_RESET, x, y, result);

        if (result > 9) {
            printf(ANSI_COLOR_RED "Toplam 9'dan b�y�k olamaz! L�tfen say�lar� tekrar giriniz.\n" ANSI_COLOR_RESET);
        }

    } while (result > 9);

    // --- Ba�ar�l� Sonu� Ekran� ---
    printf("\n\n" ANSI_COLOR_GREEN ">>> Girdi Ba�ar�l�: Toplam 0-9 Aral���nda <<<\n" ANSI_COLOR_RESET);
    printf("Girilen Birinci Say�: %d\n", x);
    printf("Girilen �kinci Say�: %d\n", y);
    printf("Say�lar�n Toplam�: %d\n", result);

    printf("\n--- Rakam Karakterlerinin ASCII Kar��l�klar� ---\n");
    printf("'%c' karakterinin (Say� %d) ASCII Kodu: %d\n", (char)(x + '0'), x, (x + '0'));  //ASCII kodu 48+x �eklinde tan�mlad�m 
    printf("'%c' karakterinin (Say� %d) ASCII Kodu: %d\n", (char)(y + '0'), y, (y + '0'));  //ASCII kodu 48+y �eklinde tan�mlad�m 
    printf("'%c' karakterinin (Sonu� %d) ASCII Kodu: %d\n", (char)(result + '0'), result, (result + '0')); //ASCII kodu 48+x+y �eklinde tan�mlad�m 

    return 0;
}
