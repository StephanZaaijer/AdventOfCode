with open("input.txt") as input_file:
    input = input_file.read().splitlines()
input.append("")

max = -1;
count = 0

for line in input:
    if line == "":
        if count > max:
            max = count
        count = 0
    else:
        count += int(line)

print(max)