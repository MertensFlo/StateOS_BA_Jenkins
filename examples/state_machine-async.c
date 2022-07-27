#include <stm32f4_discovery.h>
#include <os.h>

enum
{
	EventALL    = hsmALL,
	EventStop   = hsmStop,
	EventExit   = hsmExit,
	EventEntry  = hsmEntry,
	EventInit   = hsmInit,
	EventSwitch = hsmUser,
	EventTick,
};

OS_HSM(blinker, 1);
OS_TSK(dispatcher, 0, NULL);

OS_HSM_STATE(StateOff, NULL);
OS_HSM_STATE(StateOn,  NULL);

void StateOffHandler(hsm_t *hsm, unsigned event)
{
	(void) hsm;

	switch (event)
	{
	case EventInit:
		LEDs = 0;
		break;
	default:
		assert(false); // system shouldn't get here
	}
}

void StateOnHandler(hsm_t *hsm, unsigned event)
{
	(void) hsm;

	switch (event)
	{
	case EventTick:
		LED_Tick();
		break;
	default:
		assert(false); // system shouldn't get here
	}
}

hsm_action_t tab[] =
{
	_HSM_ACTION_INIT(StateOff, EventInit,   NULL,     StateOffHandler),
	_HSM_ACTION_INIT(StateOff, EventSwitch, StateOn,  NULL),
	_HSM_ACTION_INIT(StateOn,  EventSwitch, StateOff, NULL),
	_HSM_ACTION_INIT(StateOn,  EventTick,   NULL,     StateOnHandler),
};
#define tabsize (int)(sizeof(tab)/sizeof(tab[0]))

int main()
{
	LED_Init();

	for (int i = 0; i < tabsize; i++) hsm_link(blinker, &tab[i]);

	hsm_startAsync(blinker, dispatcher, StateOff);
	hsm_sendAsync(blinker, EventSwitch);
	for (;;)
	{
		tsk_delay(SEC);
		hsm_sendAsync(blinker, EventTick);
	}
}
