#include "hangman_helpers.h"
int main(int argc, char *argv[]) {
    char secret[MAX_LENGTH + 1];
    if (argc != 2) {
        printf("wrong number of arguments\n");
        fprintf(stderr, "usage: %s <secret word or phrase>\n", argv[0]);
        printf("if the secret is multiple words, you must quote it\n");
        return 1;
    }
    strcpy(secret, argv[1]);
    if (!validate_secret(secret)) {
        return 1;
    }
    char guessed[MAX_LENGTH + 1];
    int badGuess = 0;
    for (int i = 0; i < (int) strlen(secret); i++) {
        char c = secret[i];
        if (c == ' ' || c == '\'' || c == '-') {
            guessed[i] = c;
        } else {
            guessed[i] = '_';
        }
    }
    guessed[strlen(secret)] = '\0';
    int gameStatus = 1;
    char eliminatedLetters[MAX_LENGTH] = "";
    int numEliminated = 0;
    while (gameStatus) {
        printf("%s", CLEAR_SCREEN);
        printf("%s", arts[badGuess]);
        printf("\n");
        printf("\n");
        printf("    Phrase: %s\n", guessed);
        printf("Eliminated: ");
        char sortEliminated[MAX_LENGTH];
        for (int i = 0; i < numEliminated; i++) {
            sortEliminated[i] = eliminatedLetters[i];
        }
        for (int i = numEliminated - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (sortEliminated[j] > sortEliminated[j + 1]) {
                    char temp = sortEliminated[j];
                    sortEliminated[j] = sortEliminated[j + 1];
                    sortEliminated[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < numEliminated; i++) {
            printf("%c", sortEliminated[i]);
        }
        printf("\n");
        printf("\n");
        if (strchr(guessed, '_') == NULL) {
            printf("You win! The secret phrase was: %s\n", secret);
            gameStatus = 0;
            break;
        }
        if (badGuess == LOSING_MISTAKE) {
            printf("You lose! The secret phrase was: %s\n", secret);
            gameStatus = 0;
            break;
        }
        char guess = read_letter();
        while ((!is_lowercase_letter(guess) || string_contains_character(eliminatedLetters, guess)
                || string_contains_character(guessed, guess))) {
            guess = read_letter();
        }
        int correct = 0;
        for (int i = 0; i < (int) strlen(secret); i++) {
            if (secret[i] == guess) {
                guessed[i] = guess;
                correct = 1;
            }
        }
        if (!correct) {
            eliminatedLetters[numEliminated] = guess;
            badGuess++;
            numEliminated++;
        }
    }
    return 0;
}
