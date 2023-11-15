if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("可惜不久後我就要回渤泥島了，再晚回去師父又要罵我了，真想帶你這小孩跟我回去島上，這樣在島上就不會悶了．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
