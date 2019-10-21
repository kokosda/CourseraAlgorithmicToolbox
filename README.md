## To compile in C++:
    g++ -pipe -O2 -std=c++14 <filename> -lm
> If your C/C++ compiler does not recognize -std=c++14 flag, try replacing
it with -std=c++0x flag or compiling without this flag at all
26
(all starter solutions can be compiled without it). On Linux and MacOS,
you most probably have the required compiler. On Windows,
you may use your favorite compiler or install, e.g., cygwin.