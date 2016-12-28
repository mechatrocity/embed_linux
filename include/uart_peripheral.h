//FIXME: linux uart lib
#include <string>

class uart_peripheral
{
public:
  uart_peripheral(char* device);
  ~uart_peripheral();

  bool new_data();

  explicit void write(std::string);
  explicit void write(char* data, size_t length);
  const std::string& read_canonical();
  char* read_noncanonical(size_t length);

private:
  int file_descriptor;

  std::string data;
  char raw_data[512];
  bool new_data;
}
