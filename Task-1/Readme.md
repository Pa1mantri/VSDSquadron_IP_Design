
# FPGA-IP-DEVELOPMENT

## Task-1: Environment Setup & RISC-V Reference Bring-Up

This repository demonstrates the successful setup, verification, and usage of the **RISC-V toolchain**, simulators, and **VSDFPGA firmware build flow** within a **GitHub Codespace (Linux)** environment.

The objective of this task was to validate a known-good RISC-V reference flow, ensure toolchain readiness, and prepare for upcoming **RTL, IP, and FPGA integration tasks**.  
No FPGA hardware was required or used for this task.

---

## Environment Used

- **Platform**: GitHub Codespace  
- **Operating System**: Linux  
- **Primary Interface**: VS Code Terminal inside Codespace  
- **Secondary Interface**: noVNC graphical terminal (Codespace)  

All commands and builds were executed entirely inside the **Codespace environment**, as instructed.

## RISC-V Reference Program Execution

- **Repository**: `vsd-riscv2`  
- **Program Location**: `samples/`

This section demonstrates the successful verification of the **RISC-V toolchain** and **simulator** by compiling and running a reference C program inside the **GitHub Codespace** environment.

---

### Commands Used

```bash
riscv64-unknown-elf-gcc -o sum1ton.0 sum1ton.c
spike pk sum1ton.o
```
**RISC-V reference program simulation:**

<img width="1918" height="1023" alt="Image" src="https://github.com/user-attachments/assets/eb158e3e-1c7e-4a8e-a0f8-c309f5140d86" />


## VSDFPGA Firmware Build (No FPGA Hardware)

- **Repository**: `vsdfpga_labs`  
- **Lab**: `basicRISCV`  
- **Firmware Directory**: `basicRISCV/Firmware`

This section demonstrates a successful **firmware build** using the VSDFPGA flow, without requiring any FPGA hardware.

---

### Commands Used

```bash
git clone https://github.com/vsdip/vsdfpga_labs.git
cd vsdfpga_labs/basicRISCV/Firmware
make riscv_logo.bram.hex
```

### Result

The firmware build completed successfully and generated the following file:

```text
riscv_logo.bram.hex
```


**Generating firmware which is used to initialize instruction memory in the RTL**

<img width="1915" height="1030" alt="Image" src="https://github.com/user-attachments/assets/b48d8eb4-76d6-4934-9ae8-2e7961b17124" />

## VSDFPGA RISC-V Logo Execution Using Spike (Simulator-Based)

In addition to HEX generation, the VSDFPGA firmware source (`riscv_logo.c`) was compiled into an ELF and executed using the **Spike** simulator.

---

### Commands Used

```bash
riscv64-unknown-elf-gcc -o riscv_logo.o riscv_logo.c
spike pk riscv_logo.o
```

### Output Observed

```text
LEARN TO THINK LIKE A CHIP
VSDSQUADRON FPGA MINI
BRINGS RISC-V TO VSD CLASSROOM
```

The firmware runs in an infinite loop and repeatedly prints the ASCII logo.

<img width="1910" height="856" alt="Image" src="https://github.com/user-attachments/assets/6297023b-8a9c-4c09-9333-611c36a53a55" />


## Understanding Check

### 1. Where is the RISC-V program located?
The RISC-V program is located in the samples directory in the vsd-riscv2 repository.

### 2. How is the program compiled and loaded into memory?
Program is compiled using riscv64-unknown-elf-gcc into a risc-v elf binary, which is then loaded into simulated memory and executed by spike using proxy kernel.

### 3. How does the RISC-V core access memory and memory-mapped IO?
The RISC-V core accesses both RAM and peripherals using the same standard Load (lw) and Store (sw) instructions.
Access to specific peripherals is managed by the SoC's address decoding logic.

### 4. Where would a new FPGA IP block logically integrate?
New IP block is accessed as a memory-mapped peripheral instantiated in the SoC RTL and accessed by firmware via a defined address range.


