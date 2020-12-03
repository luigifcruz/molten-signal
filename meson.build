project('moltensig', 'cpp',
        version: '1.0.0',
        default_options: ['cpp_std=c++17'])

## Dependencies
glfw3_dep = dependency('glfw3')
vulkan_dep = dependency('vulkan')

## Includes
inc = include_directories('include')

## Modules
subdir('include')
subdir('src')
subdir('test')