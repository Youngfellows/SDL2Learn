if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("勃泥島?你從渤泥島出來的，那你應該知道袁承志吧，可不可以帶我去找他．", 116, 0);
    Talk("這種事不是大家都知道嗎?別騙我智慧果．", 0, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
