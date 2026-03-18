#include "POUS.h"
#include "Config0.h"

void MAIN_init__(MAIN *data__, BOOL retain) {
  __INIT_VAR(data__->DELAY,__time_to_timespec(1, 500, 0, 0, 0, 0),retain)
  TON_init__(&data__->TON0,retain);
  TOF_init__(&data__->TOF0,retain);
  TOF_init__(&data__->TOF1,retain);
  TON_init__(&data__->TON3,retain);
  TON_init__(&data__->TOF2,retain);
  __INIT_LOCATED(BOOL,__IX100_0,data__->LID_AT_PLACE,retain)
  __INIT_LOCATED_VALUE(data__->LID_AT_PLACE,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX100_1,data__->LID_CLAMPED,retain)
  __INIT_LOCATED_VALUE(data__->LID_CLAMPED,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX100_2,data__->BASE_AT_PLACE,retain)
  __INIT_LOCATED_VALUE(data__->BASE_AT_PLACE,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX100_3,data__->BASE_CLAMPED,retain)
  __INIT_LOCATED_VALUE(data__->BASE_CLAMPED,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX100_4,data__->MOVING_X,retain)
  __INIT_LOCATED_VALUE(data__->MOVING_X,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX100_5,data__->MOVING_Z,retain)
  __INIT_LOCATED_VALUE(data__->MOVING_Z,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX100_6,data__->ITEM_DETECTED,retain)
  __INIT_LOCATED_VALUE(data__->ITEM_DETECTED,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX100_7,data__->PART_LEAVING,retain)
  __INIT_LOCATED_VALUE(data__->PART_LEAVING,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX100_0,data__->LIDS_CONVEYOR,retain)
  __INIT_LOCATED_VALUE(data__->LIDS_CONVEYOR,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX100_1,data__->CLAMP_LID,retain)
  __INIT_LOCATED_VALUE(data__->CLAMP_LID,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX100_2,data__->POS_RAISE_LID,retain)
  __INIT_LOCATED_VALUE(data__->POS_RAISE_LID,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX100_3,data__->BASE_CONVEYOR,retain)
  __INIT_LOCATED_VALUE(data__->BASE_CONVEYOR,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX100_4,data__->CLAMP_BASE,retain)
  __INIT_LOCATED_VALUE(data__->CLAMP_BASE,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX100_5,data__->MOVE_X,retain)
  __INIT_LOCATED_VALUE(data__->MOVE_X,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX100_6,data__->MOVE_Z,retain)
  __INIT_LOCATED_VALUE(data__->MOVE_Z,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX100_7,data__->GRAB,retain)
  __INIT_LOCATED_VALUE(data__->GRAB,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX101_0,data__->START,retain)
  __INIT_LOCATED_VALUE(data__->START,__BOOL_LITERAL(FALSE))
}

// Code part
void MAIN_body__(MAIN *data__) {
  // Initialise TEMP variables

  if (__GET_LOCATED(data__->START,)) {
    __SET_LOCATED(data__->,LIDS_CONVEYOR,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_LOCATED(data__->START,)) {
    __SET_LOCATED(data__->,CLAMP_LID,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->TON3.,IN,,(__GET_LOCATED(data__->LID_AT_PLACE,) || __GET_LOCATED(data__->LID_CLAMPED,)));
  __SET_VAR(data__->TON3.,PT,,__GET_VAR(data__->DELAY,));
  TON_body__(&data__->TON3);
  if (__GET_VAR(data__->TON3.Q,)) {
    __SET_LOCATED(data__->,LIDS_CONVEYOR,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->TOF2.,IN,,__GET_LOCATED(data__->LID_AT_PLACE,));
  __SET_VAR(data__->TOF2.,PT,,__GET_VAR(data__->DELAY,));
  TON_body__(&data__->TOF2);
  if (__GET_VAR(data__->TOF2.Q,)) {
    __SET_LOCATED(data__->,CLAMP_LID,,__BOOL_LITERAL(TRUE));
  };

  goto __end;

__end:
  return;
} // MAIN_body__() 





