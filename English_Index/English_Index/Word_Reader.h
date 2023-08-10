#pragma once
#include <map>
#include <string>

class Word_Reader
{
public:
	static void Read_Words(bool random_Index);

	static void Print_Words();

private:
	static std::map<std::string, int> Word_Map;
};

