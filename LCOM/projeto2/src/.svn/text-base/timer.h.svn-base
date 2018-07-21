#ifndef __TIMER_H
#define __TIMER_H


typedef struct
{
	int ticked;
	unsigned long counter;
} Timer;


void setTicked(Timer* timer, int flag);


Timer* createTimer();

void deleteTimer(Timer* timer);


int timer_subscribe_int(void );

/**
 * @brief Unsubscribes Timer 0 interrupts
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int timer_unsubscribe_int();

/**
 * @brief Timer 0 interrupt handler
 *
 * Increments counter
 */
void timerHandler(Timer* timer);


#endif /* __TIMER_H */
