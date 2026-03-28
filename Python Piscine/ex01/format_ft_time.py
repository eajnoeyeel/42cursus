import time

# Get current time with fractional seconds
now = time.time()

# First line: seconds since epoch with 4 decimal places and scientific notation
print(f"Seconds since January 1, 1970: {now:,.4f} or {now:.2e} in scientific notation")

print(time.strftime("%b %d %Y", time.localtime(now)))

# import datetime

# now = datetime.datetime.now()

# # UNIX timestamp
# timestamp = now.timestamp()

# print(f"Seconds since January 1, 1970: {timestamp:,.4f} or {timestamp: .2e} in scientific notation")

# print(now.strftime("%b %d %Y"))