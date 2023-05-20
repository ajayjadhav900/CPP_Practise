#include <iostream>
#include "Adapter.hpp"
#include "logger.hpp"
using namespace std;
void logTest(void);
loglevel_e loglevel = logDEBUG2; // Define the log level variable

void English::write()
{
    log(logDEBUG1) <<  " I am English, Standard language logs.\n";
}

void English::standardTimings()
{
    log(logDEBUG1) <<  "convert to standard time zone\n";
}

void German::write()
{
    log(logDEBUG1) << "Uses German langugae for the logs.\n";
}

void German::standardTimings()
{
    log(logDEBUG2) <<  "Converted to German timings\n";
}

void AdapterLangConverter::write()
{
    Glang->write();
}
void AdapterLangConverter::standardTimings()
{
    Glang->standardTimings();
}

void LogsConverter(ILanguage *lang)
{
    lang->write();
    lang->standardTimings();
}

int main()
{
    //loglevel_e loglevel;

   loglevel = logDEBUG2;
    ILanguage *eng = new English();
    eng->write();
    eng->standardTimings();

    German *ger = new German();
    ger->write();
    ger->standardTimings();

    log(logDEBUG1) <<  "want the english language from German";
    AdapterLangConverter *alc = new AdapterLangConverter(ger);
    LogsConverter(alc);

    //logTest();
    return 0;
}

void logTest(void) {
    loglevel_e loglevel_save = loglevel;

    loglevel_save = logDEBUG1;

    log(logINFO) << "foo " << "bar " << "baz";

    int count = 3;
    log(logDEBUG) << "A loop with "    << count << " iterations";
    for (int i = 0; i != count; ++i)
    {
        log(logDEBUG1) << "the counter i = " << i;
        log(logDEBUG2) << "the counter i = " << i;
    }

    loglevel = loglevel_save;
}