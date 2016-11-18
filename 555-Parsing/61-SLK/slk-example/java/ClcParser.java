
// ClcParser.java - generated by the SLK parser generator 

public class ClcParser {

private static short get_conditional_production ( short symbol ) { return (short) 0; }

private static short[] Parse = {

0,0,17,17,17,17,16,0,17,0,17,15,15,14,14,12,12,15,1
,15,0,13,1,13,1,2,5,3,4,2,5,2,5,8,10,6,7,8,9
,8,11
};

private static int[] Parse_row = {0

,16,23,26,24,32,31,32,14,10,1
,0};

private static short[] Conflict = {

0
};

private static int[] Conflict_row = {0


,0};

private static short[] Production = {0

,0,2049,-1,2050,0,2050,2056,2052,0,2051,43,0,2051,45,0,2052,2057,2054
,0,2053,42,0,2053,47,0,2054,2058,2055,0,2055,41,2050,40,0,2055,-6,2055,45
,0,2055,-2,257,0,2056,2056,-3,2052,-2,2051,0,2056,0,2057,2057,-4,2054,-2,2053
,0,2057,0,2058,-5,2054,94,0,2058
,0};

private static int[] Production_row = {0

,1,5,9,12,15,19,22,25,29,34,39,43,50,52,59,61
,66
,0};

private static short[] Terminal_to_index = {0

,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,6,7,3,1,0,2,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,8,9
};

private static final short   END_OF_SLK_INPUT_ = 258;
private static final short   START_SYMBOL = 2049;

public static short GetTerminalIndex ( short   token ){
 return ( Terminal_to_index [token] );
}

private static short
get_predicted_entry ( int        display,
                      ClcToken   tokens,
                      ClcLog     log,
                      short      production_number,
                      short      token,
                      int        scan_level,
                      int        depth )
{
 return  0;
}

public static void
parse ( int         display,
        ClcAction   action,
        ClcToken    tokens,
        ClcError    error,
        ClcLog      log,
        short       start_symbol )
{
 short     rhs, lhs;
 short     production_number, entry, symbol, token, new_token;
 int       top, index, level;
 short[]   stack = new short[512];

 top = 511;
 stack [ top ] = 0;
 if ( start_symbol == 0 ) {
     start_symbol = START_SYMBOL;
 }
 if ( top > 0 ) { stack [--top] = start_symbol;
 } else { log.trace ("ClcParse: stack overflow\n"); return; }
 token = tokens.get();
 new_token = token;
 if ( display != 0 ) {
     log.trace ( "\n\n\t\tPARSE DERIVATION\n\n" );
 }

 for ( symbol = (stack[top] != 0  ? stack[top++] : (short) 0);  symbol != 0; ) {

     if ( symbol >= START_SYMBOL ) {                  // nonterminal symbol

         entry = 0;
         level = 1;
         production_number = get_conditional_production ( symbol );
         if ( production_number != 0 ) {
             entry = get_predicted_entry ( display, tokens, log,
                                           production_number, token,
                                           level, 1 );
         }
         if ( entry == 0 ) {
             index = Parse_row [ symbol - (START_SYMBOL-1) ];
             index += Terminal_to_index [ token ];
             entry = Parse [ index ];
         }
         while ( entry < 0 ) {
             index = Conflict_row [-entry];
             index += Terminal_to_index [tokens.peek (level)];
             entry = Conflict [ index ];
             ++level;
         }
         if ( entry != 0 ) {
             index = Production_row [ entry ];
             lhs = Production [ ++index ];
             if ( lhs == symbol ) {                   // valid row for lhs
                 rhs = Production [++index];
                 for ( ;  rhs != 0;  rhs = Production [++index] ) {
                     if ( top > 0 ) { stack [--top] = rhs;
                     } else { log.trace ("ClcParse: stack overflow\n"); return; }
                 }
                 if ( display != 0 ) {
                     log.trace_production ( entry );
                 }
             } else {                                 // lhs does not match
                 new_token = error.no_entry ( symbol, token, level-1 );
             }
         } else {                                       // no table entry
             new_token = error.no_entry ( symbol, token, level-1 );
         }

     } else if ( symbol > 0 ) {                         // terminal symbol
         if ( symbol == token ) {
             token = tokens.get();
             new_token = token;
         } else {                                       // token mismatch
             new_token = error.mismatch ( symbol, token );
         }

     } else {                                           // action symbol
         if ( display != 0 ) {
             log.trace_action ( symbol );
         }
         action.execute ( -symbol );
     }

     if ( token != new_token ) {
         if ( new_token != 0 ) {
             token = new_token;
         }
         if ( token != END_OF_SLK_INPUT_ ) {
             continue;                                  // try this token
         }
     }

     symbol = (stack[top] != 0  ? stack[top++] : (short) 0);
 }

 if ( token != END_OF_SLK_INPUT_ ) {                    // input left over
     error.input_left ();
 }

}



};
