if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("雖然我一開始很討厭你，但我知道，我如果跟了你，你一定會對我很好很好．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
