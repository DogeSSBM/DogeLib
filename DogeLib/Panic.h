#ifndef PANIC_H
#define PANIC_H

void panic( const char * format, ... )
{
  va_list args;
  va_start (args, format);
  vprintf (format, args);
  va_end (args);
  exit(EXIT_FAILURE);
}

#endif /* end of include guard: PANIC_H */
