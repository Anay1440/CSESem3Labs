module q1b(a,b,c,d,f);
    input a,b,c,d;
    output f;

    wire [1:0] h;
    assign h = {a,b};

    MUX4to1 stage0(h,c,d,f);

endmodule

module MUX4to1(s,c,d,f);
    input [1:0] s;
    input c,d;
    output f;
    reg f;
    wire t1;
    assign t1 = ~d | c;

    always @(s)

    case (s)
        0: f = t1;
        1: f = d;
        2: f = 0;
        3: f = 0;
    endcase

endmodule