#include <stdio.h>
#include <string.h>

int main() {
    int tweet_length = 280;
    char tweet[tweet_length + 1];

    printf("What are you tweeting today?:\n");
    fgets(tweet, sizeof(tweet), stdin);

    int valid_tweet = 1;

    if (strlen(tweet) > tweet_length) {
        valid_tweet = 0;
    }

    const char *valid_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,'&/ ";
    for (int i = 0; tweet[i] != '\0'; i++) 
    {
        int found = 0;
        for (int j = 0; valid_chars[j] != '\0'; j++) 
        {
            if (tweet[i] == valid_chars[j])  
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            valid_tweet = 0;
            break;
        }
    }


    if (strstr(tweet, "@")) {
        valid_tweet = 0;
    }

    if (strstr(tweet, "http://") || strstr(tweet, "https://")) {
        valid_tweet = 0;
    }

if (valid_tweet == 0) {
    printf("Invalid tweet!\n");
} else {
    printf("Valid tweet!\n");
    }

    return 0;
}
