#include "i2c_bus.h"

template<typename T>
class i2c_peripheral
{
public:
  i2c_peripheral(unsigned int address);

  void update();
  T& get_data();

private:
  unsigned int addr;
  T data;
}
