#include <functional>
#include <iostream>
#include <windows.h>
#include <map>
#include <vector>
using namespace std;

int main() {
    HMODULE hDll = LoadLibrary("test.dll");
    if (hDll == NULL) {
        std::cerr << "Error: " << GetLastError() << std::endl;
        return 1;
    }
    typedef map <string, void (*)(vector<string>::iterator, vector<vector<string> >, int &)> (*loadFunc)();
    loadFunc pAdd = (loadFunc)GetProcAddress(hDll, "load");
    if (pAdd == NULL) {
        std::cerr << "Error: " << GetLastError() << std::endl;
        FreeLibrary(hDll);
        return 1;
    }
    vector<string>::iterator ita;
    vector<vector<string> > lines;
    int line;
    typedef map <string, void (*)(vector<string>::iterator, vector<vector<string> >, int &)> mapType;
    mapType load = pAdd();
    for (mapType::iterator it = load.begin(); it != load.end(); it++) {
        (it->second)(ita, lines, line);
    }
    FreeLibrary(hDll);
    return 0;
}