if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("鄭公洨刀是我年輕時闖蕩江湖所用的寶刀．"武林寶刀 鄭公屠龍"，這句說的就是武林中有兩大寶刀，分別是屠龍刀和鄭公洨刀．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
