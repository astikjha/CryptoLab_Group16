from shift_cipher import decrypt

frequency = [
    8.2, 1.5, 2.8, 4.3, 12.7, 2.2, 2.0,
    6.1, 7.0, 0.15, 0.8, 4.0, 2.4, 6.7,
    7.5, 1.9, 0.1, 6.0, 6.3, 9.1, 2.8,
    1.0, 2.4, 0.15, 2.0, 0.07
]


def chi_square(text):
    letters = ""

    for ch in text.lower():
        if ch.isalpha():
            letters += ch

    n = len(letters)

    if n == 0:
        return float("inf")

    counts = [0] * 26

    for ch in letters:
        counts[ord(ch) - ord('a')] += 1

    result = 0

    for i in range(26):
        expected = n * frequency[i] / 100
        result += (counts[i] - expected) ** 2 / expected

    return result


ciphertext = input("Enter ciphertext: ")

best_key = 0
best_score = float("inf")
best_text = ""

for key in range(26):
    plaintext = decrypt(ciphertext, key)
    current_score = chi_square(plaintext)

    print(key, "->", plaintext, "Chi-Square:", current_score)

    if current_score < best_score:
        best_score = current_score
        best_key = key
        best_text = plaintext

print("\nPredicted Key:", best_key)
print("Plaintext:", best_text)
print("Chi-Square:", best_score)