#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/outputs.h>

//  _____________________________       _____________________________
// /  0  |  1  |  2  |  3  |  4  \     /  5  |  6  |  7  |  8  |  9  \
// | 10  | 11  | 12  | 13  | 14  | ___ | 15  | 16  | 17  | 18  | 19  |
// \ 20  | 21  | 22  | 23  | 24  ||25 || 26  | 27  | 28  | 29  | 30 /
//         \   31    |    32     /     \    33     |   34    /
//          ---------------------       --------------------

#define APT 0
#define NUM 1
#define NAV 2
#define SYM 3
#define FUN 4
#define BLE 5

// &lt {
//     quick_tap_ms = <170>;
// };

&caps_word {
    continue-list = <UNDERSCORE MINUS BSPC LSHFT RSHFT>;
};

/ {
    macros {
        macro_sch: macro_sch {
            label = "Macro_SCH";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings = <&macro_tap &kp S &kp C &kp H>;
        macro_shifted_sch: macro_shifted_sch {
            label = "Macro_Sch";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings = <&macro_tap &kp LS(S) &kp C &kp H>;
        };
        };
    };
};


#define COMBO(NAME, BINDINGS, KEYPOS) \
combo_##NAME { \
    timeout-ms = <20>; \
    bindings = <BINDINGS>; \
    key-positions = <KEYPOS>; \
};

/ {
    combos {
        compatible = "zmk,combos";
/* usually on base layer */
        COMBO(q, &kp Q, 2 3)
        COMBO(z, &kp Z, 21 22)
        COMBO(v, &kp V, 1 2)
        COMBO(sch, &macro_sch, 1 3)
        COMBO(slash, &kp SLASH, 28 29)
        COMBO(dash, &kp MINUS, 27 28)
        COMBO(enter, &kp ENTER, 27 29)
        COMBO(esc, &kp ESC, 22 23)
/* parentheticals */
        COMBO(lbrc, &kp LBRC, 1 11)
        COMBO(lbkt, &kp LBKT, 2 12)
        COMBO(lpar, &kp LPAR, 3 13)
        COMBO(lt, &kp LT, 4 14)
        COMBO(gt, &kp GT, 5 15)
        COMBO(rpar, &kp RPAR, 6 16)
        COMBO(rbkt, &kp RBKT, 7 17)
        COMBO(rbrc, &kp RBRC, 8 18)
/* caps */
        COMBO(caps, &caps_word, 13 16)
        COMBO(capslock, &kp CAPSLOCK, 1 8)
/* deletion */
        COMBO(bspc, &kp BSPC, 6 7)
        COMBO(del, &kp DEL, 7 8)
        COMBO(delword, &kp LC(BSPC), 6 8)
/* alternative shifting */
//  _____________________________       _____________________________
// /  0  |  1  |  2  |  3  |  4  \     /  5  |  6  |  7  |  8  |  9  \
// | 10  | 11  | 12  | 13  | 14  | ___ | 15  | 16  | 17  | 18  | 19  |
// \ 20  | 21  | 22  | 23  | 24  ||25 || 26  | 27  | 28  | 29  | 30 /
//         \   31    |    32     /     \    33     |   34    /
//          ---------------------       --------------------
        COMBO(Sq, &kp LS(Q), 2 3 32)
        COMBO(Sz, &kp LS(Z), 21 22 32)
        COMBO(Sv, &kp LS(V), 1 2 32)
        COMBO(Ssch, &macro_shifted_sch, 0 2 32)
        COMBO(Sw, &kp LS(W), 1 32)
        COMBO(Sf, &kp LS(F), 2 32)
        COMBO(Sp, &kp LS(P), 3 32)
        COMBO(Sb, &kp LS(B), 4 32)
        COMBO(Sj, &kp LS(J), 5 33)
        COMBO(Sl, &kp LS(L), 6 33)
        COMBO(Su, &kp LS(U), 7 33)
        COMBO(Sy, &kp LS(Y), 8 33)
        COMBO(Sr, &kp LS(R), 10 32)
        COMBO(Ss, &kp LS(S), 11 32)
        COMBO(St, &kp LS(T), 12 32)
        COMBO(Sh, &kp LS(H), 13 32)
        COMBO(Sk, &kp LS(K), 14 32)
        COMBO(Sx, &kp LS(X), 15 33)
        COMBO(Sn, &kp LS(N), 16 33)
        COMBO(Sa, &kp LS(A), 17 33)
        COMBO(Si, &kp LS(I), 18 33)
        COMBO(So, &kp LS(O), 19 33)
        COMBO(Sc, &kp LS(C), 21 32)
        COMBO(Sg, &kp LS(G), 22 32)
        COMBO(Sd, &kp LS(D), 23 32)
        COMBO(Sm, &kp LS(M), 27 33)
        COMBO(Scomma, &kp SEMI, 28 33)
        COMBO(Sdot, &kp COLON, 29 33)
        COMBO(Se, &kp LS(E), 16 17 33)
    };
};


/ {

    behaviors {
        hl: homerow_mods_left {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods left";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <5 6 7 8 9 15 16 17 18 19 25 26 27 28 29 30 33 34>;
        };
        hr: homerow_mods_right {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods right";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <0 1 2 3 4 10 11 12 13 14 20 21 22 23 24 25 31 32>;
        };

        my_lt: my_layer_taps {
            compatible = "zmk,behavior-hold-tap";
            label = "my layer taps";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&mo &kp>, <&kp>;
            // non-thumb keys
            // hold-trigger-key-positions = <0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23>;
        };

        dotcol: dot_colon {
            compatible = "zmk,behavior-mod-morph";
            label = "DOT_COL";
            #binding-cells = <0>;
            bindings = <&kp DOT>, <&kp COLON>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
        comsem: comma_semicolon {
            compatible = "zmk,behavior-mod-morph";
            label = "COM_SEM";
            #binding-cells = <0>;
            bindings = <&kp COMMA>, <&kp SEMI>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
    };
};
