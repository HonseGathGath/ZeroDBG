# ZeroDBG

## Overview

A minimal ptrace-based debugger for Linux. Forks a child process, attaches via `PTRACE_TRACEME`, pauses execution at the process entry point, and reports the target's stopped state. Designed as a minimal foundation for building a more capable debugger with breakpoints, single-stepping, and register inspection.

## Prerequisites

- GCC (or any C99-compatible compiler)
- Linux (ptrace is Linux-specific)
- Root or appropriate `CAP_SYS_PTRACE` capability (may be required depending on kernel settings)

## Installation & Setup

```bash
git clone <repo-url>
cd ZeroDBG
make
```

## Usage

```bash
./bin/debugger ./bin/target
```

Output:
```
file is : ./bin/target
Debugger: Target is loaded and paused at the entry point!
```

The debugger attaches to the target binary, pauses it at the entry point, and exits. This is a minimal proof-of-concept — breakpoints, single-stepping, register inspection, and memory manipulation are not yet implemented.

### Building the Test Target

The test target (`bin/target`) is built automatically by `make` from `target.c`. It prints several messages and exits normally.

```bash
# Build standalone
gcc -g target.c -o bin/target
```

## Project Structure

```
ZeroDBG/
  Makefile     — Build targets (debugger, target, clean)
  main.c       — ptrace debugger implementation (41 lines)
  target.c     — Test binary for debugging
  bin/         — Build output directory
```

## Contributing

Contributions, bug reports, and feature requests are welcome.

## License

Open-source software. Available under the MIT License.
