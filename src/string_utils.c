#include "../include/string_utils.h"
#include <ctype.h>

/* Count characters until null terminator */
int my_strlen(const char* s) {
    int i = 0;
    while (s[i] != '\0') i++; // count each character
    return i;
}

/* Copy src into dest including null terminator */
char* my_strcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') { dest[i] = src[i]; i++; } // copy char by char
    dest[i] = '\0'; // add null terminator
    return dest;
}

/* Copy at most n characters, pad with null if needed */
char* my_strncpy(char* dest, const char* src, int n) {
    int i = 0;
    while (i < n && src[i] != '\0') { dest[i] = src[i]; i++; } // copy up to n
    while (i < n) { dest[i] = '\0'; i++; } // pad remaining with null
    return dest;
}

/* Append src to end of dest */
char* my_strcat(char* dest, const char* src) {
    int i = my_strlen(dest); // go to end of dest
    int j = 0;
    while (src[j] != '\0') { dest[i++] = src[j++]; } // append src
    dest[i] = '\0'; // null terminate
    return dest;
}

/* Compare two strings — return 0 if equal */
int my_strcmp(const char* a, const char* b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return a[i] - b[i]; // difference at mismatch
        i++;
    }
    return a[i] - b[i]; // compare final chars
}

/* Compare at most n characters */
int my_strncmp(const char* a, const char* b, int n) {
    int i = 0;
    while (i < n && a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return a[i] - b[i]; // mismatch found
        i++;
    }
    if (i == n) return 0; // equal up to n chars
    return a[i] - b[i];
}

/* Convert string to uppercase in-place */
void toUpperCase(char* s) {
    int i;
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; // shift to uppercase
}

/* Convert string to lowercase in-place */
void toLowerCase(char* s) {
    int i;
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32; // shift to lowercase
}

/* Reverse string in-place using two pointers */
void reverseString(char* s) {
    int i = 0, j = my_strlen(s) - 1;
    char temp;
    while (i < j) {
        temp = s[i]; s[i] = s[j]; s[j] = temp; // swap characters
        i++; j--;
    }
}

/* Count vowels (a e i o u) */
int countVowels(const char* s) {
    int count = 0, i;
    for (i = 0; s[i] != '\0'; i++) {
        char c = tolower(s[i]);
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') count++; // is vowel
    }
    return count;
}

/* Count consonants (letters that are not vowels) */
int countConsonants(const char* s) {
    int count = 0, i;
    for (i = 0; s[i] != '\0'; i++) {
        char c = tolower(s[i]);
        if (isalpha(c) && !(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')) count++; // letter but not vowel
    }
    return count;
}

/* Count words by tracking transitions into words */
int countWords(const char* s) {
    int count = 0, inWord = 0, i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n') {
            if (!inWord) { count++; inWord = 1; } // entering a new word
        } else {
            inWord = 0; // leaving a word
        }
    }
    return count;
}

