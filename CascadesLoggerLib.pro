TEMPLATE = lib

APP_NAME = CascadesLoggerLib

CONFIG += qt warn_on cascades10 shared

LIBS += -lbb

INCLUDEPATH += ../public
HEADERS += ../public/*.hpp

include(config.pri)
