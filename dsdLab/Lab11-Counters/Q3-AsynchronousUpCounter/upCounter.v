module upCounter(clk,reset,Q);
    input clk,reset;
    output [3:0] Q;

    dFF ff1(~Q[0],clk,reset,Q[0]);
    dFF ff2(~Q[1],~Q[0],reset,Q[1]);
    dFF ff3(~Q[2],~Q[1],reset,Q[2]);
    dFF ff4(~Q[3],~Q[2],reset,Q[3]);

    /*
    jkFF ff1(1'b1,1'b1,clk,reset,Q[0]);
    jkFF ff2(1'b1,1'b1,Q[0],reset,Q[1]);
    jkFF ff3(1'b1,1'b1,Q[1],reset,Q[2]);
    jkFF ff4(1'b1,1'b1,Q[2],reset,Q[3]);
    */

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