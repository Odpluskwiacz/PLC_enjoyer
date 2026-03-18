/*
 * This file is part of OpenPLC Runtime
 *
 * Copyright (C) 2023 Autonomy, GP Orcullo
 * Based on the work by GP Orcullo on Beremiz for uC
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <stdbool.h>

// Include defines.h first for Arduino builds to set USE_*_BLOCKS macros
// before iec_std_FB.h processes its conditional includes
#ifdef ARDUINO
#include "../examples/Baremetal/defines.h"
#endif

#include "iec_types_all.h"
#include "POUS.h"

#define SAME_ENDIANNESS      0
#define REVERSE_ENDIANNESS   1

char plc_program_md5[] = "c050ad3ef6f26c62b3fcf0dafcfb75f8";

uint8_t endianness;


extern MAIN RES0__INSTANCE0;

static const struct {
    void *ptr;
    __IEC_types_enum type;
} debug_vars[] = {
    {&(RES0__INSTANCE0.DELAY), TIME_ENUM},
    {&(RES0__INSTANCE0.TON0.EN), BOOL_ENUM},
    {&(RES0__INSTANCE0.TON0.ENO), BOOL_ENUM},
    {&(RES0__INSTANCE0.TON0.IN), BOOL_ENUM},
    {&(RES0__INSTANCE0.TON0.PT), TIME_ENUM},
    {&(RES0__INSTANCE0.TON0.Q), BOOL_ENUM},
    {&(RES0__INSTANCE0.TON0.ET), TIME_ENUM},
    {&(RES0__INSTANCE0.TON0.STATE), SINT_ENUM},
    {&(RES0__INSTANCE0.TON0.PREV_IN), BOOL_ENUM},
    {&(RES0__INSTANCE0.TON0.CURRENT_TIME), TIME_ENUM},
    {&(RES0__INSTANCE0.TON0.START_TIME), TIME_ENUM},
    {&(RES0__INSTANCE0.TOF0.EN), BOOL_ENUM},
    {&(RES0__INSTANCE0.TOF0.ENO), BOOL_ENUM},
    {&(RES0__INSTANCE0.TOF0.IN), BOOL_ENUM},
    {&(RES0__INSTANCE0.TOF0.PT), TIME_ENUM},
    {&(RES0__INSTANCE0.TOF0.Q), BOOL_ENUM},
    {&(RES0__INSTANCE0.TOF0.ET), TIME_ENUM},
    {&(RES0__INSTANCE0.TOF0.STATE), SINT_ENUM},
    {&(RES0__INSTANCE0.TOF0.PREV_IN), BOOL_ENUM},
    {&(RES0__INSTANCE0.TOF0.CURRENT_TIME), TIME_ENUM},
    {&(RES0__INSTANCE0.TOF0.START_TIME), TIME_ENUM},
    {&(RES0__INSTANCE0.TOF1.EN), BOOL_ENUM},
    {&(RES0__INSTANCE0.TOF1.ENO), BOOL_ENUM},
    {&(RES0__INSTANCE0.TOF1.IN), BOOL_ENUM},
    {&(RES0__INSTANCE0.TOF1.PT), TIME_ENUM},
    {&(RES0__INSTANCE0.TOF1.Q), BOOL_ENUM},
    {&(RES0__INSTANCE0.TOF1.ET), TIME_ENUM},
    {&(RES0__INSTANCE0.TOF1.STATE), SINT_ENUM},
    {&(RES0__INSTANCE0.TOF1.PREV_IN), BOOL_ENUM},
    {&(RES0__INSTANCE0.TOF1.CURRENT_TIME), TIME_ENUM},
    {&(RES0__INSTANCE0.TOF1.START_TIME), TIME_ENUM},
    {&(RES0__INSTANCE0.TON3.EN), BOOL_ENUM},
    {&(RES0__INSTANCE0.TON3.ENO), BOOL_ENUM},
    {&(RES0__INSTANCE0.TON3.IN), BOOL_ENUM},
    {&(RES0__INSTANCE0.TON3.PT), TIME_ENUM},
    {&(RES0__INSTANCE0.TON3.Q), BOOL_ENUM},
    {&(RES0__INSTANCE0.TON3.ET), TIME_ENUM},
    {&(RES0__INSTANCE0.TON3.STATE), SINT_ENUM},
    {&(RES0__INSTANCE0.TON3.PREV_IN), BOOL_ENUM},
    {&(RES0__INSTANCE0.TON3.CURRENT_TIME), TIME_ENUM},
    {&(RES0__INSTANCE0.TON3.START_TIME), TIME_ENUM},
    {&(RES0__INSTANCE0.TOF2.EN), BOOL_ENUM},
    {&(RES0__INSTANCE0.TOF2.ENO), BOOL_ENUM},
    {&(RES0__INSTANCE0.TOF2.IN), BOOL_ENUM},
    {&(RES0__INSTANCE0.TOF2.PT), TIME_ENUM},
    {&(RES0__INSTANCE0.TOF2.Q), BOOL_ENUM},
    {&(RES0__INSTANCE0.TOF2.ET), TIME_ENUM},
    {&(RES0__INSTANCE0.TOF2.STATE), SINT_ENUM},
    {&(RES0__INSTANCE0.TOF2.PREV_IN), BOOL_ENUM},
    {&(RES0__INSTANCE0.TOF2.CURRENT_TIME), TIME_ENUM},
    {&(RES0__INSTANCE0.TOF2.START_TIME), TIME_ENUM},
    {&(RES0__INSTANCE0.LID_AT_PLACE), BOOL_P_ENUM},
    {&(RES0__INSTANCE0.LID_CLAMPED), BOOL_P_ENUM},
    {&(RES0__INSTANCE0.BASE_AT_PLACE), BOOL_P_ENUM},
    {&(RES0__INSTANCE0.BASE_CLAMPED), BOOL_P_ENUM},
    {&(RES0__INSTANCE0.MOVING_X), BOOL_P_ENUM},
    {&(RES0__INSTANCE0.MOVING_Z), BOOL_P_ENUM},
    {&(RES0__INSTANCE0.ITEM_DETECTED), BOOL_P_ENUM},
    {&(RES0__INSTANCE0.PART_LEAVING), BOOL_P_ENUM},
    {&(RES0__INSTANCE0.LIDS_CONVEYOR), BOOL_O_ENUM},
    {&(RES0__INSTANCE0.CLAMP_LID), BOOL_O_ENUM},
    {&(RES0__INSTANCE0.POS_RAISE_LID), BOOL_O_ENUM},
    {&(RES0__INSTANCE0.BASE_CONVEYOR), BOOL_O_ENUM},
    {&(RES0__INSTANCE0.CLAMP_BASE), BOOL_O_ENUM},
    {&(RES0__INSTANCE0.MOVE_X), BOOL_O_ENUM},
    {&(RES0__INSTANCE0.MOVE_Z), BOOL_O_ENUM},
    {&(RES0__INSTANCE0.GRAB), BOOL_O_ENUM},
    {&(RES0__INSTANCE0.START), BOOL_P_ENUM},
};

#define VAR_COUNT               68

uint16_t get_var_count(void)
{
    return VAR_COUNT;
}

size_t get_var_size(size_t idx)
{
    if (idx >= VAR_COUNT)
    {
        return 0;
    }
    switch (debug_vars[idx].type) {
    case BOOL_ENUM:
    case BOOL_O_ENUM:
    case BOOL_P_ENUM:
        return sizeof(BOOL);
    case SINT_ENUM:
        return sizeof(SINT);
    case TIME_ENUM:
        return sizeof(TIME);
    default:
        return 0;
    }
}

void *get_var_addr(size_t idx)
{
    void *ptr = debug_vars[idx].ptr;

    switch (debug_vars[idx].type) {
    case BOOL_ENUM:
        return (void *)&((__IEC_BOOL_t *) ptr)->value;
    case BOOL_O_ENUM:
    case BOOL_P_ENUM:
        return (void *)((((__IEC_BOOL_p *) ptr)->flags & __IEC_FORCE_FLAG)
                        ? &(((__IEC_BOOL_p *) ptr)->fvalue)
                        : ((__IEC_BOOL_p *) ptr)->value);
    case SINT_ENUM:
        return (void *)&((__IEC_SINT_t *) ptr)->value;
    case TIME_ENUM:
        return (void *)&((__IEC_TIME_t *) ptr)->value;
    default:
        return 0;
    }
}

void force_var(size_t idx, bool forced, void *val)
{
    void *ptr = debug_vars[idx].ptr;

    if (forced) {
        size_t var_size = get_var_size(idx);
        switch (debug_vars[idx].type) {
        case BOOL_ENUM: {
            memcpy(&((__IEC_BOOL_t *) ptr)->value, val, var_size);
            ((__IEC_BOOL_t *) ptr)->flags |= __IEC_FORCE_FLAG;
            break;
        }
    
        case BOOL_O_ENUM: {
            memcpy((((__IEC_BOOL_p *) ptr)->value), val, var_size);
            memcpy(&((__IEC_BOOL_p *) ptr)->fvalue, val, var_size);
            ((__IEC_BOOL_p *) ptr)->flags |= __IEC_FORCE_FLAG;
            break;
        }
        case BOOL_P_ENUM: {
            memcpy(&((__IEC_BOOL_p *) ptr)->fvalue, val, var_size);
            ((__IEC_BOOL_p *) ptr)->flags |= __IEC_FORCE_FLAG;
            break;
        }
        case SINT_ENUM: {
            memcpy(&((__IEC_SINT_t *) ptr)->value, val, var_size);
            ((__IEC_SINT_t *) ptr)->flags |= __IEC_FORCE_FLAG;
            break;
        }
    
        case TIME_ENUM: {
            memcpy(&((__IEC_TIME_t *) ptr)->value, val, var_size);
            ((__IEC_TIME_t *) ptr)->flags |= __IEC_FORCE_FLAG;
            break;
        }
    
        default:
            break;
        }
    } else {
        switch (debug_vars[idx].type) {
        case BOOL_ENUM:
            ((__IEC_BOOL_t *) ptr)->flags &= ~__IEC_FORCE_FLAG;
            break;
        case BOOL_O_ENUM:
        case BOOL_P_ENUM:
            ((__IEC_BOOL_p *) ptr)->flags &= ~__IEC_FORCE_FLAG;
            break;
        case SINT_ENUM:
            ((__IEC_SINT_t *) ptr)->flags &= ~__IEC_FORCE_FLAG;
            break;
        case TIME_ENUM:
            ((__IEC_TIME_t *) ptr)->flags &= ~__IEC_FORCE_FLAG;
            break;
        default:
            break;
        }
    }
}

void swap_bytes(void *ptr, size_t size)
{
    uint8_t *bytePtr = (uint8_t *)ptr;
    size_t i;
    for (i = 0; i < size / 2; ++i)
    {
        uint8_t temp = bytePtr[i];
        bytePtr[i] = bytePtr[size - 1 - i];
        bytePtr[size - 1 - i] = temp;
    }
}

void trace_reset(void)
{
    for (size_t i=0; i < VAR_COUNT; i++)
    {
        force_var(i, false, 0);
    }
}

void set_trace(size_t idx, bool forced, void *val)
{
    if (idx >= 0 && idx < VAR_COUNT)
    {
        if (endianness == REVERSE_ENDIANNESS)
        {
            // Prevent swapping for STRING type
            if (debug_vars[idx].type == STRING_ENUM)
            {
                // Do nothing
                ;
            }
            else
            {
                swap_bytes(val, get_var_size(idx));
            }
        }

        force_var(idx, forced, val);
    }
}

void set_endianness(uint8_t value)
{
    if (value == SAME_ENDIANNESS || value == REVERSE_ENDIANNESS)
    {
        endianness = value;
    }
}
