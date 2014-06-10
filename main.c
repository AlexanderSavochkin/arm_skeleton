#include <inttypes.h>

#include "main.h"

int main(void) {

    // Select main clock

    WRITE(PMC, PMC_MCKR, (1 << 0));

    // Configure built-in amber LED as an output
    WRITE(PIOB, PIO_OER, (1 << 27));

    volatile uint32_t cnt = 0;

    while (1) {
        WRITE(PIOB, PIO_CODR, (1 << 27));
        cnt++;

        WRITE(PIOB, PIO_SODR, (1 << 27));
        cnt++;
    }

    return 0;
}
