#include "libmx.h"

void mx_print_unicode(wchar_t c) {
    char utf8[4];  
    int len = 0;

    if (c < 0x80) {
        // 1-byte encoding (ASCII)
        utf8[0] = c;
        len = 1;
    }
    else if (c < 0x800) {
        // 2-byte encoding
        utf8[0] = (c >> 6) | 0xC0;      // First byte: 110xxxxx
        utf8[1] = (c & 0x3F) | 0x80;    // Second byte: 10xxxxxx
        len = 2;
    }
    else if (c < 0x10000) {
        // 3-byte encoding
        utf8[0] = (c >> 12) | 0xE0;     // First byte: 1110xxxx
        utf8[1] = ((c >> 6) & 0x3F) | 0x80;  // Second byte: 10xxxxxx
        utf8[2] = (c & 0x3F) | 0x80;    // Third byte: 10xxxxxx
        len = 3;
    }
    else if (c < 0x110000) {
        // 4-byte encoding
        utf8[0] = (c >> 18) | 0xF0;     // First byte: 11110xxx
        utf8[1] = ((c >> 12) & 0x3F) | 0x80; // Second byte: 10xxxxxx
        utf8[2] = ((c >> 6) & 0x3F) | 0x80;  // Third byte: 10xxxxxx
        utf8[3] = (c & 0x3F) | 0x80;    // Fourth byte: 10xxxxxx
        len = 4;
    }

    write(1, utf8, len);
}

