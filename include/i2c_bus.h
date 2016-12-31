#include <vector>

class i2c_bus
{
public:
  // Bus control
  explicit i2cbus(unsigned int i2c_bus_num = UINT_MAX,
                  unsigned int frequency = 0);
  ~i2cbus();
  const unsigned int& get_bus_id();
  const unsigned int& get_freq();
  // Bus I/O
  template<typename T>
  T get_data(unsigned int address);

private:
  template<typename T>
  explicit void push_data(T data);
  
  unsigned int bus_num_;  // 'n' for I2Cn
  unsigned int freq_;    // Hz
  volatile int file_descriptor_;  // linux file handle
  // FIXME: add linux struct(s)
};
