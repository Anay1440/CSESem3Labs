module MUX4to1(w,s,f);
    input [3:0] w;
    input [1:0] s;
    output f;
    wire [1:0] ft;

    MUX2to1 stage0(w[1:0],s[0],ft[0]);
    MUX2to1 stage1(w[3:2],s[0],ft[1]);
    MUX2to1 stage2(ft,s[1],f);

endmodule

module MUX2to1(w,s,f);
    input [1:0] w;
    input s;
    output f;
    reg f;

    always @(w or s)
    begin 
        f = w[1];
        if(s == 0)
            f = w[0];
    end
endmodule