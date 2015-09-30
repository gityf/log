#include "log.h"
#include <string>
#include <unistd.h>

using std::string;

int main(int argc, char **argv)
{
    char pCurrDir[256] = {0};
    getcwd(pCurrDir, sizeof(pCurrDir));
    if(0 == pCurrDir[0])
    {
        LOG_ERROR("Failed to get_curr_dir");
        return -1;
    }else{
        LOG_NOTICE("Get curr dir:%s", pCurrDir);
    }

    string sCurrDir(pCurrDir);
    init_log4cpp(sCurrDir);

    log_notice("--------------------------------------------------------------");
    log_notice("|--------------test log main starting------------------------|");
    log_notice("--------------------------------------------------------------");
    return 0;
}
