from collections import Counter


def analyze_file(filepath):
    try:
        with open(filepath, "r") as file:
            content = file.read()

        characters = len(content)
        words = len(content.split())
        lines = len(content.splitlines())
        unique_characters = len(set(content))

        letters = [char.lower() for char in content if char.isalpha()]
        letter_frequency = Counter(letters)

        print("\n--- File Analysis ---")
        print(f"Characters       : {characters}")
        print(f"Words            : {words}")
        print(f"Lines            : {lines}")
        print(f"Unique Characters: {unique_characters}")

        print("\nLetter Frequency:")

        for letter in sorted(letter_frequency):
            print(f"{letter}: {letter_frequency[letter]}")

    except FileNotFoundError:
        print("Error: File not found.")

    except Exception as error:
        print(f"Error: {error}")