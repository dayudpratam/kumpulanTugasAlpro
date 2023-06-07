#include <stdio.h>

int main() {
   float bil1, bil2, bil3, hasil;
   char operator;

   printf("Masukkan bilangan pertama: ");
   scanf("%f", &bil1);
   printf("Masukkan bilangan kedua: ");
   scanf("%f", &bil2);
   printf("Masukkan bilangan ketiga: ");
   scanf("%f", &bil3);

   printf("Masukkan operator (+, -, *, /): ");
   scanf(" %c", &operator);

   switch(operator) {
      case '+':
         hasil = bil1 + bil2 + bil3;
         printf("%.2f + %.2f + %.2f = %.2f", bil1, bil2, bil3, hasil);
         break;

      case '-':
         hasil = bil1 - bil2 - bil3;
         printf("%.2f - %.2f - %.2f = %.2f", bil1, bil2, bil3, hasil);
         break;

      case '*':
         hasil = bil1 * bil2 * bil3;
         printf("%.2f * %.2f * %.2f = %.2f", bil1, bil2, bil3, hasil);
         break;

      case '/':
         if(bil2 == 0 || bil3 == 0) {
            printf("Error: Bilangan kedua atau ketiga tidak boleh nol!");
         }
         else {
            hasil = bil1 / bil2 / bil3;
            printf("%.2f / %.2f / %.2f = %.2f", bil1, bil2, bil3, hasil);
         }
         break;

      default:
         printf("Error: Operator yang dimasukkan tidak valid!");
   }

   return 0;
}
