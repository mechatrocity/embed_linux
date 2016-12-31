#include "i2c_bus.h"

#include <limits.h> // UINT_MAX
#include <linux/i2c-dev.h>


i2c_bus::i2c_bus(unsigned int i2c_bus_num, unsigned int frequency)
    : bus_num_(i2c_bus_num), freq_(frequency), file_descriptor_(0)
{
  char device_name[16] = {'\0'};
  sprintf(filename, "/dev/i2c-%d", bus_num_);
  if ( (file_descriptor_ = open(device_name,O_RDWR)) < 0)
  {
    // FIXME: a throw-type situation?
    perror("Failed to open i2c bus #%d, return code %d",
           bus_num_, file_descriptor_);
    exit(1);
  }
}

i2c_bus::~i2c_bus()
{
  if (file_descriptor_ <=  0)
  {
    // TODO: Shouldn't have ever gotten here...
    perror("Attempting to close dead i2c bus #%d!", bus_num_);
    exit(1);
  }
  else if (close(file_descriptor_) < 0)
  {
    // TODO
    perror("Failed to close i2c bus #%d", bus_num_);
    exit(1);
  }
}

const unsigned int& i2c_bus::get_bus_id()
{
  return bus_id_;
}

const unsigned int& i2c_bus::get_freq()
{
  return freq_;
}

/// Bus I/O
template<typename T>
T i2c_bus::get_data(unsigned int address)
{
  T buf = 0x0;
  if (read(file_descriptor_, buf, sizeof(T)) != sizeof(T))
  {
    // FIXME: throw-type situation
  }
  return buf;
}

template<typename T>
void i2c_bus::push_data(T data)
{
  if (write(file_descriptor_, data, sizeof(data)) != sizeof(data))
  {
    //FIXME: ERROR HANDLING: i2c transaction failed
  }
}
