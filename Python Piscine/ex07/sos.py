import sys


NESTED_MORSE = {
    " ": "/ ",
    "A": ".- ",
    "B": "-... ",
    "C": "-.-. ",
    "D": "-.. ",
    "E": ". ",
    "F": "..-. ",
    "G": "--. ",
    "H": ".... ",
    "I": ".. ",
    "J": ".--- ",
    "K": "-.- ",
    "L": ".-.. ",
    "M": "-- ",
    "N": "-. ",
    "O": "--- ",
    "P": ".--. ",
    "Q": "--.- ",
    "R": ".-. ",
    "S": "... ",
    "T": "- ",
    "U": "..- ",
    "V": "...- ",
    "W": ".-- ",
    "X": "-..- ",
    "Y": "-.-- ",
    "Z": "--.. ",
    "0": "----- ",
    "1": ".---- ",
    "2": "..--- ",
    "3": "...-- ",
    "4": "....- ",
    "5": "..... ",
    "6": "-.... ",
    "7": "--... ",
    "8": "---.. ",
    "9": "----. ",
}


def main():
    """Encodes a string argument into Morse code."""
    try:
        assert len(sys.argv) == 2, "the arguments are bad"
        text = sys.argv[1]
        for c in text:
            assert c.upper() in NESTED_MORSE, "the arguments are bad"
    except AssertionError as e:
        print(f"AssertionError: {e}")
        return

    result = ""
    for c in text:
        result += NESTED_MORSE[c.upper()]
    print(result.rstrip())


if __name__ == "__main__":
    main()
