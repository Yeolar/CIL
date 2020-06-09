# Copyright 2017 Yeolar

file(GLOB CIL_SRCS *.cc io/*.cc mat/*.cc transform/*.cc)
file(GLOB CIL_HDRS */*.h)

add_library(CIL OBJECT ${CIL_SRCS})

install(FILES ${CIL_HDRS} DESTINATION include/CIL)
