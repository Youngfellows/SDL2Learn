if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("你是雙兒三少奶的師父，我該叫你婆婆，不過瞧你相貌，最多不過做得我姊姊，因此叫你婆婆姊姊。", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
