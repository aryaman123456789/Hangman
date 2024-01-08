#include "hangman_helpers.h"

bool is_lowercase_letter(char c) {
    return (c >= 'a' && c <= 'z');
}

bool validate_secret(const char *secret) {
    if (strlen(secret) > MAX_LENGTH) {
        printf("the secret phrase is over 256 characters\n");
        return false;
    }
    for (int i = 0; secret[i] != '\0'; i++) {
        char c = secret[i];
        if (!is_lowercase_letter(c) && c != ' ' && c != '\'' && c != '-') {
            printf("invalid character: '%c'\n", c);
            printf("the secret phrase must contain only lowercase letters, spaces, hyphens, and "
                   "apostrophes\n");
            return false;
        }
    }
    return true;
}

bool string_contains_character(const char *s, char c) {
    while (*s != '\0') {
        if (*s == c) {
            return true;
        }
        s++;
    }
    return false;
}
char read_letter(void) {
    char guess;
    printf("Guess a letter: ");
    guess = (char) getchar();
    while (getchar() != '\n')
        ;
    return guess;
}
