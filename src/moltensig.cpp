#include "moltensig.h"

namespace MoltenSig {

Glass::Glass() {
    std::cout << "Starting MoltenSig" << std::endl;
}

void Glass::PrintEnv() {
    std::cout << "MoltenSig Environment:" << std::endl;
    render.PrintEnv();
}

int Glass::Start() {
    render.OpenWindow();
}

int Glass::Stop() {
    render.CloseWindow();
}

} // namespace MoltenSig
