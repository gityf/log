#pragma once

#include <glog/logging.h>
#include <string>

namespace glogwrapper {

using std::string;

void SetRequestID(const std::string& id = "");
void ClearRequestID();
const std::string& GetRequestID();
int GetElapsedTime();

void InstallLogHandler(const string& logPath, const string& prefix, int level);

#define PREFIX                                       \
    "\trid:" << ::glogwrapper::GetRequestID()   <<   \
    "\tet:"  << ::glogwrapper::GetElapsedTime() << "\t" 

#define LOG_DEBUG1 VLOG(-2) << PREFIX
#define LOG_DEBUG2 VLOG(-1) << PREFIX
#define LOG_DEBUG3 VLOG(0) << PREFIX
#define LOG_INFO   LOG(INFO) << PREFIX
#define LOG_WARN   LOG(WARNING) << PREFIX
#define LOG_ERROR  LOG(ERROR) << PREFIX
#define LOG_FATAL  LOG(FATAL) << PREFIX
}
