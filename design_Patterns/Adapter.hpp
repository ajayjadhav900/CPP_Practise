class ILanguage
{

    public:
    virtual void write() = 0;
    virtual void standardTimings() = 0;
};
class English:public ILanguage
{
    public:
    void write();
    void standardTimings();
};


class German{
    public:
    void write();
    void standardTimings();
};

class AdapterLangConverter :public English
{
    public:
German *Glang;
AdapterLangConverter(German *lang_arg)
{
    Glang=lang_arg;
}
    void write();
    void standardTimings();

};