project('OpenGlTest', ['c', 'cpp'],
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++17'])

gl = dependency('gl')
glfw = dependency('glfw3')
glew = dependency('glew')
include = include_directories('./include')

src = [
  './src/main.cpp',
  './src/betmine/debug.cpp',
  './src/gl/gl.c',
]


exe = executable('OpenGlTest', src,
  install : true, dependencies : [gl, glfw, glew], include_directories : include)

test('basic', exe)
