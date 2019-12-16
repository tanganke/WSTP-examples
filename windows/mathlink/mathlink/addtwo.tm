

:Begin:
:Function:       addtwo
:Pattern:        AddTwo[i_Integer, j_Integer]
:Arguments:      { i, j }
:ArgumentTypes:  { Integer, Integer }
:ReturnType:     Integer
:End:

:Evaluate: AddTwo::usage = "AddTwo[x, y] gives the sum of two machine integers x and y."


:Begin:
:Function: addList
:Pattern:  AddList[i_List,j_Integer,k_Integer]
:Arguments: {i,j,k}
:ArgumentTypes: {IntegerList,Integer,Integer}
:ReturnType: Integer
:End:
