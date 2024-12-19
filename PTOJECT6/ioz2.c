#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

int isPalindrome(const char* str) {
    int left = 0, right = strlen(str) - 1;

    while (left < right) {
        
        while (left < right && !isalnum((unsigned char)str[left])) {
            left++;
        }

        while (left < right && !isalnum((unsigned char)str[right])) {
            right--;
        }

        if (tolower((unsigned char)str[left]) != tolower((unsigned char)str[right])) {
            return 0;
        }

        left++;
        right--;
    }

    return 1;
}

int main() {
    setlocale(LC_ALL, "RU");
    char sentence[256];

    printf("Введите предложение: ");
    fgets(sentence, sizeof(sentence), stdin);

    sentence[strcspn(sentence, "\n")] = '\0';

    if (isPalindrome(sentence)) {
        printf("Предложение является палиндромом.\n");
    }
    else {
        printf("Предложение не является палиндромом.\n");
    }

    return 0;
}
