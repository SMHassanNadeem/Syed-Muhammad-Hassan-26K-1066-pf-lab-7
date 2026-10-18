#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() 
{
    char titles[5][50];
    int copies[5];
    
    printf("ENTER BOOK DETAILS\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\nEnter title for Book %d (allows spaces): ", i + 1);
        scanf(" %[^\n]", titles[i]); 
        
        printf("Enter number of copies for '%s': ", titles[i]);
        scanf("%d", &copies[i]);
    }

    printf("\n%-4s | %-30s | %-10s\n", "No.", "Book Title", "Copies");
    for (int i = 0; i < 5; i++) 
    {
        printf("%-4d | %-30s | %-10d\n", i + 1, titles[i], copies[i]);
    }

    printf("\nVOWEL COUNT REPORT\n");
    for (int i = 0; i < 5; i++) 
    {
        int vowel_count = 0;
        for (int j = 0; titles[i][j] != '\0'; j++) 
        {
            char ch = tolower(titles[i][j]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') 
            {
                vowel_count++;
            }
        }
        printf("Book %d ('%s') contains: %d vowels\n", i + 1, titles[i], vowel_count);
    }

    char search_letter;
    printf("\n=== SEARCH BY FIRST LETTER ===\n");
    printf("Enter a single letter to filter titles: ");
    scanf(" %c", &search_letter);
    
    printf("Books starting with '%c':\n", search_letter);
    int found_any = 0;
    for (int i = 0; i < 5; i++) 
    {
        if (tolower(titles[i][0]) == tolower(search_letter)) 
        {
            printf("  - %s\n", titles[i]);
            found_any = 1;
        }
    }
    if (!found_any) 
    {
        printf("  No books found starting with that letter.\n");
    }

    int max_index = 0;
    for (int i = 1; i < 5; i++) 
    {
        if (copies[i] > copies[max_index]) 
        {
            max_index = i;
        }
    }
    printf("\nMAXIMUM COPIES ALERT\n");
    printf("The book with the most copies is '%s' (%d copies available).\n", titles[max_index], copies[max_index]);

    return 0;
}
