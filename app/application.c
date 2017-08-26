#include <application.h>

bc_led_t led;
bc_button_t button;

static void radio_event_handler(bc_radio_event_t event, void *event_param);

void button_event_handler(bc_button_t *self, bc_button_event_t event, void *event_param);

void application_init(void)
{
    bc_led_init(&led, BC_GPIO_LED, false, false);

    bc_radio_init();
    bc_radio_set_event_handler(radio_event_handler, NULL);

    static bc_button_t button;
    bc_button_init(&button, BC_GPIO_BUTTON, BC_GPIO_PULL_DOWN, false);
    bc_button_set_event_handler(&button, button_event_handler, NULL);

}

void application_task(void)
{
    static uint16_t event_count = 0;

    // Simulate button press every second
    bc_radio_pub_push_button(&event_count);

    event_count++;

    bc_scheduler_plan_current_relative(500);
}


void button_event_handler(bc_button_t *self, bc_button_event_t event, void *event_param)
{
    (void) self;
    (void) event_param;

    if (event == BC_BUTTON_EVENT_PRESS)
    {
        bc_led_pulse(&led, 100);

        static uint16_t event_count = 0;

        bc_radio_pub_push_button(&event_count);

        event_count++;
    }
    else if (event == BC_BUTTON_EVENT_HOLD)
    {
        bc_radio_enroll_to_gateway();

        bc_led_set_mode(&led, BC_LED_MODE_OFF);

        bc_led_pulse(&led, 1000);
    }
}


static void radio_event_handler(bc_radio_event_t event, void *event_param)
{
    (void) event_param;

    bc_led_set_mode(&led, BC_LED_MODE_OFF);

    if (event == BC_RADIO_EVENT_ATTACH)
    {
        bc_led_pulse(&led, 1000);
    }
    else if (event == BC_RADIO_EVENT_DETACH)
    {
        bc_led_pulse(&led, 1000);
    }
    else if (event == BC_RADIO_EVENT_INIT_DONE)
    {
        //my_device_address = bc_radio_get_device_address();
    }
}

