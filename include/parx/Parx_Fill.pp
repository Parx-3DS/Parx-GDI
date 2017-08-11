
unit Parx_Fill;
interface

uses
  ctypes;

{
  Automatically converted by H2Pas 1.0.0 from Parx_Fill.h
  The following command line parameters were used:
    -C
    -d
    -e
    Parx_Fill.h
}

    Type
    Prect  = ^rect;
    Pu8  = ^u8;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  {forked --> https://github.com/linoma/fb43ds/blob/master/source/gfxDraw.c }
(* error 
	p[0] = (p[0] * sa + b * da) >> 8;\
in declaration at line 4 *)
(* error 
	p[0] = (p[0] * sa + b * da) >> 8;\
(* error 
	p[1] = (p[1] * sa + g * da) >> 8;\
in declaration at line 5 *)
(* error 
	p[1] = (p[1] * sa + g * da) >> 8;\
(* error 
	p[2] = (p[2] * sa + r * da) >> 8;
in declaration at line 6 *)

    procedure GradientFillRect(prc:Prect; radius:cint; mode:cint; s_col:u32; e_col:u32; 
                screen:Pu8);cdecl;external;

    procedure FillRoundRect(prc:Prect; radius:cint; b_col:u32; f_col:u32; screen:Pu8);cdecl;external;

    procedure RoundRectShadow(prc:Prect; radius:cint; col:u32; length:cint; screen:Pu8);cdecl;external;

    procedure FillRect(prc:Prect; col:u32; screen:Pu8);cdecl;external;

    procedure FloodFill(x0:cint; y0:cint; fillColor:u32; interiorColor:u32; screen:Pu8);cdecl;external;


implementation


end.
