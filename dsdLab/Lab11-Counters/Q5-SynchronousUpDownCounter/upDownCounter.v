module upDownCounter(up,down,clk,reset,Q);
    input up,down,clk,reset;
    output [3:0] Q;
    wire t0,t1,t2,t3,t4;
    jkFF ff1(1'b1,1'b1,clk,reset,Q[0]);
    assign t0 = (up & Q[0]) | (~up & ~Q[0]);
    jkFF ff2(t0,t0,clk,reset,Q[1]);
    assign t1 = (up & Q[1] & Q[0]) | (~up & ~Q[1] & ~Q[0]);
    jkFF ff3(t1,t1,clk,reset,Q[2]);
    assign t2 = (up & Q[2] & Q[1] & Q[0]) | (~up & Q[2] & ~Q[1] & ~Q[0]);
    jkFF ff4(t2,t2,clk,reset,Q[3]);

endmodule

module jkFF(j,k,clk,reset,q);
    input j,k,clk,reset;
    output reg q;

    always @(posedge clk)
    begin
        if (reset)
            q <= 0;
        else
        begin
            if (clk)
            begin
                if (!q)
                begin
                    if (j)
                        q <= 1;
                end
                else
                begin
                    if (k) 
                        q <= 0;
                end
            end
        end
    end

    always @(reset)
    begin 
        if (reset)
            q <= 0;
    end
endmodule