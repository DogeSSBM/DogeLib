#ifndef PANIC_H
#define PANIC_H

void panicHelper(const int line, const char * format, ... )
{
    fprintf(stderr, "Line %i: ", line);
    va_list args;
    va_start (args, format);
    vprintf (format, args);
    va_end (args);
    exit(EXIT_FAILURE);
}

#define panic(...)      panicHelper(__LINE__, __VA_ARGS__)

#endif /* end of include guard: PANIC_H */
