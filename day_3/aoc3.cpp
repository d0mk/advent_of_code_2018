#include <iostream>
#include <string>
#include <sstream> // std::stringstream
#include <fstream>
#include <vector>
#include <algorithm> // std::replace
#include <set>


std::vector<std::string> loadData(const std::string& filename)
{
	std::ifstream file(filename);
	
	if (file.fail())
	{
		exit(1);
	}
	
	std::string line;
	std::vector<std::string> data;
	
	// loading data from file and replacing
	// non-integer characters with spaces
	while (std::getline(file, line))
	{
		std::replace(line.begin(), line.end(), '#', ' ');
		std::replace(line.begin(), line.end(), '@', ' ');
		std::replace(line.begin(), line.end(), ':', ' ');
		std::replace(line.begin(), line.end(), ',', ' ');
		std::replace(line.begin(), line.end(), 'x', ' ');
		
		data.push_back(line);
	}
	
	file.close();
	
	return data;
}


void extractValues(const std::string& line, int& id, int& newWidth, int& newHeight, int& distFromTop, int& distFromLeft)
{
	std::stringstream stream(line);
	stream >> id >> distFromLeft >> distFromTop >> newWidth >> newHeight;
}


void aoc3_part1(const std::vector<std::string>& data)
{
	int id, newWidth, newHeight, distFromTop, distFromLeft;	
	int maxW = -1, maxH = -1;
	
	// finding the maximum size of the area
	for (const auto& line : data)
	{
		extractValues(line, id, newWidth, newHeight, distFromTop, distFromLeft);
		
		if (newHeight + distFromTop > maxH)
		{
			maxH = newHeight + distFromTop;
		}
		
		if (newWidth + distFromLeft > maxW)
		{
			maxW = newWidth + distFromLeft;
		}
	}
	
	int overlap = 0;
	std::vector<std::vector<char>> vec(maxH, std::vector<char>(maxW));
	
	for (const auto& line : data)
	{
		extractValues(line, id, newWidth, newHeight, distFromTop, distFromLeft);
		
		for (int i = 0; i < newHeight; ++i)
		{
			for (int j = 0; j < newWidth; ++j)
			{
				if (vec[distFromTop + i][distFromLeft + j] == '.')
				{
					vec[distFromTop + i][distFromLeft + j] = '#';
					overlap++;
				}
				
				if (vec[distFromTop + i][distFromLeft + j] != '.' && vec[distFromTop + i][distFromLeft + j] != '#')
				{
					vec[distFromTop + i][distFromLeft + j] = '.';
				}
			}
		}
	}
	
	std::cout << overlap << std::endl;
}


void aoc3_part2(const std::vector<std::string>& data)
{
	int id, newWidth, newHeight, distFromTop, distFromLeft;	
	int maxW = -1, maxH = -1;
	
	// finding the maximum size of the area
	for (const auto& line : data)
	{
		extractValues(line, id, newWidth, newHeight, distFromTop, distFromLeft);
		
		if (newHeight + distFromTop > maxH)
		{
			maxH = newHeight + distFromTop;
		}
		
		if (newWidth + distFromLeft > maxW)
		{
			maxW = newWidth + distFromLeft;
		}
	}
	
	std::set<int> invalidIDs;
	std::vector<std::vector<int>> layer(maxH, std::vector<int>(maxW, 0));
	
	for (const auto& line : data)
	{
		extractValues(line, id, newWidth, newHeight, distFromTop, distFromLeft);
		
		for (int i = 0; i < newHeight; ++i)
		{
			for (int j = 0; j < newWidth; ++j)
			{
				if (layer[distFromTop + i][distFromLeft + j])
				{
					invalidIDs.insert(layer[distFromTop + i][distFromLeft + j]);
					invalidIDs.insert(id);
				}
				
				layer[distFromTop + i][distFromLeft + j] = id;
			}
		}
	}
	
	for (int id = 1; id <= data.size(); ++id)
	{
		if (invalidIDs.find(id) == invalidIDs.end())
		{
			std::cout << id << std::endl;
			return;
		}
	}
}


int main()
{
	aoc3_part1(loadData("aoc3_data.txt"));
	aoc3_part2(loadData("aoc3_data.txt"));
}