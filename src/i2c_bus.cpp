#include "i2c_bus.h"
#include <linux/i2c-dev.h>


i2c_bus::i2c_bus(unsigned int bus_identifier, unsigned int frequency)
    : bus_id(bus_identifier), freq(frequency), dev_handle(0)
{
  char device_name[16] = {'\0'};
  sprintf(filename, "/dev/i2c-%d", bus_identifier);

  if ((dev_handle = open(device_name,O_RDWR)) < 0)
  {
    exit(1);
  }
}

i2c_bus::~i2c_bus()
{
  // TODO: anything to 'release' the bus?
}

template<typename T>
T i2c_bus::get_data(unsigned int address)
{
  try
  {

  }
  catch(...)
  {

  }
}

template<typename T>
void i2c_bus::push_data(T data)
{
  try
  {

  }
  catch(...)
  {

  }
}
