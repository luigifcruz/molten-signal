#include <iostream>
#include <moltensig.h>

int main() {
    auto msg = MoltenSig::Glass();

    msg.Start();
    msg.PrintEnv();
}
