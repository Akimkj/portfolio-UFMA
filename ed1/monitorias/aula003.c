#include <stdio.h>
#include <string.h>
/*int main() {
    char str1[20] = "Hello, ";
   char str2[] = "World!";
   strncat(str1, str2, 3);
   printf("strncat(): %s\n", str1);
   return 0;
}*/

int main() {
char sentence[] = "This is a sample sentence.";
char *ptr = strchr(sentence, 'a');
printf("strchr(): %s\n", ptr);
return 0;
}