import tkinter as tk
from tkinter import messagebox

# set length of tweet to be 280 characters long
TWEET_LEN = 280

# create Tkinter window
window = tk.Tk()

# set window title
window.title("Twitter GUI")

# function to check if tweet is valid
def check_tweet():
    tweet = tweet_entry.get()

    # check if tweet satisfies the length condition
    if len(tweet) > TWEET_LEN:
        messagebox.showerror("Error", "Invalid tweet. (exceeds maximum character length)")
        return

    # check if tweet contains invalid characters
    invalid_chars = "!@#$%^&*()_-+=[]{}|;':\"<>,.?/~`"
    for char in tweet:
        if char in invalid_chars:
            messagebox.showerror("Error", "Invalid tweet. (contains invalid characters)")
            return

    # check if tweet contains @mentions
    if "@" in tweet:
        messagebox.showerror("Error", "Invalid tweet. (contains @mentions)")
        return

    # check if tweet contains URLs
    if "http://" in tweet or "https://" in tweet:
        messagebox.showerror("Error", "Invalid tweet. (contains URLs)")
        return

    # show success message
    messagebox.showinfo("Success", "Valid tweet.")

# function to update remaining characters label
def update_remaining_chars(char_count):
    remaining_chars = TWEET_LEN - char_count
    remaining_chars_label.config(text=f"{remaining_chars} characters remaining")

# create tweet entry
tweet_var = tk.StringVar()
tweet_entry = tk.Entry(window, width=50, textvariable=tweet_var)
tweet_entry.pack()
tweet_var.trace_add("write", lambda *args: update_remaining_chars(len(tweet_var.get())))

# create button to check tweet
check_button = tk.Button(window, text="Check Tweet", command=check_tweet)
check_button.pack()

# create label for remaining characters
remaining_chars_label = tk.Label(window, text=f"{TWEET_LEN} characters remaining")
remaining_chars_label.pack()

# start Tkinter event loop
window.mainloop()
