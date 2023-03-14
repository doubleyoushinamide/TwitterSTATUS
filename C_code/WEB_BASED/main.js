const tweetForm = document.querySelector("#tweet-form");
const tweetInput = document.querySelector("#tweet-input");
const charCounter = document.querySelector("#char-counter");

tweetForm.addEventListener("submit", (e) => {
  e.preventDefault();

  const tweetText = tweetInput.value.trim();

  // Check tweet length
  if (tweetText.length > 280) {
    alert("Invalid tweet. (exceeds maximum character length)");
    return;
  }

  // Check invalid characters
  const invalidChars = /[*|\":<>[\]{}`\()';@&$]/;
  if (invalidChars.test(tweetText)) {
    alert("Invalid tweet. (contains invalid characters)");
    return;
  }

  // Check @mentions
  const mentions = /\B@\w+/;
  if (mentions.test(tweetText)) {
    alert("Invalid tweet. (contains @mentions)");
    return;
  }

  // Check urls
  const urls = /(https?:\/\/[^\s]+)/g;
  if (urls.test(tweetText)) {
    alert("Invalid tweet. (contains URLs)");
    return;
  }

  alert("Valid tweet.");
  resetForm();
});

tweetInput.addEventListener("input", () => {
  charCounter.textContent = `${280 - tweetInput.value.length} Characters Remaining`;
});

function resetForm() {
  tweetForm.reset();
  charCounter.textContent = "280 Characters Remaining";
}
