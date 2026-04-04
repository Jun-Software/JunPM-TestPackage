#include <map>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

extern "C" void run(vector<string>::iterator it, vector<vector<string> > lines, int &line) {
    cout << "test" << endl;
}
extern "C" map <string, void (*)(vector<string>::iterator, vector<vector<string> >, int &)> load() {
    map <string, void (*)(vector<string>::iterator, vector<vector<string> >, int &)> tmp;
    tmp["test"] = run;
    return tmp;
}