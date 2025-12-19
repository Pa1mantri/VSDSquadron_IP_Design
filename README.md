# VSDSquadron_IP_Design
VSDSquadron FPGA – RISC-V &amp; IP Development

Environment Used:
Github Codespaces

1. RISC-V program is located in the samples directory in the vsd-riscv2 repository.
2. Program is compiled using riscv64-unknown-elf-gcc into a risc-v elf binary, which is then loaded into simulated memory and executed by spike using proxy kernel.
   Command used spike pk


3. RISC-V core access memory and memory-mapped IO's with the SoC address decoding address to route access to memory or peripherals.
4. New IP block is accessed as a memory-mapped peripheral instantiated in the SoC RTL and accessed by firmware via a defined address range.
