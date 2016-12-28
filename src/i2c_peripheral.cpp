#include "i2c_peripheral.h"


i2c_peripheral::i2c_peripheral(unsigned int address)
  : addr(address), data()
{}

void i2c_peripheral::update()
{

}

T& i2c_peripheral::get_data()
{
  return data;
}
