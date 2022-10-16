module q2b(w,f);
    input [2:0] w;
    output f;
    wire h,g;
    MUX2to1 stage0({w[0],1'b0},w[1],g);
    MUX2to1 stage1({1'b1,w[0]},w[1],h);
    MUX2to1 stage2({h,g},w[2],f);

endmodule

module MUX2to1(w,s,f);
    input [1:0] w;
    input s;
    output reg f;

    always @(w or s)
    begin 
        f = w[1];
        if(s == 0)
            f = w[0];
    end
endmodule