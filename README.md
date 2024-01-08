# Hangman
The purpose of this program is to simulate a game of hangman where before entering the game, you must
enter a ”secret” word that will consequently be the word the user must guess. In the guessing stage of the
game, the player must guess certain letters and try to figure out the secret word in a certain amount of tries.
If the player surpasses the given amount of tries for the game, then the player loses and the secret word is
revealed.

After lots of debugging and head scratching wondering why my output was not exactly matching the reference
binary file, I was able to develop a successful program that properly ran the hangman game. I believe that
my code could have been a lot smoother and efficient as there was a concept I learned in discussion section
about how to track guessed letter with an array of Boolean values linked to each letter of the alphabet.
However, I was not quite able to grasp the concept and I ended up going with what I knew and simply
initializing a guessed letter array that would be looped every guess to sort alphabetically.
