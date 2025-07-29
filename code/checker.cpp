#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv); // ✅ Checker 專用初始化

    int n = inf.readInt(); // input file 的 n
    int m = inf.readInt();
    inf.readEoln();
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        a[i] = inf.readInt();
    }
    inf.readEoln();
    inf.readEof();

    int jury_x = ans.readInt(); // 正確答案
    int jury_y = ans.readInt();
    ans.readEof();

    int x = ouf.readInt(); // 參賽者答案
    int y = ouf.readInt();

    if (x < 1 || x > n || y < 1 || y > n)
        quitf(_wa, "位置超出範圍 %d %d", x, y);

    if (a[x] + a[y] != m)
        quitf(_wa, "a[x] + a[y] != m");

    quitf(_ok, "答案正確");
}
