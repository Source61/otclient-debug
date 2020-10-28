#include <myconfig.h>

MyConfig g_config;


// no need for logBlacklist["all"] as it's virtually set by default
// purpose of logBlacklist[...]: if logWhitelist["all"] = true, then logBlacklist[...] disables a particular section
MyConfig::MyConfig()
{
	logWhitelist["all"] = false; // special case that enables all logging when set to true
	logWhitelist["example"] = true; // this makes example code `g_logger.debug("Example Text", "example");` output and log the text "Example Text"
}

MyConfig::~MyConfig()
{

}

bool MyConfig::checkLogSection(const std::string& section)
{
	if( ((!logWhitelist.count(section) || !logWhitelist[section]) && (!logWhitelist.count("all") || !logWhitelist["all"])) || (logBlacklist.count(section) && logBlacklist[section]) )
		return false;
	return true;
}
