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
endmodule
