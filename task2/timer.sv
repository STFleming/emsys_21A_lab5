// A memory-mapped hardware timer peripheral stub
//
// It uses the same memory-mapped interface signals as the example presented
// in Lecture 5.
//
// This video contains an overview of the interface: https://www.youtube.com/watch?v=gax3yg27doc&ab_channel=ShaneFleming

module timer (
    input logic clk,
    input logic rst,

	input logic [31:0]   addr_in, // The address for the memory mapped register
	input logic [31:0]   data_in, // incoming data 
	input logic          wr_in,   // the write signal 

	input logic          rd_in,   // the read signal
	output logic 	     rd_valid_out, // when this is high there is a valid read signal at the output
	output logic [31:0]  data_out // the output data
);
// -------------------------------

logic [31:0] reg1;
logic [31:0] reg2;

// write interface
always_ff @(posedge clk) begin

        if ((addr_in[31:16] == 16'hFFFF) & wr_in) begin
                case(addr_in[15:0])
                        16'h0000: reg1 <= data_in;
                        16'h0004: reg2 <= data_in;
                        default: begin

                        end
                endcase
        end

        if (rst) begin
                reg1 <= 32'd0;
                reg2 <= 32'd0;
        end

end


// read interface
always_ff @(posedge clk) begin
        rd_valid_out <= rd_in;

        if ((addr_in[31:16] == 16'hFFFF) & rd_in) begin
                case(addr_in[15:0])
                        16'h0000: data_out <= reg1;
                        16'h0004: data_out <= reg2;
                        default: begin

                        end
                endcase
        end

        if(rst) begin
                data_out <=32'd0;
                rd_valid_out <= 1'b0;
        end
end



endmodule
// ----- End of MMIO interfacing module -----
