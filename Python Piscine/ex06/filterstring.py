import sys
from ft_filter import ft_filter


def main():
    """Filters words from a string by minimum length."""
    try:
        assert len(sys.argv) == 3, "the arguments are bad"
        s = sys.argv[1]
        n = sys.argv[2]
        assert n.lstrip('-').isdigit(), "the arguments are bad"
        n = int(n)
    except AssertionError as e:
        print(f"AssertionError: {e}")
        return

    result = list(ft_filter(lambda word: len(word) > n, s.split()))
    print(result)


if __name__ == "__main__":
    main()
