project( parsek )

set( CMAKE_MODULE_PATH 
     ${PROJECT_SOURCE_DIR}/cmake
     ${CMAKE_SOURCE_DIR}/cmake
     ${CMAKE_MODULE_PATH} )

find_package( KDE4 REQUIRED )
find_package( TPProto REQUIRED )

include( KDE4Defaults )
include_directories( ${KDE4_INCLUDES} ${TPPROTO_INCLUDE_DIR} )

add_definitions( ${KDE4_DEFINITIONS} )

set( parsekSources
     parsek.cpp
     mainwindow.cpp
     connecttoserverdialog.cpp
     converters.cpp
     messagesmodel.cpp )

kde4_add_ui_files( parsekSources
                   connecttoserverdialog.ui )

kde4_automoc( ${parsekSources} )
kde4_add_executable( parsek ${parsekSources} )

target_link_libraries( parsek ${KDE4_KDEUI_LIBS} ${TPPROTO_LIBRARY} )

install( TARGETS parsek DESTINATION bin )
install( FILES parsek.desktop DESTINATION ${XDG_APPS_DIR} )