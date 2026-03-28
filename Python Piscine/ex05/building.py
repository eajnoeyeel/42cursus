import sys


def main():
    """Counts and displays character types in a given text string."""
    args = sys.argv[1:]

    if len(args) > 1:
        print("AssertionError: more than one argument is provided")
        return
    elif len(args) == 0:
        print("What is the text to count?")
        text = sys.stdin.read()
    else:
        text = args[0]

    upper, lower, punct, space, digit = 0, 0, 0, 0, 0

    for c in text:
        if c.isupper():
            upper += 1
        elif c.islower():
            lower += 1
        elif c.isspace():
            space += 1
        elif c.isdigit():
            digit += 1
        else:
            punct += 1

    print(f"The text contains {len(text)} characters:")
    print(f"{upper} upper letters")
    print(f"{lower} lower letters")
    print(f"{punct} punctuation marks")
    print(f"{space} spaces")
    print(f"{digit} digits")


if __name__ == "__main__":
    main()
