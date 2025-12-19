# VSDSquadron_IP_Design

**Environment Used:**    

Github Codespaces

**RISC-V reference program simulation:**

<img width="1918" height="1023" alt="Image" src="https://github.com/user-attachments/assets/eb158e3e-1c7e-4a8e-a0f8-c309f5140d86" />

1. RISC-V program is located in the samples directory in the vsd-riscv2 repository.
2. Program is compiled using riscv64-unknown-elf-gcc into a risc-v elf binary, which is then loaded into simulated memory and executed by spike using proxy kernel.
   

**Generating firmware which is used to initialize instruction memory in the RTL**

<img width="1919" height="1026" alt="Image" src="https://github.com/user-attachments/assets/768418b9-5a7f-435d-90f5-87414c6612d5" />



4. RISC-V core access memory and memory-mapped IO's with the SoC address decoding address to route access to memory or peripherals.
5. New IP block is accessed as a memory-mapped peripheral instantiated in the SoC RTL and accessed by firmware via a defined address range.
