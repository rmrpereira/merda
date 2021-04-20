/**
 * \file: doorLock.h
 *
 * \brief Simulation of the door lock system.
 *
 *
 */
#pragma once

#include <stdint.h>

/******************************************************************
*
* Data types definitions
*
******************************************************************/

/**
* Push button states (pressed, released)
*
*/
typedef enum {
	PB_Pressed,   /**< Push button is pressed */
	PB_Released   /**< Push button is released */
} button_state_t;

/**
 * Door lock states (locked/unlocked)
 */
typedef enum {
	DoorLocked, /**< Door is locked */
	DoorUnlocked/**< Door is unlocked */
} lock_state_t;

/**
 * Door states (opened/closed)
 */
typedef enum {
	DoorOpened,    /**< Door is open */
	DoorClosed     /**< Door is closed */
} door_state_t;

/**********************************************************************
*
* Functions to interact with the physical system.
*
**********************************************************************/

/**
* \brief Actuate the door lock, locking and unlocking the door.
*
* \param command Door lock command.
*
*/
void set_door_lock(lock_state_t command);

/**
 * \brief Get current door state
 *
 */
door_state_t get_door_state(void);

/**
 * \brief Get current door lock state
 *
 */
lock_state_t get_door_lock_state(void);

/**
 * \brief Read the pushbutton state
 */
button_state_t read_push_button(void);

/**
 * \brief Increment time by a tick
 */
void timeTick(void);

/**
* \brief Get current time
*/
uint16_t get_current_time(void);

/* System state variables */
extern lock_state_t DoorLockState;
extern button_state_t ButtonState;
extern door_state_t DoorState;
