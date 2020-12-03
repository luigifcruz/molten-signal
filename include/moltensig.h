#ifndef MOLTENSIG_H
#define MOLTENSIG_H

#include "vulkan/render.h"

#include <iostream>

namespace MoltenSig {

class Glass {
    private:
        Vulkan::Render render;

    public:
        Glass();

        int Start();
        int Stop();

        void PrintEnv();
};

} // namespace MoltenSig

#endif
