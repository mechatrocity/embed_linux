#include "i2c_bus.h"

template<typename T>
class i2c_peripheral
{
public:
  i2c_peripheral(unsigned int address, i2c_bus& _bus);

  void send_data(T data);
  T& get_data();

private:
  uint8_t addr_;
  i2c_bus& bus_;
};
