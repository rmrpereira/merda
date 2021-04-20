#include "doorLock.h"

/* System state variables */
lock_state_t DoorLockState;
button_state_t ButtonState;
door_state_t DoorState;

uint16_t timeElapsed;

void set_door_lock(lock_state_t command)
{
	DoorLockState = command;
	return;
}

lock_state_t get_door_lock(void)
{
	return DoorLockState;
}

door_state_t get_door_state(void)
{
	return DoorState;
}

button_state_t read_push_button(void)
{
	return ButtonState;
}

void timeTick(void)
{
	timeElapsed++;
	return;
}

uint16_t get_current_time(void)
{
	return timeElapsed;
}
