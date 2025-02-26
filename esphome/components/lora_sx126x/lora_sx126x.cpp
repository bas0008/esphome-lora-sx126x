#include "lora_sx126x.h"
#include "esphome/core/log.h"

namespace esphome {
namespace lora_sx126x {

static const char *TAG = "lora_sx126x";

void LoraSX126X::setup() {
  ESP_LOGD(TAG, "Initializing SX126x...");
  lora_.begin(pin_lora_nss_, pin_lora_reset_, pin_lora_busy_, pin_lora_dio_1_);
  lora_.setFrequency(rf_frequency_);
  lora_.setTxPower(tx_output_power_);
  lora_.setBandwidth(lora_bandwidth_);
  lora_.setSpreadingFactor(lora_spreading_factor_);
  lora_.setCodingRate(lora_codingrate_);
  lora_.setPreambleLength(lora_preamble_length_);
  lora_.setRxMode();
}

void LoraSX126X::loop() {}

void LoraSX126X::dump_config() {
  ESP_LOGCONFIG(TAG, "SX126x Config:");
  ESP_LOGCONFIG(TAG, "  NSS Pin: %d", pin_lora_nss_);
  ESP_LOGCONFIG(TAG, "  Reset Pin: %d", pin_lora_reset_);
  ESP_LOGCONFIG(TAG, "  DIO1 Pin: %d", pin_lora_dio_1_);
  ESP_LOGCONFIG(TAG, "  Busy Pin: %d", pin_lora_busy_);
  ESP_LOGCONFIG(TAG, "  Frequency: %u Hz", rf_frequency_);
  ESP_LOGCONFIG(TAG, "  TX Power: %d dBm", tx_output_power_);
  ESP_LOGCONFIG(TAG, "  Bandwidth: %.1f kHz", lora_bandwidth_);
  ESP_LOGCONFIG(TAG, "  Spreading Factor: %u", lora_spreading_factor_);
  ESP_LOGCONFIG(TAG, "  Coding Rate: %u", lora_codingrate_);
  ESP_LOGCONFIG(TAG, "  Preamble Length: %u", lora_preamble_length_);
}

float LoraSX126X::get_rssi() {
  return lora_.getRssiInst();
}

std::string LoraSX126X::receive_packet() {
  uint8_t buffer[255];
  int16_t packet_size = lora_.receive(buffer, sizeof(buffer));
  if (packet_size > 0) {
    return std::string((char*)buffer, packet_size);
  }
  return "";
}

}  // namespace lora_sx126x
}  // namespace esphome
