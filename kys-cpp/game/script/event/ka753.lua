if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("你這小滑頭好有趣，一張嘴油腔滑調，真會討人歡喜，可是小娃娃，你要下毒害人，可著實得好好的學學呢。", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
