This is a simple practice for RPC in Windows OS.
This project has three section:
- interface: include `.idl` and `.acf` file
- Client
- Server

1. Using MIDL Compiler generate corresponding `xxx_h.h` , `xxx_c.c` and `xxx_s.c` file
   according to `.idl` and `.acf` file.
2. `xxx_c.c` is used for Client Program.
3. `xxx_s.c` is used for Server Program.
