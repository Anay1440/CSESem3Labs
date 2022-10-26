module grayToBin(g,b);
    input [3:0] g;
    output [3:0] b;

    assign b[3] = g[3];
    MUX4to1 stage2({1'b0,1'b1,1'b1,1'b0},{g[2],b[3]},b[2]);
    MUX4to1 stage0({g[1],~g[1],~g[1],g[1]},{g[3],g[2]},b[1]);
    MUX4to1 stage1({1'b0,1'b1,1'b1,1'b0},{g[0],b[1]},b[0]);

endmodule

module MUX4to1(w,s,f);
    input [3:0] w;
    input [1:0] s;
    output f;
    reg f;

    always @(w or s)
    f = s[0] ? ( s[1] ? w[3] : w[2] ) : ( s[1] ? w[1] : w[0]);

endmodule