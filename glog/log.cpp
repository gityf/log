#include "log.hpp"

#include <string>
#include <chrono>
#include <glog/log_severity.h>
#include <libgen.h>

namespace glogwrapper {

using namespace std;

struct trace_stats {
    std::string request_id = {""};
    std::chrono::time_point<std::chrono::system_clock> start_time =
    {std::chrono::system_clock::now()};
};
static thread_local trace_stats trace;

void SetRequestID(const std::string& id) {
    trace.request_id = id;
    trace.start_time = std::chrono::system_clock::now();
}
void ClearRequestID() {
    trace.request_id = "";
    trace.start_time = std::chrono::system_clock::now();;
}
const std::string& GetRequestID() {
    return trace.request_id;
}
int GetElapsedTime() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now() - trace.start_time).count();
}

static string log_path;
static void WriteToStderr(const char* message, int len) {
    fwrite(message, len, 1, stderr);
}

#define INFO_NAME(x) (string(x) + ".info_").c_str()
#define WARN_NAME(x) (string(x) + ".warn_").c_str()
#define ERROR_NAME(x) (string(x) + ".error_").c_str()
#define FATAL_NAME(x) (string(x) + ".fatal_").c_str()

void InstallLogHandler(const string& logPath, const string& prefix, int level) {

    google::InitGoogleLogging(prefix.c_str());
    google::InstallFailureSignalHandler();

    log_path = logPath;
    log_path = dirname(&log_path[0]);

    google::InstallFailureWriter(WriteToStderr);

    FLAGS_logbufsecs = 1;
    FLAGS_v = level - 3;

    string fullpath = logPath + prefix;
    google::SetLogDestination(google::INFO,     INFO_NAME(fullpath));
    google::SetLogDestination(google::WARNING,  WARN_NAME(fullpath));
    google::SetLogDestination(google::ERROR,   ERROR_NAME(fullpath));
    google::SetLogDestination(google::FATAL,   FATAL_NAME(fullpath));
}

}
