#include <functional>
#include <iostream>
#include <dlfcn.h>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    void* hDll = dlopen("./test.so", RTLD_LAZY);
    if (!hDll) {
        cerr << "Error: " << dlerror() << endl;
        return 1;
    }
    typedef unordered_map <string, void (*)(vector<string>::iterator, vector<vector<string> >, int &)> (*loadFunc)();
    loadFunc pAdd = (loadFunc)dlsym(hDll, "load");
    const char* error = dlerror();
    if (error != NULL) {
        cerr << "Error: " << error << endl;
        dlclose(hDll);
        return 1;
    }
    vector<string>::iterator ita;
    vector<vector<string> > lines;
    int line;
    typedef unordered_map <string, void (*)(vector<string>::iterator, vector<vector<string> >, int &)> mapType;
    mapType load = pAdd();
    for (mapType::iterator it = load.begin(); it != load.end(); it++) {
        (it->second)(ita, lines, line);
    }
    dlclose(hDll);
    return 0;
}