#include <iostream>
#include <vector>
#include <string>
using namespace std;

class IFileSystem {
public:
    virtual void FileSystemDetails() = 0;
    virtual void Insert(IFileSystem*) = 0;
    virtual void Display() = 0;

    virtual ~IFileSystem() {
        cout << " ~IFileSystem()\n";
    }
};

class File : public IFileSystem {
public:
    File(const string& name) : Name(name) {}
    void FileSystemDetails() override {
        cout << "\tFile: " << Name << endl;
    }
    void Insert(IFileSystem*) override {
        // Do nothing as File cannot contain other elements
    }
    void Display() override {
        FileSystemDetails();
    }
    ~File() {
        cout << " ~File()\n";
    }

private:
    string Name;
};

class Directory : public IFileSystem {
public:
    Directory(const string& name) : Name(name) {}
    void FileSystemDetails() override {
        cout << "Directory: " << Name << endl;
    }
    void Display() override {
        FileSystemDetails(); // Call FileSystemDetails of the Directory itself
        for (auto itr : Directories) {
            itr->Display(); // Call Display of child components
        }
    }
    void Insert(IFileSystem* ptr) {
        Directories.push_back(ptr);
    }
    ~Directory() {
        for (auto itr : Directories) {
            delete itr;
        }
        cout << " ~Directory()\n";
    }

private:
    string Name;
    vector<IFileSystem*> Directories;
};

int main() {
    IFileSystem* root = new Directory("root");
    IFileSystem* opt = new Directory("opt");
    IFileSystem* config = new File("config.xml");
    opt->Insert(config);
    IFileSystem* emc = new Directory("emc");
    opt->Insert(emc);
    IFileSystem* save = new File("nsrvproxy_save");
    emc->Insert(save);
    root->Insert(opt);

    // Display the entire file system structure
    root->Display();

    // Properly delete the root
    delete root;

    return 0;
}
