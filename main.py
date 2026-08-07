from analysis.file_analyzer import analyze_file
from utils.logger import log_action


def display_menu():
    print("\n" + "=" * 40)
    print("          CryptoLabX Toolkit")
    print("=" * 40)
    print("1. Encrypt")
    print("2. Decrypt")
    print("3. Attack")
    print("4. Analyze")
    print("5. Exit")
    print("=" * 40)


def main():
    while True:
        display_menu()

        choice = input("Enter your choice (1-5): ")

        if choice == "1":
            log_action("Encrypt")
            print("Encrypt: Coming Soon")

        elif choice == "2":
            log_action("Decrypt")
            print("Decrypt: Coming Soon")

        elif choice == "3":
            log_action("Attack")
            print("Attack: Coming Soon")

        elif choice == "4":
            log_action("Analyze")

            filename = input("Enter dataset filename: ")
            filepath = "datasets/" + filename

            analyze_file(filepath)

        elif choice == "5":
            log_action("Exit")
            print("Exiting CryptoLabX...")
            break

        else:
            log_action("Invalid Option")
            print("Invalid choice. Please enter a number from 1 to 5.")


if __name__ == "__main__":
    main()