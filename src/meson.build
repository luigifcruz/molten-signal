libmsg_sources = [
    'moltensig.cpp',
    'vulkan/render.cpp',
    'vulkan/tools.cpp',
]

libmsg = shared_library('moltensig',
                        libmsg_sources,
                        include_directories: inc,
                        dependencies: [
                            glfw3_dep,
                            vulkan_dep,
                        ],
                        install: true)
