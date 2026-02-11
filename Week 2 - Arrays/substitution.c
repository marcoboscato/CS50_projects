#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

/*
This is a program that implements a substitution cipher. The user provides a 26-character key, and the program substitutes each letter of the plaintext with the corresponding letter in the key to produce the ciphertext.
*/

bool check_KEY(string key);
void substitution(string text, string key);

int main(int argc, string argv[]){
    // first check if there is a command-line argument
    if (argc != 2){
        printf("Usage: ./substitution [KEY]\n");
        return 1;
    }
    // proceed with the program
    else{
        // check if the KEY is valid
        string KEY = argv[1];
        if (check_KEY(KEY) == false){
            return 1;
        }
        // ask for the plain text
        string text = get_string("plaintext: ");
        // do the substitution
        substitution(text, KEY);
    }
    return 0;
}

// helper functions
bool check_KEY(string key){
    // 1) check lenght:
    if (strlen(key) != 26){
        printf("Key must constain 26 characters.\n");
        return false;
    }
    else{
        // 2) check if the KEY is ONLY alphabetic
        int count[26] = {0};    // For a-z only

        for (int i = 0; key[i] != '\0'; i++){
            if (isalpha(key[i]) == 0){
                printf("Key must not constain alphanumeric characters.\n");
                return false;
            }
            else{
                // check if there are any repeated letters
                char c = tolower(key[i]);  // lowercase
                int index = c - 'a';       // different between ASCII values
                count[index]++;
                if (count[index] > 1){
                    printf("Key must not constain repeated characters.\n");
                    return false;
                }
            }
        }
        return true;
    }
}

void substitution(string text, string key){
    const char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int transport[26] = {0};
    int len_text = strlen(text);

    // create the transportation array values
    for (int i = 0; i < 26; i++){
        char c = tolower(key[i]);
        int differ = c - letters[i];
        transport[i] += differ;
    }

    char ciphertext[len_text];
    for (int i = 0; text[i] != '\0'; i++){
        // if the character in not a letter -> don't make changes
        if (isalpha(text[i]) == 0){
            ciphertext[i] = text[i];
        }
        else{
            // if the character is a letter:
            char temp_text = tolower(text[i]);
            // index inside the alphabetic AND transposition values
            int index = temp_text - 'a';
            // add the transposition values to the LOWERCASED character
            int new_char = temp_text + transport[index];
            if (islower(text[i]) == 0){
                ciphertext[i] = new_char - 32;
            }
            else{
                ciphertext[i] = new_char;
            }
        }
    }
    ciphertext[len_text] = '\0';
    printf("ciphertext: %s\n", ciphertext);
}