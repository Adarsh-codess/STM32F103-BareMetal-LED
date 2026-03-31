# STM32F103 Bare-Metal LED Sequence

A low-level firmware implementation for the STM32F103 (ARM Cortex-M3) that controls a 4-LED sequence using direct register manipulation. This project bypasses high-level abstraction layers like HAL (Hardware Abstraction Layer) or LL (Low Layer) to demonstrate a deep understanding of the microcontroller's architecture.

## 🚀 Overview
The goal of this project is to interface with the STM32 hardware at the memory-mapped I/O level. By manually configuring the Reset and Clock Control (RCC) and GPIO registers, the firmware executes a precise lighting sequence across multiple ports.

## 🛠 Hardware Used
* **Microcontroller:** STM32F103RB Nucleo-64.
* **Architecture:** ARM Cortex-M3.
* **Peripherals:** GPIO Port A, GPIO Port B.

## 💻 Technical Implementation Details

### 1. Clock Configuration
Before any peripheral can be used, its clock must be enabled in the APB2 bus.
- **Register:** `RCC->APB2ENR`
- **Bits Set:** `IOPAEN` (Port A) and `IOPBEN` (Port B).

### 2. GPIO Configuration
The pins are configured as **General Purpose Output Push-Pull** with a **10MHz max speed**. 
- **Registers used:** `CRL` (for pins 0-7) and `CRH` (for pins 8-15).
- **Pin Mapping:**
  - **PA5, PA6:** Configured via `GPIOA->CRL`.
  - **PB2:** Configured via `GPIOB->CRL`.
  - **PB12:** Configured via `GPIOB->CRH`.

### 3. Logic Flow
The program uses a bitwise `XOR` operation on the Output Data Register (`ODR`) to toggle the state of the pins after clearing previous states. A manual `while` loop delay is implemented to create a visible sequence between transitions.

## 📂 Project Structure
* `main.c` : Contains the core logic, register configurations, and the super-loop.
* `stm32f1xx.h` : Device header providing register definitions and memory offsets.

## 🔧 How to Build
1. Clone the repository:
   ```bash
   git clone [https://github.com/Adarsh-codess/STM32F103-BareMetal-LED.git](https://github.com/Adarsh-codess/STM32F103-BareMetal-LED.git)
![20260331_121622 jpg](https://github.com/user-attachments/assets/23a4494b-334a-4377-8526-f09585d5d3db)
