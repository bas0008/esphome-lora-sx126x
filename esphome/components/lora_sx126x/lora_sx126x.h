#ifndef LORA_SX126X_H
#define LORA_SX126X_H

#include "esphome/core/component.h"
#include <SX126x-Arduino.h>  // Utiliser <> au lieu de "" pour les bibliothèques PlatformIO

namespace esphome {
namespace lora_sx126x {

class LoraSX126X : public Component {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;

  float get_rssi();
  std::string receive_packet();

  void set_pin_lora_nss(int pin) { pin_lora_nss_ = pin; }
  void set_pin_lora_reset(int pin) { pin_lora_reset_ = pin; }
  void set_pin_lora_dio_1(int pin) { pin_lora_dio_1_ = pin; }
  void set_pin_lora_busy(int pin) { pin_lora_busy_ = pin; }
  void set_rf_frequency(uint32_t freq) { rf_frequency_ = freq; }
  void set_tx_output_power(int8_t power) { tx_output_power_ = power; }
  void set_lora_bandwidth(float bw) { lora_bandwidth_ = bw; }
  void set_lora_spreading_factor(uint8_t sf) { lora_spreading_factor_ = sf; }
  void set_lora_codingrate(uint8_t cr) { lora_codingrate_ = cr; }
  void set_lora_preamble_length(uint16_t pl) { lora_preamble_length_ = pl; }

 protected:
  ::SX126x lora_;  // Ajouter :: pour indiquer l’espace de noms global
  int pin_lora_nss_;
  int pin_lora_reset_;
  int pin_lora_dio_1_;
  int pin_lora_busy_;
  uint32_t rf_frequency_;
  int8_t tx_output_power_;
  float lora_bandwidth_;
  uint8_t lora_spreading_factor_;
  uint8_t lora_codingrate_;
  uint16_t lora_preamble_length_;
};

}  // namespace lora_sx126x
}  // namespace esphome

#endif
