#include <inttypes.h>

#define PIOB_PER    0x400e1000
#define PIOB_PDR    0x400e1004
#define PIOB_PSR    0x400e1008
#define PIOB_OER    0x400e1010
#define PIOB_SODR   0x400e1030 /* Set Output */
#define PIOB_CODR   0x400e1034 /* Clear Output */

#define PIO(addr,d) (* (uint32_t *) addr) = d

int main(void) {

    // Configure built-in amber LED as an output
    PIO(PIOB_OER, (1 << 27));

    volatile uint32_t cnt = 0;

    while (1) {
        PIO(PIOB_SODR, cnt++);
    }

    return 0;
}
