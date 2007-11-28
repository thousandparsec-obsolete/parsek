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
     connecttoserverdialog.cpp
     converters.cpp
     importobject.cpp
     loggerwidget.cpp
     mainwindow.cpp
     messagesmodel.cpp
     objectsitem.cpp
     objectsmodel.cpp
     parsek.cpp )

kde4_add_ui_files( parsekSources
                   connecttoserverdialog.ui
                   loggerwidget.ui )

kde4_add_executable( parsek ${parsekSources} )

target_link_libraries( parsek ${KDE4_KDEUI_LIBS} ${TPPROTO_LIBRARY} )

install( TARGETS parsek DESTINATION ${BIN_INSTALL_DIR} )
install( FILES parsek.desktop  DESTINATION  ${XDG_APPS_INSTALL_DIR} )
