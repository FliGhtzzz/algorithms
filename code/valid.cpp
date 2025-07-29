#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 100'000, "n");
    inf.readEoln();

    for (int i = 0; i < n; i++) {
        inf.readInt(1, 100'000, "a");
        inf.readSpace();
        inf.readInt(1, 100'000, "b");
        inf.readEoln();
    }

    inf.readEof();
}
