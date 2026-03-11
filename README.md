# NetUtil-V1 / C++ Network Utility

This is a console-based network utility I built for my Introduction to C++ final project. It's a lightweight menu app that lets you run basic network commands like `ping` and `nslookup` directly from the terminal. 

The main focus of this project was building a custom, highly strict IPv4 validation function from scratch without relying on external networking libraries.

## Features
* **Custom IPv4 Validation:** Parses user input to ensure it perfectly matches the `x.x.x.x` format, checks that all octets are within the 0-255 range, and blocks random letters/symbols to prevent command injection.
* **IP Lookup:** Runs an `nslookup` on a validated target.
* **Custom Pings:** Lets you ping a target and specify exactly how many packets you want to send.
* **Session Memory:** The app remembers the last IP address you successfully entered so you don't have to type it again when switching between menu options.

## Requirements
* A C++ compiler (GCC, MSVC, etc.)
* **Windows OS:** This program uses Windows-specific `system()` calls (like `cls`, `ping -n`, and `nslookup`). If you run this on Linux or Mac, you'll need to modify the system commands in the source code.

## How to Run
1. Clone the repository.
2. Compile the `main.cpp` file using your preferred IDE (like Visual Studio) or via the command line:
   `g++ main.cpp -o nettool.exe`
3. Run the executable.

## What I Learned
Building this helped me figure out how to manage input buffers (`cin >> ws`), safely parse mixed data types using `stringstream`, and handle control flow in a continuous menu loop.

#Preview Image:

<img width="803" height="519" alt="image" src="https://github.com/user-attachments/assets/514ddb68-cbee-49fc-8ea2-811d0254047b" />
