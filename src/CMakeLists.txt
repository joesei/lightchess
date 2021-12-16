

cmake_minimum_required (VERSION 3.8)

find_package (wxWidgets 3.1.5 REQUIRED)

if (APPLE)
    add_executable (lightchess MACOSX_BUNDLE chess_main.cpp chess_main.h frame_main.cpp frame_main.h)
else ()
    add_executable (lightchess WIN32 chess_main.cpp chess_main.h frame_main.cpp frame_main.h)
endif ()

include (${wxWidgets_USE_FILE})
target_link_libraries (lightchess ${wxWidgets_LIBRARIES})