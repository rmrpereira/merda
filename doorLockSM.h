/**
 * \file: doorLockSM.h
 *
 */
#pragma once

#include <stdint.h>



/* Door Lock State Machine states */
/* Fill in with the appropriate states */
typedef enum { State1, State2 } doorLockState_t;

/* Data structure for the state machine */
typedef struct {
	doorLockState_t current_state;
	doorLockState_t initial_state;
} sm_t;

/* State machine data structure */
extern sm_t smDoorLock;


/*
 * State machine execution
 */
void sm_execute(sm_t *SMp);

/*
 * Set initial state
 */
void sm_init(sm_t *SMp);
