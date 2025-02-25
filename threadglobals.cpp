#include "threadglobals.h"
#include "cassert"

thread_local Authentication *ThreadGlobals::auth = nullptr;
thread_local ThreadData *ThreadGlobals::threadData = nullptr;
thread_local Settings *ThreadGlobals::settings = nullptr;

void ThreadGlobals::assign(Authentication *auth)
{
#ifndef TESTING
    assert(ThreadGlobals::auth == nullptr);
#endif
    ThreadGlobals::auth = auth;
}

Authentication *ThreadGlobals::getAuth()
{
    return auth;
}

void ThreadGlobals::assignThreadData(ThreadData *threadData)
{
#ifndef TESTING
    assert(ThreadGlobals::threadData == nullptr);
#endif
    ThreadGlobals::threadData = threadData;
}

ThreadData *ThreadGlobals::getThreadData()
{
    return threadData;
}

void ThreadGlobals::assignSettings(Settings *settings)
{
#ifndef TESTING
    assert(ThreadGlobals::settings == nullptr || ThreadGlobals::settings == settings);
#endif
    ThreadGlobals::settings = settings;
}

Settings *ThreadGlobals::getSettings()
{
    return settings;
}
