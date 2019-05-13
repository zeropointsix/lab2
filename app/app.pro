TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += editor.c \
	shownum.c \
	mcf.c \
	rh.c \
    load.c \
    show.c \
    mwcrsr.c \
    text/append_line.c \
    text/delete_line.c \
    text/change_cursor_position.c \
    text/process_forward.c \
    text/create_text.c \
    text/prepend_line.c \
    text/remove_all.c


HEADERS += text/_text.h \
    text/text.h \
    data.h \
    common.h

QMAKE_CFLAGS += -Wall -Wextra

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
