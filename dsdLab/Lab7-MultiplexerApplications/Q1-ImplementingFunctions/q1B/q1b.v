module q1b(a,b,c,d,f);
    input a,b,c,d;
    output f;
    wire [3:0] t;
    wire [1:0] h;
    assign h = {a,b};
    assign t = {1'b0, 1'b0, d, ~d | c};
    MUX4to1 stage0(t,h,f);

endmodule

module MUX4to1(w,s,f);
    input [3:0] w;
    input [1:0] s;
    output f;
    reg f;

    always @(w or s)
    f = s[0] ? ( s[1] ? w[3] : w[1] ) : ( s[1] ? w[2] : w[0]);

endmodule
