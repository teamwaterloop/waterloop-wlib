#if (defined(__AVR_ATmega1280__)  || \
     defined(__AVR_ATmega2560__)  || \
     defined(__AVR_ATmega1284__)  || \
     defined(__AVR_ATmega1284P__) || \
     defined(__AVR_ATmega644__)   || \
     defined(__AVR_ATmega644A__)  || \
     defined(__AVR_ATmega644P__)  || \
     defined(__AVR_ATmega644PA__)) && !defined(COSA_H)

#include "New.h"

void *operator new(decltype(sizeof(0)), void *ptr) noexcept {
    return ptr;
}

#elif defined(WLIB_DEBUG) && !defined(COSA_H)
#else

#include <stdlib.h>
#include "New.h"

void *operator new(decltype(sizeof(0)) n) noexcept(false) {
    return malloc(n);
}

void *operator new(decltype(sizeof(0)), void *ptr) noexcept {
    return ptr;
}

void operator delete(void *ptr) throw() {
    free(ptr);
}

void *operator new[](decltype(sizeof(0)) n) noexcept(false) {
    return malloc(n);
}

void operator delete[](void *ptr) throw() {
    free(ptr);
}

#endif