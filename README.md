# get_next_line

get_next_line is a Hive project that focuses on reading text from a file descriptor line by line. This project is a key exercise in understanding file I/O in C, memory management, and handling buffer logic efficiently.

## 🚀 Project Overview

The goal of get_next_line is to implement a function that reads a line from a file each time it is called, maintaining internal state between calls. The function must work efficiently with different file descriptors and varying buffer sizes.

This project reinforces:

- File descriptor handling
- Efficient use of static variables
- Dynamic memory allocation and management
- Working with buffers and newline delimiters

## 📁 Project Structure

### ✅ Mandatory Part

- Implement `get_next_line(int fd)` which returns the next line read from the given file descriptor.
- Ensure the function handles reading line-by-line until EOF.
- Manage memory properly to avoid leaks or overflows.

### 🧩 Bonus Part

- Extend the project to allow simultaneous reading from **multiple file descriptors** without interfering with each other's state.
- The function must still behave consistently and return one line per call per descriptor.

## 📦 Buffer Management

- The reading is done in chunks of `BUFFER_SIZE`, which can be defined at compile time.
- The function handles partial reads and keeps track of leftover content between calls using a static variable.

## 🔧 Compilation & Usage

The project includes a `Makefile` for building the library and testing.

## 🧠 What I Learned

- Efficiently managing state across function calls using static variables
- Handling multiple file descriptors independently
- Reading data with system calls (read) and dynamically allocating memory
- Implementing a line parser and buffer join/split logic manually
- Avoiding memory leaks and segmentation faults in lower-level C code
