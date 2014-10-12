set(libeyeter_SRC
  program.cpp
)

set(libeyeter_HDR
  ../include/program.h
)

add_library(libeyeter SHARED ${libeyeter_SRC})
target_link_libraries(libeyeter m)