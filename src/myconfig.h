#ifndef MYCONFIG_H
#define MYCONFIG_H

#include <map>
#include <string>

class MyConfig
{
public:
	MyConfig();
	~MyConfig();
	std::map<std::string, bool> logWhitelist;
	std::map<std::string, bool> logBlacklist;
	bool checkLogSection(const std::string& section);
};

extern MyConfig g_config;

#endif
