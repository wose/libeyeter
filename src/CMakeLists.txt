set(libeyeter_SRC
  Procedure.cpp
  Program.cpp
)

set(libeyeter_HDR
  ../include/Procedure.h
  ../include/Program.h
)

set(pugixml_SRC
  ../3rdparty/pugixml/src/pugixml.cpp
)

add_library(eyeter SHARED ${libeyeter_SRC} ${pugixml_SRC})
target_link_libraries(eyeter)
