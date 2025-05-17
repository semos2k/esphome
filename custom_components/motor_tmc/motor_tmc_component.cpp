#include "esphome/core/log.h"
#include "motor_tmc_component.h"

namespace esphome {
namespace motor_tmc_component {

static const char *TAG = "motor_tmc_component.component";

void MotorTmcComponent::setup() {

}

void MotorTmcComponent::loop() {

}

void MotorTmcComponent::dump_config(){
    ESP_LOGCONFIG(TAG, "Motor TMC component");
}

}  // namespace empty_uart_component
}  // namespace esphome