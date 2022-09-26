#ifndef PANIC_H
#define PANIC_H

void panic_helper(const char *func, const char *file, const int line, const char * format, ...)
{
    fprintf(stderr, "Panic -\n");
    fprintf(stderr, "File: %s\n", file);
    fprintf(stderr, "Line: %i\n", line);
    fprintf(stderr, "Func: %s\n", func);
    fprintf(stderr, "Message: \"");
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    fprintf(stderr, "\"\n");
    exit(EXIT_FAILURE);
}

#define panic(...)  panic_helper(__func__, __FILE__, __LINE__, __VA_ARGS__)

#endif /* end of include guard: PANIC_H */
