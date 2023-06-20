#ifndef __BLOK_SQUARE_H
#define __BLOK_SQUARE_H

typedef struct square__
{
    int x;
    int y;
    int width;
    int height;
} square;

void square_create(int x, int y, int width, int height);

void square_position_set(int x, int y);

void square_size_set(int width, int height);

void square_free();

#endif