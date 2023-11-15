if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("婆婆姊姊，謝謝你救了莊家和雙兒，韋小寶磕頭。", 161, 0);
    Add3EventNum(-2, 0, 0, 1, -1)
exit();
