// Copyright (C) 2015, diditaxi Inc.
// Author: huojiasen (huojiasen@diditaxi.com.cn)
//
// Description:

#include "log4cplus/logger.h"
#include "log4cplus/fileappender.h"
#include "log4cplus/layout.h"
#include "log4cplus/ndc.h"
#include "log4cplus/helpers/loglog.h"

using namespace log4cplus;
const int LOOP_COUNT = 200;

int main() {
    helpers::LogLog::getLogLog()->setInternalDebugging(true);

    SharedAppenderPtr append(new RollingFileAppender(LOG4CPLUS_TEXT("test.log"), 5*1000, 5));
    append->setName(LOG4CPLUS_TEXT("First"));
    append->setLayout( std::auto_ptr<Layout> ( new TTCCLayout() ) );
    Logger::getRoot().addAppender(append);

    Logger root = Logger::getRoot();
    Logger test = Logger::getInstance(LOG4CPLUS_TEXT("test"));
    Logger subTest = Logger::getInstance(LOG4CPLUS_TEXT("test.subtest"));
    for (int i=0;i<LOOP_COUNT;i++) {
        LOG4CPLUS_DEBUG(subTest, "Enter loop #" <<i);
    }
    return 0;
}

