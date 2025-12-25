
**Implementing GPIO IP as a memory mapped peripheral**

GPIO RTL: gpio_ip.v

```
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

GPIO module is instantiated inside the SoC module.

<img width="1371" height="495" alt="Image" src="https://github.com/user-attachments/assets/c5fc412a-ca07-4c98-a4a7-e3c622e74de7" />

Adding address offset that triggers gpio IP

<img width="1365" height="499" alt="Image" src="https://github.com/user-attachments/assets/bec59f1c-ace6-4679-97c9-74373a7c6448" />

**Simulation**

Simulation requires a stub module to mock the FPGA's internal primitives (PLL and Oscillator); this can be provided via a standalone ice40_primitives.v file or defined locally inside the testbench.
