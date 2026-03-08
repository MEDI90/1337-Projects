def garden_operations() -> tuple:
    def trigger_value() -> None:
        int("abs")

    def trigger_zero() -> None:
        1 / 0

    def trigger_file() -> None:
        open("missing.txt", "r")

    def trigger_key() -> None:
        garden = {"tree": 5}
        garden["missing_plant"]

    return trigger_value, trigger_zero, trigger_file, trigger_key


def test_error_types() -> None:
    print("=== Garden Error Types Demo ===")

    val_err, zero_err, file_err, key_err = garden_operations()

    print("\nTesting ValueError...")
    try:
        val_err()
    except ValueError:
        print("Caught ValueError: invalid literal for int()")

    print("\nTesting ZeroDivisionError...")
    try:
        zero_err()
    except ZeroDivisionError:
        print("Caught ZeroDivisionError: division by zero")

    print("\nTesting FileNotFoundError...")
    try:
        file_err()
    except FileNotFoundError:
        print("Caught FileNotFoundError: No such file 'missing.txt'")

    print("\nTesting KeyError...")
    try:
        key_err()
    except KeyError:
        print("Caught KeyError: 'missing_plant'")

    print("\nTesting multiple errors together...")
    try:
        val_err()
    except (ValueError, ZeroDivisionError, KeyError, FileNotFoundError):
        print("Caught an error, but program continues!")

    print("\nAll error types tested successfully!")


if __name__ == "__main__":
    try:
        test_error_types()
    except Exception as e:
        print(f"Error: {e}")
