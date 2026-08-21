# Vulnerability 1: Hardcoded Secret
ADMIN_USERNAME = "admin"
ADMIN_PASSWORD = "admin123"


class Wallet:
    def __init__(self, username):
        self.username = username
        self.balance = 1000.0
        self.transactions = []

    def show_balance(self):
        print(f"\nWallet owner: {self.username}")
        print(f"Balance: {self.balance} coins")

    def send_transaction(self):
        receiver = input("Enter receiver username: ")
        amount = float(input("Enter amount to send: "))

        # Vulnerability 2: Improper Input Validation
        # Negative values are not rejected.
        if receiver not in users:
            print("Receiver wallet not found.")
            return

        if amount > self.balance:
            print("Insufficient balance.")
            return

        self.balance -= amount
        users[receiver].balance += amount

        transaction = (
            f"{self.username} sent {amount} coins to {receiver}"
        )

        self.transactions.append(transaction)
        users[receiver].transactions.append(transaction)

        print("Transaction successful.")

    def show_history(self):
        print("\nTransaction History:")

        if not self.transactions:
            print("No transactions found.")
            return

        for transaction in self.transactions:
            print(transaction)


# Stores all wallet objects
users = {}


def create_wallet():
    username = input("Enter username: ")

    if username in users:
        print("Wallet already exists.")
        return

    users[username] = Wallet(username)

    print(f"Wallet created successfully for {username}.")


def login():
    username = input("Enter username: ")

    if username not in users:
        print("Wallet not found.")
        return

    wallet = users[username]

    print(f"Welcome, {wallet.username}!")

    wallet_menu(wallet)


# Vulnerability 3: Broken Access Control
def view_wallet():
    username = input("Enter username whose wallet you want to view: ")

    if username not in users:
        print("Wallet not found.")
        return

    wallet = users[username]

    print("\n=== Wallet Information ===")
    print(f"Username: {wallet.username}")
    print(f"Balance: {wallet.balance} coins")

    wallet.show_history()


def wallet_menu(wallet):
    while True:
        print("\n=== Wallet Menu ===")
        print("1. Check Balance")
        print("2. Send Transaction")
        print("3. Transaction History")
        print("4. Logout")
        print("5. View Another Wallet")

        choice = input("Enter choice: ")

        if choice == "1":
            wallet.show_balance()

        elif choice == "2":
            wallet.send_transaction()

        elif choice == "3":
            wallet.show_history()

        elif choice == "4":
            print("Logged out.")
            break

        elif choice == "5":
            view_wallet()

        else:
            print("Invalid choice.")


def main():
    while True:
        print("\n=== Cryptocurrency Wallet ===")
        print("1. Create Wallet")
        print("2. Login")
        print("3. Exit")

        choice = input("Enter choice: ")

        if choice == "1":
            create_wallet()

        elif choice == "2":
            login()

        elif choice == "3":
            print("Goodbye!")
            break

        else:
            print("Invalid choice.")


if __name__ == "__main__":
    main()
