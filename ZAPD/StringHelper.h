#pragma once

#include <numeric>
#include <stdarg.h>
#include <string.h>
#include <string>
#include <vector>

class StringHelper
{
public:
	static std::vector<std::string> Split(std::string s, const std::string& delimiter)
	{
		std::vector<std::string> result;

		size_t pos = 0;
		std::string token;

		while ((pos = s.find(delimiter)) != std::string::npos)
		{
			token = s.substr(0, pos);
			result.push_back(token);
			s.erase(0, pos + delimiter.length());
		}

		if (s.length() != 0)
			result.push_back(s);

		return result;
	}

	static std::string Strip(std::string s, const std::string& delimiter)
	{
		size_t pos = 0;
		std::string token;

		while ((pos = s.find(delimiter)) != std::string::npos)
		{
			token = s.substr(0, pos);
			s.erase(pos, pos + delimiter.length());
		}

		return s;
	}

	static std::string Replace(std::string str, const std::string& from, const std::string& to)
	{
		size_t start_pos = str.find(from);

		if (start_pos == std::string::npos)
			return str;

		str.replace(start_pos, from.length(), to);
		return str;
	}

	static bool StartsWith(const std::string& s, const std::string& input)
	{
		return s.rfind(input, 0) == 0;
	}

	static bool Contains(const std::string& s, const std::string& input)
	{
		return s.find(input) != std::string::npos;
	}

	static bool EndsWith(const std::string& s, const std::string& input)
	{
		int inputLen = strlen(input.c_str());
		return s.rfind(input) == (s.size() - inputLen);
	}

	static std::string Sprintf(const char* format, ...)
	{
		char buffer[32768];
		// char buffer[2048];
		std::string output = "";
		va_list va;

		va_start(va, format);
		vsprintf(buffer, format, va);
		va_end(va);

		output = buffer;
		return output;
	}

	static std::string Implode(std::vector<std::string>& elements, const char* const separator)
	{
		return std::accumulate(std::begin(elements), std::end(elements), std::string(),
		                       [separator](std::string& ss, std::string& s) {
								   return ss.empty() ? s : ss + separator + s;
							   });
	}
};
