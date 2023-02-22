## Symptom
When mclBnG1 is instantiated as (or under) a static variable, it crashes during static initialization phase before the main function is called.

The symptoom can be reproduced in non-static context by calling a mcl c-api such as `mclBnG1_clear` before calling `blsInit`.

```gdb
(gdb) run
Starting program: /home/../repos/mcl-bls-sample/test
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
b
Program received signal SIGSEGV, Segmentation fault.
0x0000000000000000 in ?? ()
(gdb) bt
#0  0x0000000000000000 in ?? ()
#1  0x000055555555b42a in mcl::FpT<mcl::bn::local::FpTag, 384ul>::clear (
    this=0x55555561a1c0 <A::p>)
    at /home/../repos/mcl-bls-sample/src/bls/mcl/include/mcl/fp.hpp:254
#2  mcl::EcT<mcl::FpT<mcl::bn::local::FpTag, 384ul> >::clear (this=0x55555561a1c0 <A::p>)
    at /home/../repos/mcl-bls-sample/src/bls/mcl/include/mcl/ec.hpp:1305
#3  mclBnG1_clear (x=0x55555561a1c0 <A::p>)
    at /home/../repos/mcl-bls-sample/src/bls/mcl/include/mcl/impl/bn_c_impl.hpp:370
#4  0x0000555555558e4e in MclWrapper::MclWrapper (this=0x55555561a1c0 <A::p>)
    at src/mcl_wrapper.cpp:7
#5  0x0000555555558e15 in __static_initialization_and_destruction_0 (__initialize_p=1,
    __priority=65535) at src/main.cpp:7
#6  0x0000555555558e2f in _GLOBAL__sub_I__ZN1A1pE () at src/main.cpp:12
#7  0x000055555560339d in __libc_csu_init ()
#8  0x00007ffff7bbf010 in __libc_start_main (main=0x555555558dd9 <main()>, argc=1,
    argv=0x7fffffffdc08, init=0x555555603350 <__libc_csu_init>, fini=<optimized out>,
    rtld_fini=<optimized out>, stack_end=0x7fffffffdbf8) at ../csu/libc-start.c:264
#9  0x0000555555558d1e in _start ()
    at /home/../repos/mcl-bls-sample/src/bls/mcl/include/mcl/fp.hpp:244

```

## Environment
- x86_64
- g++
- Ubuntu 20.04
- gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04.1)

## How to reproduce the symptom
```sh
$ make
$ make run
```
