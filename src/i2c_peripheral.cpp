#include "i2c_peripheral.h"


i2c_peripheral::i2c_peripheral(unsigned int address, i2c_bus& bus)
  : addr_(address), bus_(bus)
{
  // TODO: device setup?? initial ping??
}

void i2c_peripheral::send_data(uint16_t data)
{
  // Sanity check: can only send 9-bytes of data, because address
  // takes up highest 7-bits of payload
  if (data != (0x1FF & data))
  {
    // TODO
  }
  else
  {
    try
    {
      bus_.push_data(data);
    }
    catch (...)
    {
      // TODO
    }
  }
}

T i2c_peripheral::get_data()
{
  T data;
  try
  {
    data = bus_.get_data(addr_);
  }
  catch
  {
    // TODO
  }
  return data;
}
