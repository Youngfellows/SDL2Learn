if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("臭小子，上次在揚州你們居然這樣修辱我，今日我就要報當日一箭之仇．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
