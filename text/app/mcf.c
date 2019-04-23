/**
 * mcf.c -- для перемещения курсора на один символ вправо, если это возможно
 *
 * Copyright (c) 2018, Zdorovennov Maksim <zdoroven@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "common.h"
#include "text/text.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void move_cursor_forward(int index, char *contents, int cursor,
                                void *data);

void mcf(text txt) { process_forward(txt, move_cursor_forward, txt); }

static void move_cursor_forward(int index, char *contents, int cursor,
                                void *data) {

  assert(contents != NULL);

  UNUSED(data);

  if (cursor >= 0) {

    int y = strlen(contents);

    if (cursor < y - 1) {
      mwcrsr(data, index + 1, cursor + 2);
    }
  }
}
