#include <stdio.h>
#include <stdbool.h>

#include "doorLock.h"
#include "doorLockSM.h"

void show_system_state(char);
void SystemInit(void);
void InitScreen(void);

int main(void)
{
	bool running = true;

	InitScreen();
	SystemInit();

	while (running) {
		char c;
		bool show_state;

		c = getchar();

		show_state = true;

		switch (c) {
      case '.':
      case ' ':
			/* simulate passing of time and run state machine */
			timeTick();
			sm_execute(&smDoorLock);
      //show_system_state(c);
			break;

			/* Interactions with system */
			/* Pressing the button, opening and closing door */

			/* Press and release pushbutton */
		case '+':
			ButtonState = PB_Pressed;
			break;

		case '-':
			ButtonState = PB_Released;
			break;

			/* Open and close door */
		case 'o':
			DoorState = DoorOpened;
			break;

		case 'c':
			DoorState = DoorClosed;
			break;

			/* Miscelanous user interface */

			/* Help */
		case '?':
		case 'h':
			InitScreen();
			break;

			/* Leave */
		case 'x':
    case EOF:
			running = false;
			break;

			/* Avoid displaying status line for all keys that are not relevant */
		default:
			show_state = false;
			break;
		}


		if (show_state && running) {
			show_system_state(c);
		}

	}
	return 0;
}

/**
 * \brief Shows current system state
 */
void show_system_state(char c)
{
  static uint16_t last_time;

  putchar(c);
  putchar('\t');

  printf("%3d", get_current_time());
  if(last_time == get_current_time()){
    putchar('*');
  }
  last_time = get_current_time();
  putchar('\t');

	if (ButtonState == PB_Pressed) {
		printf("+\t");
	} else {
		printf("-\t");
	}

	if (DoorLockState == DoorLocked) {
		printf("Lck\t");
	} else {
		printf("Unl\t");
	}

	if (DoorState == DoorOpened) {
		printf("Open\n");
	} else {
		printf("Closed\n");
	}
}

/*
 * \brief System initialization.
 *
 */
void SystemInit(void)
{
  DoorLockState = DoorUnlocked;
  DoorState = DoorClosed;
  ButtonState = PB_Released;
  sm_init(&smDoorLock);         /* Note that the state machine initial state
                                   must be coherent with the definitions in
                                   the lines before! */
}

/*
 * \brief Initial screen with help for the user.
 *
 */
void InitScreen(void)
{
	printf("Interaction:\n\n");
	printf("Push Button: '+' to press, '-' to release.\n");
	printf("Door: 'o' to open, 'c' to close.\n");
	printf("Space or '.' to execute the state machine and show system state.\n");
	printf("x to leave.\n");
  printf("(In the terminal, requires Enter to read the input.)\n");
	printf
	    ("----------------------------------------------------------------\n");
	printf("\tTime\tPB\tLock\tDoor\n");
	printf
	    ("----------------------------------------------------------------\n");
}
