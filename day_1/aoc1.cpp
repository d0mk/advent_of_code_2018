#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <set>

std::vector<int> loadData(const std::string& filename)
{
	std::ifstream file(filename);
	
	if (file.fail())
	{
		exit(1);
	}
	
	std::string line;
	std::vector<int> data;
	
	while (std::getline(file, line))
	{
		data.push_back(std::stoi(line));
	}
	
	file.close();
	
	return data;
}

void aoc1_part1(const std::vector<int>& data)
{
	int sum = 0;
	
	for (const auto& n : data)
	{
		sum += n;
	}
	
	std::cout << sum << std::endl;
}

void aoc1_part2(const std::vector<int>& data)
{
	std::set<int> frequencySet;
	frequencySet.insert(0);
	
	int freq = 0;
	
	for (int i = 0;; ++i)
	{
		if (i == data.size())
		{
			i = 0;
		}
		
		freq += data[i];
		
		if (!frequencySet.insert(freq).second)
		{
			std::cout << freq << std::endl;
			return;
		}
	}
}

int main()
{
	std::vector<int> data = loadData("aoc1_data.txt");
	
	aoc1_part1(data);
	aoc1_part2(data);
	
	return 0;
}