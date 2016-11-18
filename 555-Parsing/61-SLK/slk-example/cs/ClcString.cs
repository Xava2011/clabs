
// ClcString.cs - generated by the SLK parser generator 

class ClcString {

private static string[] Nonterminal_name ={"0"

,"expression"
,"additive_expression"
,"add_op"
,"multiplicitive_expression"
,"mul_op"
,"exponential_expression"
,"primary_expression"
,"add_op_multiplicitive_expression_*"
,"mul_op_exponential_expression_*"
,"^_exponential_expression_opt"
};

private static string[] Terminal_name ={"0"

,"+"
,"-"
,"*"
,"/"
,"^"
,"("
,")"
,"NUMBER"
,"END_OF_SLK_INPUT_"
};

private static string[] Action_name ={"0"

,"_action_Finish"
,"_action_Push"
,"_action_Add"
,"_action_Multiply"
,"_action_Exponent"
,"_action_Negate"
};

private static string[] Production_name ={"0"

,"expression --> additive_expression _action_Finish"
,"additive_expression --> multiplicitive_expression add_op_multiplicitive_expression_*"
,"add_op --> +"
,"add_op --> -"
,"multiplicitive_expression --> exponential_expression mul_op_exponential_expression_*"
,"mul_op --> *"
,"mul_op --> /"
,"exponential_expression --> primary_expression ^_exponential_expression_opt"
,"primary_expression --> ( additive_expression )"
,"primary_expression --> - primary_expression _action_Negate"
,"primary_expression --> NUMBER _action_Push"
,"add_op_multiplicitive_expression_* --> add_op _action_Push multiplicitive_expression _action_Add add_op_multiplicitive_expression_*"
,"add_op_multiplicitive_expression_* -->"
,"mul_op_exponential_expression_* --> mul_op _action_Push exponential_expression _action_Multiply mul_op_exponential_expression_*"
,"mul_op_exponential_expression_* -->"
,"^_exponential_expression_opt --> ^ exponential_expression _action_Exponent"
,"^_exponential_expression_opt -->"
};

private const short   START_SYMBOL = 2049;

public static string  GetSymbolName ( short symbol )
{
  if ( symbol >= START_SYMBOL ) {
      return ( Nonterminal_name [symbol - (START_SYMBOL-1)] );
  } else if ( symbol > 0 ) {
      return ( Terminal_name [ ClcParser.GetTerminalIndex ( symbol ) ] );
  } else {
      return ( Action_name [ -symbol ] );
  }
}

public static string  GetProductionName ( short production_number )
{
  return ( Production_name [production_number] );
}


};
