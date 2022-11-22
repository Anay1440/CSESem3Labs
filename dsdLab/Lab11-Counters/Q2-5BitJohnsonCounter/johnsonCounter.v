module johnsonCounter(clk,reset,Q);
    input clk,reset;
    output [4:0] Q;
    dFF ff1(~Q[0],clk,reset,Q[4]);
    dFF ff2(Q[4],clk,reset,Q[3]);
    dFF ff3(Q[3],clk,reset,Q[2]);
    dFF ff4(Q[2],clk,reset,Q[1]);
    dFF ff5(Q[1],clk,reset,Q[0]);

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