lib_src = files([
    'moltensig.cpp',
    'vulkan/render.cpp',
    'vulkan/tools.cpp',
])

lib_spirv = [
    'vulkan/shaders/triangle.frag',
    'vulkan/shaders/triangle.vert'
]

lib_dep = [
    glfw3_dep,
    vulkan_dep
]

glsl_comp = find_program('glslangValidator')
glsl_gen = generator(glsl_comp,
                     output: '@PLAINNAME@.h',
                     arguments: [ '-V', '--vn', '@EXTRA_ARGS@', '@INPUT@', '-o', '@OUTPUT@' ])

foreach s : lib_spirv
    lib_src += glsl_gen.process(s, extra_args: s.underscorify().to_upper())
endforeach

libmsg = shared_library('moltensig',
                        lib_src,
                        include_directories: inc,
                        dependencies: lib_dep,
                        install: true)
