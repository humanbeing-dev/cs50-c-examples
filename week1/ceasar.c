/* CEASAR CIPHER
 * Tests:
 * ./caesar 13
 * plaintext:  HELLO
 * ciphertext: URYYB
 *
 * ./caesar 1
 * plaintext:  HELLO
 * ciphertext: IFMMP
 *
 * ./caesar 13
 * plaintext:  hello, world
 * ciphertext: uryyb, jbeyq
 *
 * ./caesar 13
 * plaintext:  be sure to drink your Ovaltine
 * ciphertext: or fher gb qevax lbhe Binygvar
 *
 *
 *
 *
 * c = (p + k) % 26
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    // Check if no or more than one key
    if (argc != 2)
    {
        printf("Usage: ./ceasar key\n");
        return 1;
    }

    char *shift = argv[1];

    // Check if key is non-negative integer ASCII 48-57
    for (int i = 0, n = strlen(shift); i < n; i++)
    {
        if (shift[i] < 48 || shift[i] > 57)
        {
            printf("Usage: ./ceasar key\n");
            return 1;
        }
    }

    // Convert argv[1] to integer
    int shift_int = atoi(shift);

    // Take a text from a user
    char plaintext[200];
    printf("plaintext: ");
    fgets(plaintext, 200, stdin);

    // Convert text to cipher text
    char ciphertext[200];
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (plaintext[i] >= 65 && plaintext[i] <= 90)
        {
            ciphertext[i] = 65 + (plaintext[i] - 65 + shift_int) % 26;

        }
        else if (plaintext[i] >= 97 && plaintext[i] <= 122)
        {
            ciphertext[i] = 97 + (plaintext[i] - 97 + shift_int) % 26;
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    // Printout cipher text
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}