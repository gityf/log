#include "log.hpp"

int main(int argc, char* argv[]) {
    // install log handler
    glogwrapper::InstallLogHandler("log", "test_prefix", 5);

    LOG_INFO << "start the server";

    LOG_INFO << "end the server";
    return 0;
}
