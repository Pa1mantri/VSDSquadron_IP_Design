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