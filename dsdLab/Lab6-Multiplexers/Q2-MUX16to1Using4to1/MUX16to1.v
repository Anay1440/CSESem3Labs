module MUX16to1(w,s,f);
    input [15:0] w;
    input [3:0] s;
    output f;
    wire [3:0] ft;

    MUX4to1 stage0(w[3:0],s[1:0],ft[0]);
    MUX4to1 stage1(w[7:4],s[1:0],ft[1]);
    MUX4to1 stage2(w[11:8],s[1:0],ft[2]);
    MUX4to1 stage3(w[15:12],s[1:0],ft[3]);
    MUX4to1 stage4(ft,s[3:2],f);

endmodule

module MUX4to1(w,s,f);
    input [3:0] w;
    input [1:0] s;
    output f;
    reg f;

    always @(w or s)
    f = s[0] ? ( s[1] ? w[3] : w[2] ) : ( s[1] ? w[1] : w[0]);

endmodule