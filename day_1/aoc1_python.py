# first part of the exercise
with open("aoc1_data.txt", "r") as file:
	print(sum([int(x) for x in file.readlines()]))