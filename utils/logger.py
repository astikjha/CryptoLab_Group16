from datetime import datetime


def log_action(option):
    current_time = datetime.now()

    with open("outputs/cryptolabx.log", "a") as log_file:
        log_file.write(
            f"{current_time.strftime('%Y-%m-%d %H:%M:%S')} - {option}\n"
        )