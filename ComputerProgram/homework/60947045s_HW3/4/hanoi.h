#ifndef __hanoi_h
#define __hanoi_h
#include <stdint.h>
void Hanoi_recu(int8_t n, int8_t *arr, int8_t A, int8_t B, int8_t C);
int8_t find_disk(int32_t i, int8_t n);
void Hanoi_iter(int8_t n, int8_t A, int8_t B, int8_t C);
#endif
