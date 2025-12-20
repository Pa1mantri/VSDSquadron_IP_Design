# VSDSquadron_IP_Design

**Environment Used:**    

Github Codespaces

**RISC-V reference program simulation:**

<img width="1918" height="1023" alt="Image" src="https://github.com/user-attachments/assets/eb158e3e-1c7e-4a8e-a0f8-c309f5140d86" />


**Generating firmware which is used to initialize instruction memory in the RTL**

<img width="1915" height="1030" alt="Image" src="https://github.com/user-attachments/assets/b48d8eb4-76d6-4934-9ae8-2e7961b17124" />

Since hardware is not yet available, the same program is cross compiled using riscv and run on spike to get the following output in the terminal

<img width="1908" height="852" alt="Image" src="https://github.com/user-attachments/assets/dbf657ec-a128-445c-bd8f-98fc1badb852" />

<img width="1910" height="856" alt="Image" src="https://github.com/user-attachments/assets/6297023b-8a9c-4c09-9333-611c36a53a55" />


1. RISC-V program is located in the samples directory in the vsd-riscv2 repository.
2. Program is compiled using riscv64-unknown-elf-gcc into a risc-v elf binary, which is then loaded into simulated memory and executed by spike using proxy kernel.
3. RISC-V core access memory and memory-mapped IO's with the SoC address decoding address to route access to memory or peripherals.
4. New IP block is accessed as a memory-mapped peripheral instantiated in the SoC RTL and accessed by firmware via a defined address range.
