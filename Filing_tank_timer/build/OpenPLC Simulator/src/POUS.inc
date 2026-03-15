#include "POUS.h"
#include "Config0.h"

static inline INT __MAIN_TIME_TO_INT1(BOOL EN,
  TIME IN,
  MAIN *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_TIME_TO_INT8073191_ENO,);
  __res = TIME_TO_INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_TIME_TO_INT8073191_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __MAIN_TIME_TO_INT2(BOOL EN,
  TIME IN,
  MAIN *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_TIME_TO_INT6710441_ENO,);
  __res = TIME_TO_INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_TIME_TO_INT6710441_ENO,,__TMP_ENO);
  return __res;
}

void MAIN_init__(MAIN *data__, BOOL retain) {
  TOF_init__(&data__->TOF0,retain);
  TOF_init__(&data__->TOF1,retain);
  __INIT_VAR(data__->FILL_TIME_TO_COUNT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DISCHARGE_TIME_TO_COUNT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->ONLY_DIS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ONLY_FILL,__BOOL_LITERAL(FALSE),retain)
  __INIT_LOCATED(BOOL,__IX100_0,data__->DISCHARGE,retain)
  __INIT_LOCATED_VALUE(data__->DISCHARGE,1)
  __INIT_LOCATED(BOOL,__IX100_1,data__->I_FILL,retain)
  __INIT_LOCATED_VALUE(data__->I_FILL,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX100_0,data__->DISCHARGE_VALVE,retain)
  __INIT_LOCATED_VALUE(data__->DISCHARGE_VALVE,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX100_1,data__->DISCHARGING,retain)
  __INIT_LOCATED_VALUE(data__->DISCHARGING,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX100_2,data__->FILL_VALVE,retain)
  __INIT_LOCATED_VALUE(data__->FILL_VALVE,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX100_3,data__->FILLING,retain)
  __INIT_LOCATED_VALUE(data__->FILLING,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(INT,__QW100,data__->TIMER,retain)
  __INIT_LOCATED_VALUE(data__->TIMER,0)
  __INIT_VAR(data__->_TMP_TIME_TO_INT8073191_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_TIME_TO_INT8073191_OUT,0,retain)
  __INIT_VAR(data__->_TMP_TIME_TO_INT6710441_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_TIME_TO_INT6710441_OUT,0,retain)
}

// Code part
void MAIN_body__(MAIN *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->TOF0.,IN,,__GET_LOCATED(data__->I_FILL,));
  __SET_VAR(data__->TOF0.,PT,,__time_to_timespec(1, 0, 8, 0, 0, 0));
  TOF_body__(&data__->TOF0);
  __SET_LOCATED(data__->,FILL_VALVE,,__GET_VAR(data__->TOF0.Q,));
  __SET_VAR(data__->,FILL_TIME_TO_COUNT,,__GET_VAR(data__->TOF0.ET,));
  __SET_LOCATED(data__->,FILLING,,__GET_VAR(data__->TOF0.Q,));
  __SET_VAR(data__->,ONLY_DIS,,__GET_VAR(data__->TOF0.Q,));
  __SET_VAR(data__->TOF1.,IN,,!(__GET_LOCATED(data__->DISCHARGE,)));
  __SET_VAR(data__->TOF1.,PT,,__time_to_timespec(1, 0, 8, 0, 0, 0));
  TOF_body__(&data__->TOF1);
  __SET_LOCATED(data__->,DISCHARGE_VALVE,,__GET_VAR(data__->TOF1.Q,));
  __SET_VAR(data__->,DISCHARGE_TIME_TO_COUNT,,__GET_VAR(data__->TOF1.ET,));
  __SET_LOCATED(data__->,DISCHARGING,,__GET_VAR(data__->TOF1.Q,));
  __SET_VAR(data__->,ONLY_FILL,,__GET_VAR(data__->TOF1.Q,));
  __SET_VAR(data__->,_TMP_TIME_TO_INT8073191_OUT,,__MAIN_TIME_TO_INT1(
    (BOOL)!(__GET_VAR(data__->ONLY_FILL,)),
    (TIME)__GET_VAR(data__->FILL_TIME_TO_COUNT,),
    data__));
  if (__GET_VAR(data__->_TMP_TIME_TO_INT8073191_ENO,)) {
    __SET_LOCATED(data__->,TIMER,,__GET_VAR(data__->_TMP_TIME_TO_INT8073191_OUT,));
  };
  __SET_VAR(data__->,_TMP_TIME_TO_INT6710441_OUT,,__MAIN_TIME_TO_INT2(
    (BOOL)!(__GET_VAR(data__->ONLY_DIS,)),
    (TIME)__GET_VAR(data__->DISCHARGE_TIME_TO_COUNT,),
    data__));
  if (__GET_VAR(data__->_TMP_TIME_TO_INT6710441_ENO,)) {
    __SET_LOCATED(data__->,TIMER,,__GET_VAR(data__->_TMP_TIME_TO_INT6710441_OUT,));
  };

  goto __end;

__end:
  return;
} // MAIN_body__() 





