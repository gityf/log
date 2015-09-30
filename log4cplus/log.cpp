#include "log.h"

using namespace log4cplus;
using namespace log4cplus::helpers;

Logger norm_logger = log4cplus::Logger::getInstance("norm");
Logger err_logger = log4cplus::Logger::getInstance("error");

void init_log4cpp(std::string &rCurrDir) {
    std::string sFullFileName(rCurrDir + "/config/log.properties");
    PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT(sFullFileName.c_str()));
    LOG_TRACE("init_log4cpp sFullFileName:%s", sFullFileName.c_str());
}
