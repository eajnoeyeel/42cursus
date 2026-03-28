import os


def ft_tqdm(lst: range) -> None:
    """Decorate an iterable object, returning an iterator which acts to
print a dynamically updating progressbar."""
    total = len(lst)
    try:
        cols = os.get_terminal_size().columns
    except OSError:
        cols = 80
    for i, item in enumerate(lst, 1):
        percent = i / total
        pct_str = f"{int(percent * 100)}%"
        counter = f"{i}/{total}"
        # Calculate bar width: cols - pct_str - "|" - "[>" - "]|" - counter
        # Format: "XXX%|[=====>]| i/total"
        fixed_len = len(pct_str) + 1 + 2 + 1 + 1 + len(counter)
        bar_width = cols - fixed_len
        if bar_width < 1:
            bar_width = 1
        filled = int(percent * bar_width)
        if filled == bar_width:
            bar = "=" * bar_width
        else:
            bar = "=" * filled + ">" + " " * (bar_width - filled - 1)
        print(f"\r{pct_str}|[{bar}]| {counter}", end="", flush=True)
        yield item
    print()
