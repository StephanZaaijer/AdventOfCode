with open("input.txt") as input_file:
    input = input_file.read().splitlines()

input.append("")
count = 0

amountPerElf = [];

for line in input:
    if line == "":
        amountPerElf.append(count)
        count = 0
    else:
        count += int(line)

amountPerElf.sort(reverse=True);
print(amountPerElf[0] + amountPerElf[1] + amountPerElf[2])