#include "doorLockSM.h"


/* Create the machine state data */
sm_t smDoorLock;


/*
* State Machine execution
*/
void sm_execute(sm_t *stateMachinep)
{
}

void sm_init(sm_t *stateMachinep)
{
  /* The following is a crude way of setting the initial state
     to the first state in the enum */
  stateMachinep->initial_state = (doorLockState_t) 0;
  stateMachinep->current_state = stateMachinep->initial_state;
}
