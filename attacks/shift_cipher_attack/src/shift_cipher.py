def encrypt(text, key):
    result = ""

    for ch in text:
        if ch.isalpha():
            result += chr((ord(ch.lower()) - ord('a') + key) % 26 + ord('a'))
        else:
            result += ch

    return result


def decrypt(text, key):
    return encrypt(text, -key)


text = input("Enter plaintext: ")
key = int(input("Enter key: "))

cipher = encrypt(text, key)

print("Ciphertext:", cipher)
print("Decrypted:", decrypt(cipher, key))