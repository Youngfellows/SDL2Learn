if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("你這臭小子，居然還懂得回來，這些年你跑到哪了，當初老娘跑到街上找你找了好久，還以為你被人口販子抓去，害我哭了好久．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
