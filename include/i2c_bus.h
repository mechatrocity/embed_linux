#include <vector>

class i2c_bus
{
public:
  explicit i2cbus(unsigned int bus_identifier, unsigned int frequency);
  ~i2cbus();

  template<typename T>
  T get_data(unsigned int address);

  template<typename T>
  explicit void push_data(T data);

private:
  unsigned int bus_id;  // 'n' for I2Cn
  unsigned int freq;    // Hz

  int file_descriptor;  // linux file handle
}
