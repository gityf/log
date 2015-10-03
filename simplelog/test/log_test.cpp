/*
** Copyright (C) 2015 Wang Yaofu
** All rights reserved.
**
**Author:Wang Yaofu voipman@qq.com
**Description: The source file of main.
*/

#include "log.h"

int main(int argc, char* argv[]) {
    log_init(LL_INFO, "log", "test");
    LOG_INFO("start the server");

    LOG_WARN("end the server");
    log_close();
    return 0;
}
