import random

with open('names.txt') as file:
    lines = file.readlines()
    lines = [line.rstrip() for line in lines]
    random.shuffle(lines)
    for line in lines:
        print(line)
