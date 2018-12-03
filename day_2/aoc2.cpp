#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

std::vector<std::string> loadData(const std::string& filename)
{
	std::ifstream file(filename);
	
	if (file.fail())
	{
		exit(1);
	}
	
	std::string line;
	std::vector<std::string> data;
	
	while (std::getline(file, line))
	{
		data.push_back(line);
	}
	
	file.close();
	
	return data;
}

void aoc2_part1(const std::vector<std::string>& data)
{
	int count2 = 0, count3 = 0;
	
	for (const auto& line : data)
	{
		std::map<char, int> m;
		
		for (const auto& c : line)
		{
			if (m.find(c) != m.end())
			{
				m[c]++;
			}
			else
			{
				m[c] = 1;
			}
		}
		
		bool check2 = false, check3 = false;
		
		for (auto it : m)
		{
			if (!check2)
			{
				if (it.second == 2)
				{
					count2++;
					check2 = true;
				}
			}
			
			if (!check3)
			{
				if (it.second == 3)
				{
					count3++;
					check3 = true;
				}
			}
		}
	}
	
	std::cout << count2 * count3 << std::endl;
}

void aoc2_part2(const std::vector<std::string>& data)
{
	int iresult = -1, jresult = -1;
	
	for (int i = 0; i < data.size(); ++i)
	{
		for (int j = 0; j < data.size(); ++j)
		{
			if (i == j)
			{
				continue;
			}
			
			int countDifferentChars = 0;
			
			for (int k = 0; k < data[i].size(); ++k)
			{
				if (data[i][k] != data[j][k])
				{
					countDifferentChars++;
				}
				
				if (countDifferentChars > 1)
				{
					break;
				}
			}
			
			if (countDifferentChars == 1)
			{
				iresult = i;
				jresult = j;
				
				break;
			}
		}
		
		if (iresult != -1)
		{
			break;
		}
	}
	
	for (int i = 0; i < data[iresult].size(); ++i)
	{
		if (data[iresult][i] == data[jresult][i])
		{
			std::cout << data[iresult][i];
		}
	}
	
	std::cout << std::endl;
}

int main()
{	
	aoc2_part1(loadData("aoc2_data.txt"));
	aoc2_part2(loadData("aoc2_data.txt"));
	
	return 0;
}