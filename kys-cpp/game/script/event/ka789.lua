if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("你終於想通了，你的選擇是對的，跟著我保證你一輩子都快樂，兄弟，我要跟我老婆去消遙了，跟你在一起的時間過的很快樂，掰．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
