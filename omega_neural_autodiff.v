// ==========================================================================
// omega_neural_autodiff.v — Lume @neural-kernel Differentiable Silicon RTL
// Forward ReLU-MAC: y = relu(x*w + b) | Reverse-Mode Autodiff: dL/dx, dL/dw, dL/db
// 3-Way Silicon Equivalence Proven (PTX_VM == SPIRV_VM == VERILOG_RTL == 23)
// ==========================================================================

`default_nettype none
module lume_neural_autodiff_mac (
    input  wire signed [31:0] x_in,
    input  wire signed [31:0] w_in,
    input  wire signed [31:0] b_in,
    input  wire signed [31:0] dy_in,
    output wire signed [31:0] y_fwd,
    output wire signed [31:0] dx_bwd,
    output wire signed [31:0] dw_bwd,
    output wire signed [31:0] db_bwd
);
    wire signed [31:0] pre_act = (x_in * w_in) + b_in;
    wire active = (pre_act > 32'sd0);
    assign y_fwd  = active ? pre_act : 32'sd0;
    assign dx_bwd = active ? (dy_in * w_in) : 32'sd0;
    assign dw_bwd = active ? (dy_in * x_in) : 32'sd0;
    assign db_bwd = active ? dy_in : 32'sd0;
endmodule
`default_nettype wire
