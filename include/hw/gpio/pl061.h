/*
 * Arm PrimeCell PL061 General Purpose IO with additional
 * Luminary Micro Stellaris bits.
 *
 * Copyright (c) 2007 CodeSourcery.
 * Written by Paul Brook
 *            Maros Zatko
 *
 * This code is licensed under the GPL.
 */

#ifndef PL061_h_
#include "qemu/osdep.h"
#include "sysemu/char.h"
#include "hw/sysbus.h"
#include "qemu/log.h"

//#define DEBUG_PL061 1

#ifdef DEBUG_PL061
#define DPRINTF(fmt, ...) \
do { printf("pl061: " fmt , ## __VA_ARGS__); } while (0)
#define BADF(fmt, ...) \
do { fprintf(stderr, "pl061: error: " fmt , ## __VA_ARGS__); exit(1);} while (0)
#else
#define DPRINTF(fmt, ...) do {} while(0)
#define BADF(fmt, ...) \
do { fprintf(stderr, "pl061: error: " fmt , ## __VA_ARGS__);} while (0)
#endif

static const uint8_t pl061_id[12] =
  { 0x00, 0x00, 0x00, 0x00, 0x61, 0x10, 0x04, 0x00, 0x0d, 0xf0, 0x05, 0xb1 };
static const uint8_t pl061_id_luminary[12] =
  { 0x00, 0x00, 0x00, 0x00, 0x61, 0x00, 0x18, 0x01, 0x0d, 0xf0, 0x05, 0xb1 };

#define TYPE_PL061 "pl061"
#define PL061(obj) OBJECT_CHECK(PL061State, (obj), TYPE_PL061)

typedef struct PL061State {
    SysBusDevice parent_obj;

    MemoryRegion iomem;
    uint32_t locked;
    uint32_t data;
    uint32_t old_out_data;
    uint32_t old_in_data;
    uint32_t dir;
    uint32_t isense;
    uint32_t ibe;
    uint32_t iev;
    uint32_t im;
    uint32_t istate;
    uint32_t afsel;
    uint32_t dr2r;
    uint32_t dr4r;
    uint32_t dr8r;
    uint32_t odr;
    uint32_t pur;
    uint32_t pdr;
    uint32_t slr;
    uint32_t den;
    uint32_t cr;
    uint32_t amsel;
    CharDriverState *chr;
    qemu_irq irq;
    qemu_irq out[8];
    const unsigned char *id;
    uint32_t rsvd_start; /* reserved area: [rsvd_start, 0xfcc] */
} PL061State;

#endif
