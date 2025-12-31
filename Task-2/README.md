# GPIO IP Integration and Verification

## 1. Overview
In this task, I designed a simple **GPIO IP** (write-only with read-back capability), integrated it into an existing **RISC-V SoC**, and validated it through simulation using a **C firmware program**.

The IP allows the CPU to:
- Write values to a register (driving LEDs)
- Read the value back to verify correct operation

---

## 2. IP Design (RTL)
I created a new module named `gpio_ip` that implements a **32-bit register** with synchronous write and combinational read logic.

### File: `gpio_ip.v`

```verilog

module gpio_ip(
    input clk,
    input resetn,
    input sel,
    input [31:0] wdata,
    input wr_enable,
    output [31:0] rdata,
    output reg [31:0] gpio_out
);
always@(posedge clk) begin
if(!resetn)
gpio_out <= 32'h00000000;
else if (sel && wr_enable)
gpio_out <= wdata;
end

assign rdata = gpio_out;
endmodule

```

## 3. SoC Integration

I modified the top-level SoC module in `riscv.v` to include the new GPIO peripheral.

### Step A: Address Definition
A new bit index was defined for the GPIO in the one-hot addressing scheme.

```verilog
// Inside SOC module
localparam IO_GPIO_bit = 3; // Defines the specific bit for GPIO addressing
```
<img width="1365" height="499" alt="Image" src="https://github.com/user-attachments/assets/bec59f1c-ace6-4679-97c9-74373a7c6448" />

### Step B: Instantiation

The `gpio_ip` module was instantiated and connected to the processor bus signals.

```verilog
wire [31:0] gpio_out;
wire [31:0] gpio_rdata;

gpio_ip uut (
    .clk(clk),
    .resetn(resetn),
    .sel(isIO & mem_wordaddr[IO_GPIO_bit]), // Decoding Logic
    .wdata(mem_wdata),
    .wr_enable(mem_wstrb),
    .rdata(gpio_rdata),
    .gpio_out(gpio_out)
);
```

### Step C: Read Data Multiplexing

The IO read-data multiplexer was updated to return GPIO data when the CPU accesses the GPIO address.

```verilog
wire [31:0] IO_rdata = 
    mem_wordaddr[IO_UART_CNTL_bit] ? {22'b0, !uart_ready, 9'b0} :
    mem_wordaddr[IO_GPIO_bit]      ? gpio_rdata :
    32'b0;
```

<img width="1371" height="495" alt="Image" src="https://github.com/user-attachments/assets/c5fc412a-ca07-4c98-a4a7-e3c622e74de7" />

## 5. Simulation Results

The design was simulated using **iverilog**.  
The testbench executed the firmware, and UART output was captured using the `BENCH` define.

### Simulation Command

```bash
iverilog -D BENCH -o soc_sim riscv.v gpio_ip.v SOC_tb.v
./soc_sim
```
### Output Log

```text
VCD info: dumpfile tb_soc.vcd opened for output.
0 LEDS=xxxxx
656065000 LEDS=00000
Read: 5
```


