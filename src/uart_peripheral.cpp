#include "uart_peripheral.h"


uart_peripheral::uart_peripheral(char* device)
  : file_descriptor(0), data(), raw_data{'\0'}, new_data(false)
{
  file_descriptor = open(device, O_RDWR | O_NOCTTY );
  if (file_descriptor < 0)
  {
    perror(device);
    exit(-1);
  }
}

const std::string& uart_peripheral::read_canonical()
{
  memset(raw_data, '\0', 512);
  int res = read(file_descriptor,raw_data,512);
  data.assign(raw_data, res);

  return data;
}

char* uart_peripheral::read_noncanonical(size_t length)
{
  memset(raw_data, '\0', 512);
  int res = read(file_descriptor,raw_data,length);
  if (res != length)
  {
    // FIXME
  }

  return raw_data;
}

void uart_peripheral::async_callback()
{
  
}
