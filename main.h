#ifndef __MAIN_H__
#define __MAIN_H__

/*
 * Power Management Controller
 */

#define PMC        0x400e0600

#define PMC_MCKR   0x030

/*
 * Peripheral IO Controller
 */

#define PIOA        0x400e0e00
#define PIOB        0x400e1000
#define PIOC        0x400e1200
#define PIOD        0x400e1400
#define PIOE        0x400e1600

#define PIO_PER     0x000    /* Enable               */
#define PIO_PDR     0x004    /* Disable              */
#define PIO_PSR     0x008    /* Status               */
#define PIO_OER     0x010    /* Output Enable        */
#define PIO_ODR     0x014    /* Output Disable       */
#define PIO_OSR     0x018    /* Output Status        */
#define PIO_IFER    0x020    /* Input Filter Enable  */
#define PIO_IFDR    0x024    /* Input Filter Disable */
#define PIO_IFSR    0x028    /* Input Filter Status  */
#define PIO_SODR    0x030    /* Set Output           */
#define PIO_CODR    0x034    /* Clear Output         */
#define PIO_ODSR    0x038    /* Output Data Status   */
#define PIO_PDSR    0x03C    /* Pin Data Status      */
#define PIO_IER     0x040    /* Interrupt Enable     */
#define PIO_IDR     0x044    /* Interrupt Disable    */
#define PIO_IMR     0x048    /* Interrupt Mask       */
#define PIO_ISR     0x04C    /* Interrupt Status     */
#define PIO_MDER    0x050    /* Multi-Driver Enable  */
#define PIO_MDDR    0x054    /* Multi-Driver Disable */
#define PIO_MDSR    0x058    /* Multi-Driver Status  */
#define PIO_PUDR    0x060    /* Pull-Up Disable      */
#define PIO_PUER    0x064    /* Pull-Up Enable       */
#define PIO_PUSR    0x068    /* Pull-Up Status       */
#define PIO_ABSR    0x070    /* Pull-Up Disable      */
#define PIO_SCIFSR  0x080    /* Glitch Inp. Filter   */
#define PIO_DIFSR   0x084    /* Debounce Inp. Filter */
#define PIO_IFDGSR  0x088    /* Glitch/Debounce Stat.*/
#define PIO_SCDR    0x08C    /* Slow Clock Debounce  */
#define PIO_OWER    0x0A0    /* Output Write Enable  */
#define PIO_OWDR    0x0A4    /* Output Write Disable  */
#define PIO_OWSR    0x0A8    /* Output Write Disable  */


#define WRITE(base,offset,d) (* (uint32_t *) (base + offset)) = d
#define READ(base,offset,d) (*(* (uint32_t *) (base + offset)))

#endif
