from shift_cipher import decrypt

dictionary = {
    "the", "is", "a", "this", "hello",
    "world", "test", "shift", "cipher",
    "cryptography", "and", "for", "security"
}


def score(text):
    words = text.lower().split()
    count = 0

    for word in words:
        if word in dictionary:
            count += 1

    return count


ciphertext = input("Enter ciphertext: ")

best_key = 0
best_score = -1
best_text = ""

for key in range(26):
    plaintext = decrypt(ciphertext, key)
    current_score = score(plaintext)

    print(key, "->", plaintext, "Score:", current_score)

    if current_score > best_score:
        best_score = current_score
        best_key = key
        best_text = plaintext

print("\nPredicted Key:", best_key)
print("Plaintext:", best_text)
print("Dictionary Score:", best_score)