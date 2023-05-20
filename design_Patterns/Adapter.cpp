#include <iostream>
#include "Adapter.hpp"
using namespace std;
void English::write()
{
    cout << " I am English, Standard language logs.\n";
}

void English::standardTimings()
{
    cout << "convert to standard time zone\n";
}

void German::write()
{
    cout << "Uses German langugae for the logs.\n";
}

void German::standardTimings()
{
    cout << "Converted to German timings\n";
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
    ILanguage *eng = new English();
    eng->write();
    eng->standardTimings();

    German *ger = new German();
    ger->write();
    ger->standardTimings();

    cout << "want the english language from German";
    AdapterLangConverter *alc = new AdapterLangConverter(ger);
    LogsConverter(alc);
    return 0;
}
