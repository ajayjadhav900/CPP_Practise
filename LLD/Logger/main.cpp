#include "Logger.hpp"
extern loglevel_e loglevel;
loglevel_e loglevel = logDEBUG2; // Define and set the log level variable to logDEBUG
void logTest(void);
int main() {

    logTest();
    return 0;
}


void logTest(void) {

    log(logINFO) << "foo " << "bar " << "baz";

    int count = 3;
    log(logDEBUG) << "A loop with "    << count << " iterations";
    for (int i = 0; i != count; ++i)
    {
        log(logDEBUG1) << "the counter i = " << i;
        log(logDEBUG2) << "the counter i = " << i;
    }

}