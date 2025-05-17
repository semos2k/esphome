#include "esphome/core/log.h"
#include "motor_tmc_component.h"

#define DELAY_MILISECONDS 400
#define MICRO_STEPS 16
#define MAX_STEPS 200 * MICRO_STEPS

namespace esphome {
namespace motor_tmc_component {

static const char *TAG = "motor_tmc_component.component";

void MotorTmcComponent::setup() {    
    ESP_LOGCONFIG(TAG, "Init Setup");
    //inMode(STOP_PIN, INPUT_PULLUP);
    pinMode(DIR_PIN, OUTPUT);
    pinMode(STEP_PIN, OUTPUT);
    pinMode(EN_PIN, OUTPUT);
    digitalWrite(EN_PIN, LOW);

    Serial1.begin(115200, SERIAL_8N1, UART_RX, UART_TX);
    driver_ = new TMC2208Stepper(&Serial1);
    driver_.begin();
    driver_.toff(5);
    driver_.rms_current(750); // Corriente RMS
    driver_.microsteps(MICRO_STEPS);
    driver_.en_spreadCycle(false);
    driver_.pwm_autoscale(true);
    
    // Inicializar FastAccelStepper
    stepper_engine.init();
    stepper = engine.stepperConnectToPin(STEP_PIN);
    if (stepper) {
        stepper->setDirectionPin(DIR_PIN);
        stepper->setEnablePin(EN_PIN);
        stepper->setAutoEnable(true);
        stepper->setSpeedInHz(4000);         // Velocidad máxima
        stepper->setAcceleration(1000);      // Aceleración
        ESP_LOGCONFIG(TAG, "Move motor");
        stepper->move(MAX_STEPS);                  // Mueve 200 pasos
    }
}

void MotorTmcComponent::loop() {

}

void MotorTmcComponent::dump_config(){
    ESP_LOGCONFIG(TAG, "Motor TMC component");
}

}  // namespace empty_uart_component
}  // namespace esphome