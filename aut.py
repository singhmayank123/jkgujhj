from pynput.keyboard import Controller
import time

def type_enter_n():
    keyboard = Controller()

    # Type 'Enter'
    keyboard.press('\n')
    keyboard.release('\n')
    time.sleep(1.5)  # Delay in seconds (adjust as needed)

    # Type 'n'
    keyboard.press('n')
    keyboard.release('n')
    time.sleep(1.5)  # Delay in seconds (adjust as needed)

if __name__ == "__main__":
    print("Starting to automatically type 'Enter' and 'n'")
    try:
        while True:
            type_enter_n()
    except KeyboardInterrupt:
        print("\nScript interrupted.")
