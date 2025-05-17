#pragma once

#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"


#include <Arduino.h>
#include <TMCStepper.h>
#include <FastAccelStepper.h>

namespace esphome {
namespace motor_tmc_component {

class MotorTmcComponent : /*public uart::UARTDevice,*/ public Component {
  public:
    void setup() override;
    void loop() override;
    void dump_config() override;

  protected:
    HardwareSerial &serial_;
    TMC2208Stepper *driver_;
    FastAccelStepperEngine stepper_engine;
    FastAccelStepper *stepper = nullptr;

    const int STEP_PIN = 4;
    const int DIR_PIN = 2;
    const int EN_PIN = 15;
    const int UART_TX = 21;
    const int UART_RX = 20;
};


}  // namespace empty_uart_component
}  // namespace esphome