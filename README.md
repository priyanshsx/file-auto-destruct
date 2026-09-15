# Text File Detonator 

A medium-level C project that explores time management and system-level file deletion by creating a text file and automatically destroying it after a 15-second countdown.

## Requirements
*   **Compiler:** GCC or Clang.
*   **Operating System:** Linux, macOS, or Windows Subsystem for Linux (WSL). 
> **Note:** The `<unistd.h>` library required for the `sleep()` function is a POSIX standard. If you attempt to compile this on a raw Windows command prompt without WSL or MinGW, it will throw an error.

## Overview
This project acts as the first foundational bridge toward building an ephemeral "Secret Messenger." It demonstrates how to capture Unix timestamps, create a live-updating terminal clock, and programmatically erase files from the hard drive without user intervention.

## Core Concepts
*   **Time Management:** Using `<time.h>` and `time_t` to capture raw Unix Epoch timestamps, and calculating elapsed time using `difftime()`.
*   **Terminal Formatting:** Utilizing the carriage return (`\r`) and fixed-width formatting (`%2d`) to create a single-line, live-updating digital clock that overwrites "ghost digits."
*   **System Integration:** Managing CPU usage with `sleep()` and permanently destroying file data using the `remove()` function.

## Compilation & Usage

**1. Compile the code:**
```bash
gcc time_bomb.c -o time_bomb
