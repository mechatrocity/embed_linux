//FIXME: linux uart lib
#include <string>

class uart_peripheral
{
public:
  explicit uart_peripheral(char* device);  // TODO: include baud
  virtual ~uart_peripheral();

  void write(std::string);
  void write(char* data, size_t length);

  const std::string& read_canonical();
  const char* read_noncanonical(size_t length);

private:
  void async_callback();

  int file_descriptor;
  std::string data;  // TODO: no strings on an embedded platform!
  bool new_data;
  char raw_data[512];
};
