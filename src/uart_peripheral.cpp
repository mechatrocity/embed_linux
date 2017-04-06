#include "uart_peripheral.h"


uart_peripheral::uart_peripheral(char* device)
  : file_descriptor(0),
  data(), new_data(false), raw_data{'\0'}
{
  file_descriptor = open(device, O_RDWR|O_NOCTTY);
  if (file_descriptor < 0)
  {
    // check errno
    perror(device);
    exit(-1);
  }
}


uart_peripheral::~uart_peripheral()
{
  memset(raw_data, '\0', 512);
  int close_status = close(file_descriptor);
  if (0 != close_status)
  {
    // FIXME
  }
}


const std::string& uart_peripheral::read_canonical()
{
  memset(raw_data, '\0', 512);
  int res = read(file_descriptor,raw_data,512);
  data.assign(raw_data, res);

  return data;
}


const char* uart_peripheral::read_noncanonical(size_t length)
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
