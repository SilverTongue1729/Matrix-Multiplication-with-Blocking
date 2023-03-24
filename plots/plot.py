import matplotlib.pyplot as plt
import re

# Define a function to convert the time format (e.g., '0m1.231s') to seconds

def time_to_sec(time_str):
    match = re.match(r'(\d+)m([\d.]+)s', time_str)
    minutes = int(match.group(1))
    seconds = float(match.group(2))
    return minutes * 60 + seconds

# Read the time data from the two files
with open('time_taken_main.txt', 'r') as f:
    times_main = [time_to_sec(line.strip()) for line in f]

with open('time_taken_naive.txt', 'r') as f:
    times_naive = [time_to_sec(line.strip()) for line in f]

# Plot the time data as line graphs
plt.plot(times_main, label='Main')
plt.plot(times_naive, label='Naive')
plt.xlabel('Iterations')
plt.ylabel('Time (s)')
plt.title('Plot')
plt.legend()
plt.show()
