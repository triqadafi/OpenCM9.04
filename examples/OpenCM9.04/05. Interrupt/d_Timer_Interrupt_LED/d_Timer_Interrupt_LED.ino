/* Timer_Interrupt_LED

               Compatibility
 CM900                  O
 OpenCM9.04             O
 
 created 16 Nov 2012
 by ROBOTIS.LTD
 */

#define LED_RATE 100000    // in microseconds; should give 0.5Hz toggles

HardwareTimer Timer(1);

void setup() {
  // Set up the LED to blink
  pinMode(BOARD_LED_PIN, OUTPUT);

  // Pause the timer while we're configuring it
  Timer.pause();

  // Set up period
  Timer.setPeriod(LED_RATE); // in microseconds

  // Set up an interrupt on channel 1
  Timer.setMode(TIMER_CH1, TIMER_OUTPUT_COMPARE);
  Timer.setCompare(TIMER_CH1, 1);  // Interrupt 1 count after each update
  Timer.attachInterrupt(TIMER_CH1, handler_led);

  // Refresh the timer's count, prescale, and overflow
  Timer.refresh();

  // Start the timer counting
  Timer.resume();
}

void loop() {
  // Nothing! It's all in the handler_led() interrupt:
}

void handler_led(void) {
  toggleLED();
}

