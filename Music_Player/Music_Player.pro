TEMPLATE = app
TARGET = "Music Player"

QT += quick

SOURCES = \
    main.cpp

OTHER_FILES += \
    qml/main.qml

RESOURCES += \
    Music_player.qrc

RC_ICONS = images/icon.ico

target.path = ./
INSTALLS += target

DISTFILES += \
    images/icon.ico
