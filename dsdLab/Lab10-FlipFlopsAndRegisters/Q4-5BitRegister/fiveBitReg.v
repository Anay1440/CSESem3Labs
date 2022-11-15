module fiveBitReg(inp,clk,reset,o);
    input [4:0] inp;
    input clk,reset;
    output [4:0] o;

    dFF ff1(inp[4],clk,reset,o[4]);
    dFF ff2(inp[3],clk,reset,o[3]);
    dFF ff3(inp[2],clk,reset,o[2]);
    dFF ff4(inp[1],clk,reset,o[1]);
    dFF ff5(inp[0],clk,reset,o[0]);

endmodule

module dFF(d,clk,reset,q);
    input d,clk,reset;
    output reg q;

    always @(posedge clk)
        if (!reset)
            q <= d;

    always @(reset)
        if (reset)
            q <= 0;

endmodule