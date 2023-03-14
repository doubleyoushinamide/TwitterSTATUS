#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TWEET_LEN 280 // set length of tweet to be 280 characters long

int main(void)
{
    char tweet[TWEET_LEN + 1];

    printf("What are you tweeting today?:\n");

    // use fgets() instead of scanf() to read in a complete line
    fgets(tweet, sizeof(tweet), stdin);

    /*
     * check if the tweet satisfies the 
     * length condition
     */
    if (strlen(tweet) - 1 > TWEET_LEN) {
        printf("Invalid tweet. (exceeds maximum character length)\n");
        return 0;
    }

    /** check if the tweet contains invalid characters, 
     * only allow alpha-numeric, whitespaces, 
     * dots, commas, question/exclamation marks and apostrophes
     */
    for (int i = 0; i < strlen(tweet) - 1; i++) {
        if (!(isalpha(tweet[i]) || isdigit(tweet[i]) || isspace(tweet[i]) ||
              tweet[i] == '.' || tweet[i] == ',' || tweet[i] == '?' || tweet[i] == '!' || tweet[i] == '\'')) {
            printf("Invalid tweet. (contains invalid characters)\n");
            return 0;
        }
    }

    /** check if the tweet contains @ mentions 
     * (assuming that these start with '@' followed by any combination of letters/numbers/underscores)
     */
    if (strstr(tweet, "@") != NULL) {
        printf("Invalid tweet. (contains @mentions)\n");
        return 0;
    }

    /** check if the tweet contains URLs 
     * (assuming that URLs start with "http://" or "https://")
     */
    if (strstr(tweet, "http://") != NULL || strstr(tweet, "https://") != NULL) {
        printf("Invalid tweet. (contains URLs)\n");
        return 0;
    }

    printf("Valid tweet.\n");

    // calculate remaining characters and display to user
    int remaining_chars = TWEET_LEN - strlen(tweet) + 1;
    printf("You have %d characters remaining.\n", remaining_chars);
   
   // loop until user enters a valid tweet or the tweet reaches the max length
   int i;
    while (remaining_chars >= 0) {
        printf("What are you tweeting today?:\n");
        fgets(tweet, sizeof(tweet), stdin);

        if (strlen(tweet) - 1 <= TWEET_LEN) {
            break;
        }

        printf("Invalid tweet. (exceeds maximum character length)\n");
        remaining_chars = TWEET_LEN - strlen(tweet) + 1;
        printf("You have %d characters remaining.\n", remaining_chars);
    }

    // loop until user enters a tweet without invalid characters
    while (1) {
        for (int i = 0; i < strlen(tweet) - 1; i++) {
            if (!(isalpha(tweet[i]) || isdigit(tweet[i]) || isspace(tweet[i]) ||
                  tweet[i] == '.' || tweet[i] == ',' || tweet[i] == '?' || tweet[i] == '!' || tweet[i] == '\'')) {
                printf("Invalid tweet. (contains invalid characters)\n");
                remaining_chars = TWEET_LEN - strlen(tweet) + 1;
                printf("You have %d characters remaining.\n", remaining_chars);
                break;
            }
        }

        if (remaining_chars >= 0 && strstr(tweet, "@") == NULL &&
            strstr(tweet, "http://") == NULL && strstr(tweet, "https://") == NULL && i == strlen(tweet) - 1) {
            break;
        }

        if (remaining_chars <= 0) {
            printf("Invalid tweet. (exceeds maximum character length)\n");
        } else if (strstr(tweet, "@") != NULL) {
            printf("Invalid tweet. (contains @mentions)\n");
        } else if (strstr(tweet, "http://") != NULL || strstr(tweet, "https://") != NULL) {
            printf("Invalid tweet. (contains URLs)\n");
        } else {
            printf("Invalid tweet. (contains invalid characters)\n");
        }

        remaining_chars = TWEET_LEN - strlen(tweet) + 1;
        printf("You have %d characters remaining.\n", remaining_chars);
        printf("What are you tweeting today?:\n");
        fgets(tweet, sizeof(tweet), stdin);
     }

    printf("Valid tweet.\n");

    return 0;
}
