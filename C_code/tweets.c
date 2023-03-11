#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TWEET_LEN 280 // set length of tweet to be 280 characters long

int main()
{
    char tweet[TWEET_LEN + 1];
    // read in the tweet from user input
    printf("What are you tweeting today?:\n");
    scanf("%280[^\n]", tweet); // this will read in at most TWEET_LEN characters, and stop at the first newline ('\n')

    // check if the tweet satisfies the length condition
    if (strlen(tweet) > TWEET_LEN) {
        printf("Invalid tweet. (exceeds maximum character length)\n");
        return 0;
    }

    // check if the tweet contains invalid characters, only allow alpha-numeric, whitespaces, dots,commas, question/exclamation marks 
    for (int i = 0; i < strlen(tweet); i++) {
        if (!(isalpha(tweet[i]) || isdigit(tweet[i]) || isspace(tweet[i]) ||
              tweet[i] == '.' || tweet[i] == ',' || tweet[i] == '?' || tweet[i] == '!' || tweet[i] == '\'')) {
            printf("Invalid tweet. (contains invalid characters)\n");
            return 0;
        }
    }

    // check if the tweet contains @ mentions (assuming that these start with '@' followed by any combination of letters/numbers/underscores)
    if (strstr(tweet, "@") != NULL) {
        printf("Invalid tweet. (contains @mentions)\n");
        return 0;
    }

    // check if the tweet contains URLs (assuming that URLs start with "http://" or "https://")
    if (strstr(tweet, "http://") != NULL || strstr(tweet, "https://") != NULL) {
        printf("Invalid tweet. (contains URLs)\n");
        return 0;
    }

    printf("Valid tweet.\n");
    return 0;
}
