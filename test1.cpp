#include <stdio.h>
#include <string.h>
int main() {
 // Example of Strings
 char str1[20] = "Hello";
 char str2[20] = "World";
 char str3[40];
 // Concatenating two strings using strcat
 strcpy(str3, str1);
 strcat(str3, " ");
 strcat(str3, str2);
 printf("Concatenated String: %s\n", str3);
 // Example of Arrays
 int numbers[] = {10, 20, 30, 40, 50};
 int array_size = sizeof(numbers) / sizeof(numbers[0]);
 printf("Array elements: ");
 for (int i = 0; i < array_size; i++) {
 printf("%d ", numbers[i]);
 }
 printf("\n");
 // Example of Pointers
 int x = 100;
 int *ptr = &x;
 printf("Value of x: %d\n", x);
 printf("Address of x: %p\n", (void*)&x);
 printf("Pointer ptr holds the address: %p\n", (void*)ptr);
 printf("Value pointed by ptr: %d\n", *ptr);

*ptr = 90;
 printf("Value of x: %d\n", x);
 printf("Value pointed by ptr: %d\n", *ptr);
 return 0;
}