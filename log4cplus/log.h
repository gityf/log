#ifndef _LOG_H_
#define _LOG_H_

#include <cstdlib>
#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/helpers/stringhelper.h>
#include <string>

extern log4cplus::Logger norm_logger;
extern log4cplus::Logger err_logger;

/*
#define log_fatal(errno, content)\
    LOG4CPLUS_FATAL(err_logger, " errno:"<<errno<<" - "<<content)

#define log_error(errno, content)\
    LOG4CPLUS_ERROR(err_logger, " errno:"<<errno<<" - "<<content)

#define log_warn(errno, content) \
    LOG4CPLUS_WARN(err_logger, " errno:"<<errno<<" - "<<content)
*/

#define log_fatal(content)\
	LOG4CPLUS_FATAL(err_logger, content)

#define log_error(content)\
    LOG4CPLUS_ERROR(err_logger, content)

#define log_warn(content) \
    LOG4CPLUS_WARN(err_logger, content)

#define log_notice(content) \
    LOG4CPLUS_INFO(norm_logger, content)

#define log_debug(content) \
    LOG4CPLUS_DEBUG(norm_logger, content)

#define log_trace(content) \
    LOG4CPLUS_TRACE(norm_logger, content)


#define LOG_PRINT(log_fmt, log_arg...) \
    do{ \
        printf("%s:%d " log_fmt "\n", __FILE__, __LINE__, ##log_arg); \
    } while (0);

#define LOG_ERROR(log_fmt, log_arg...) LOG_PRINT(log_fmt, ##log_arg)
#define LOG_WARN(log_fmt, log_arg...) LOG_PRINT(log_fmt, ##log_arg)
#define LOG_NOTICE(log_fmt, log_arg...) LOG_PRINT(log_fmt, ##log_arg)
#define LOG_TRACE(log_fmt, log_arg...) LOG_PRINT(log_fmt, ##log_arg)
#define LOG_DEBUG(log_fmt, log_arg...) LOG_PRINT(log_fmt, ##log_arg)

void init_log4cpp(std::string &rCurrDir);
#endif
