tweet_length = 280  # set length of tweet to be 280 characters long
tweet = input("What are you tweeting today?:\n")

# Validation conditions: Here we check if the tweet satisfies the requirements such as length, existence of special 
# characters, @mentions, URLs, etc.

valid_tweet = True

# check if the tweet satisfies the length condition
if len(tweet) > tweet_length:
    valid_tweet = False

# check if the tweet contains invalid characters, only allow alpha-numeric, whitespaces, dots,commas, question/exclamation 
# marks 
for i in range(len(tweet)):
    if not ((tweet[i].isalpha() or tweet[i].isdigit()) or (tweet[i] == ' ' or tweet[i] == '.' or tweet[i] == ',' or 
                                                           tweet[i] == '?' or tweet[i] == '!' or tweet[i] == "'")):
        valid_tweet = False
        break

# check if the tweet contains @ mentions
if "@" in tweet:
    valid_tweet = False

# check if the tweet contains URLs
if ("http://" in tweet) or ("https://" in tweet):
    valid_tweet = False

# print validation result
if valid_tweet:
    print("Valid tweet.\n")
else:
    print("Invalid tweet. \n")

