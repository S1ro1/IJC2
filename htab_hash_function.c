#include "hash_tab_struct.h"
#include "htab.h"

/**
 @brief calculates hash value of a string str
 @param str String whose hash is calculated
 @return Hash of string str
*/
size_t htab_hash_function(const char *str) {
  uint32_t h = 0; // musí mít 32 bitů
  const unsigned char *p;
  for (p = (const unsigned char *)str; *p != '\0'; p++)
    h = 65599 * h + *p;
  return h;
}
